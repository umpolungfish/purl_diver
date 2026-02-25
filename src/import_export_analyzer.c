/**
 * @file import_export_analyzer.c
 * @brief Implementation of import and export table analysis
 */

#include "../include/import_export_analyzer.h"
#include "../include/pe_parser.h"
#include <stdio.h>

/* -------------------------------------------------------------------------
 * Private helpers
 * ---------------------------------------------------------------------- */

/**
 * Flat lookup entry for O(n) RVA→offset resolution with better cache locality
 * than dereferencing through IMAGE_SECTION_HEADER pointers per call.
 */
typedef struct {
    DWORD rva_start;   /* section->VirtualAddress                   */
    DWORD rva_end;     /* VirtualAddress + Misc.VirtualSize         */
    DWORD raw_base;    /* PointerToRawData - VirtualAddress          */
} SectionCacheEntry;

/** Build a flat cache from the section table for repeated RVA lookups. */
static void build_section_cache(PIMAGE_SECTION_HEADER section_table,
                                WORD num_sections,
                                SectionCacheEntry *cache)
{
    for (WORD i = 0; i < num_sections; i++) {
        cache[i].rva_start = section_table[i].VirtualAddress;
        cache[i].rva_end   = section_table[i].VirtualAddress
                             + section_table[i].Misc.VirtualSize;
        /* Guard against underflow: PointerToRawData may be 0 for BSS etc. */
        cache[i].raw_base  = (section_table[i].PointerToRawData >= section_table[i].VirtualAddress)
                             ? section_table[i].PointerToRawData - section_table[i].VirtualAddress
                             : 0;
    }
}

/** Resolve an RVA using the pre-built cache. Returns 0 if not found. */
static DWORD cached_rva_to_offset(DWORD rva,
                                  const SectionCacheEntry *cache,
                                  WORD count,
                                  long file_size)
{
    if (rva == 0) return 0;
    for (WORD i = 0; i < count; i++) {
        if (rva >= cache[i].rva_start && rva < cache[i].rva_end) {
            DWORD offset = rva + cache[i].raw_base;
            if (offset < (DWORD)file_size) return offset;
        }
    }
    return 0;
}

/**
 * Compute section table pointer from buffer in one place.
 * Called once per public function; the result is passed to the internal helpers.
 */
static PIMAGE_SECTION_HEADER get_section_table(PIMAGE_NT_HEADERS32 nt_headers)
{
    WORD opt_size = nt_headers->FileHeader.SizeOfOptionalHeader;
    return (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers
                                   + sizeof(DWORD)
                                   + sizeof(IMAGE_FILE_HEADER)
                                   + opt_size);
}

/* -------------------------------------------------------------------------
 * Internal analysis helpers (accept pre-computed section info + cache)
 * ---------------------------------------------------------------------- */

static void analyze_imports_internal(unsigned char *buffer,
                                     DWORD import_dir_rva,
                                     const SectionCacheEntry *cache,
                                     WORD num_sections,
                                     WORD machine,
                                     long file_size)
{
    if (import_dir_rva == 0) {
        if (verbose) printf("[INFO] No import directory found.\n");
        return;
    }

    DWORD import_dir_offset = cached_rva_to_offset(import_dir_rva, cache, num_sections, file_size);
    if (import_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing import directory.\n");
        return;
    }

    PIMAGE_IMPORT_DESCRIPTOR import_desc =
        (PIMAGE_IMPORT_DESCRIPTOR)(buffer + import_dir_offset);

    printf("[IMPORTS ANALYSIS]\n");

    int import_count = 0;
    while (import_desc->Name != 0) {
        DWORD dll_name_offset = cached_rva_to_offset(import_desc->Name, cache, num_sections, file_size);

        if (dll_name_offset != 0) {
            const char *dll_name = (const char *)(buffer + dll_name_offset);
            printf("  Imported DLL: %s\n", dll_name);

            DWORD orig_thunk_rva = (import_desc->OriginalFirstThunk != 0)
                                   ? import_desc->OriginalFirstThunk
                                   : import_desc->FirstThunk;
            DWORD thunk_offset         = cached_rva_to_offset(import_desc->FirstThunk, cache, num_sections, file_size);
            DWORD original_thunk_offset = cached_rva_to_offset(orig_thunk_rva, cache, num_sections, file_size);

            if (thunk_offset != 0 && original_thunk_offset != 0) {
                if (machine == IMAGE_FILE_MACHINE_I386) {
                    PIMAGE_THUNK_DATA32 thunk =
                        (PIMAGE_THUNK_DATA32)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x80000000)) {
                            DWORD hint_name_offset = cached_rva_to_offset(
                                thunk->u1.AddressOfData, cache, num_sections, file_size);
                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name =
                                    (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %d\n", thunk->u1.Ordinal & 0x7FFFFFFF);
                        }
                        thunk++;
                    }
                } else {
                    PIMAGE_THUNK_DATA64 thunk =
                        (PIMAGE_THUNK_DATA64)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x8000000000000000ULL)) {
                            DWORD hint_name_offset = cached_rva_to_offset(
                                (DWORD)thunk->u1.AddressOfData, cache, num_sections, file_size);
                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name =
                                    (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %lld\n",
                                   thunk->u1.Ordinal & 0x7FFFFFFFFFFFFFFFLL);
                        }
                        thunk++;
                    }
                }
            }
        }

        import_desc++;
        import_count++;
    }

    printf("[END IMPORTS ANALYSIS - %d DLLs imported]\n\n", import_count);
}

static void analyze_exports_internal(unsigned char *buffer,
                                     DWORD export_dir_rva,
                                     const SectionCacheEntry *cache,
                                     WORD num_sections,
                                     long file_size)
{
    if (export_dir_rva == 0) {
        if (verbose) printf("[INFO] No export directory found.\n");
        return;
    }

    DWORD export_dir_offset = cached_rva_to_offset(export_dir_rva, cache, num_sections, file_size);
    if (export_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing export directory.\n");
        return;
    }

    PIMAGE_EXPORT_DIRECTORY export_dir =
        (PIMAGE_EXPORT_DIRECTORY)(buffer + export_dir_offset);

    DWORD name_offset = cached_rva_to_offset(export_dir->Name, cache, num_sections, file_size);
    const char *dll_name = (name_offset != 0)
                           ? (const char *)(buffer + name_offset)
                           : "Unknown";

    printf("[EXPORTS ANALYSIS - %s]\n", dll_name);
    printf("  Base Ordinal: %d\n", export_dir->Base);
    printf("  Number of Functions: %d\n", export_dir->NumberOfFunctions);
    printf("  Number of Names: %d\n", export_dir->NumberOfNames);

    if (export_dir->NumberOfNames > 0 && export_dir->AddressOfNames != 0) {
        DWORD name_array_offset = cached_rva_to_offset(
            export_dir->AddressOfNames, cache, num_sections, file_size);

        if (name_array_offset != 0) {
            DWORD *name_rvas = (DWORD *)(buffer + name_array_offset);
            for (DWORD i = 0; i < export_dir->NumberOfNames; i++) {
                DWORD func_name_offset = cached_rva_to_offset(
                    name_rvas[i], cache, num_sections, file_size);
                if (func_name_offset != 0) {
                    printf("    - Function: %s\n",
                           (const char *)(buffer + func_name_offset));
                }
            }
        }
    }

    printf("[END EXPORTS ANALYSIS]\n\n");
}

/* -------------------------------------------------------------------------
 * Public API
 * ---------------------------------------------------------------------- */

void analyze_imports(unsigned char *buffer, DWORD *rva_to_imports, DWORD *rva_to_names,
                     WORD machine, long file_size)
{
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    PIMAGE_NT_HEADERS32 nt_headers =
        (PIMAGE_NT_HEADERS32)(buffer + dos_header->e_lfanew);
    PIMAGE_SECTION_HEADER section_table = get_section_table(nt_headers);
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;

    /* Build the lookup cache once for this call */
    SectionCacheEntry cache[num_sections];
    build_section_cache(section_table, num_sections, cache);

    DWORD import_dir_rva = 0;
    if (rva_to_imports) {
        import_dir_rva = *rva_to_imports;
    }
    if (rva_to_names && verbose && *rva_to_names != 0) {
        printf("[INFO] Additional import names analysis available at RVA: 0x%08X\n",
               *rva_to_names);
    }

    if (import_dir_rva == 0) {
        if (machine == IMAGE_FILE_MACHINE_I386) {
            PIMAGE_OPTIONAL_HEADER32 opt =
                (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            import_dir_rva =
                opt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        } else {
            PIMAGE_NT_HEADERS64 nt64 = (PIMAGE_NT_HEADERS64)nt_headers;
            import_dir_rva =
                nt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        }
    }

    analyze_imports_internal(buffer, import_dir_rva, cache, num_sections, machine, file_size);
}

void analyze_exports(unsigned char *buffer, DWORD rva_to_exports, WORD machine, long file_size)
{
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    PIMAGE_NT_HEADERS32 nt_headers =
        (PIMAGE_NT_HEADERS32)(buffer + dos_header->e_lfanew);
    PIMAGE_SECTION_HEADER section_table = get_section_table(nt_headers);
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;

    SectionCacheEntry cache[num_sections];
    build_section_cache(section_table, num_sections, cache);

    if (rva_to_exports == 0) {
        if (machine == IMAGE_FILE_MACHINE_I386) {
            PIMAGE_OPTIONAL_HEADER32 opt =
                (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            rva_to_exports =
                opt->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        } else {
            PIMAGE_NT_HEADERS64 nt64 = (PIMAGE_NT_HEADERS64)nt_headers;
            rva_to_exports =
                nt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        }
    }

    analyze_exports_internal(buffer, rva_to_exports, cache, num_sections, file_size);
}

void print_imports_exports_summary(unsigned char *buffer, WORD machine, long file_size)
{
    /* Parse headers and build cache exactly once for both import and export analysis */
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    PIMAGE_NT_HEADERS32 nt_headers =
        (PIMAGE_NT_HEADERS32)(buffer + dos_header->e_lfanew);
    PIMAGE_SECTION_HEADER section_table = get_section_table(nt_headers);
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;

    SectionCacheEntry cache[num_sections];
    build_section_cache(section_table, num_sections, cache);

    DWORD import_rva = 0, export_rva = 0;
    if (machine == IMAGE_FILE_MACHINE_I386) {
        PIMAGE_OPTIONAL_HEADER32 opt =
            (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
        import_rva = opt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = opt->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } else {
        PIMAGE_NT_HEADERS64 nt64 = (PIMAGE_NT_HEADERS64)nt_headers;
        import_rva = nt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = nt64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    }

    if (import_rva != 0) {
        analyze_imports_internal(buffer, import_rva, cache, num_sections, machine, file_size);
    }
    if (export_rva != 0) {
        analyze_exports_internal(buffer, export_rva, cache, num_sections, file_size);
    }
    if (import_rva == 0 && export_rva == 0) {
        printf("[INFO] No import or export tables found in this PE file.\n");
    }
}
