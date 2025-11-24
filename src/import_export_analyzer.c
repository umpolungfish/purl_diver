/**
 * @file import_export_analyzer.c
 * @brief Implementation of import and export table analysis
 */

#include "../include/import_export_analyzer.h"
#include "../include/pe_parser.h"
#include <stdio.h>

void analyze_imports(unsigned char *buffer, DWORD *rva_to_imports, DWORD *rva_to_names,
                     WORD machine, long file_size) {
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);

    DWORD import_dir_rva = 0;
    DWORD import_names_rva = 0;

    if (rva_to_imports) import_dir_rva = *rva_to_imports;
    if (rva_to_names) {
        import_names_rva = *rva_to_names;
        // Use the import_names_rva value if additional analysis is available
        if (verbose && import_names_rva != 0) {
            printf("[INFO] Additional import names analysis available at RVA: 0x%08X\n", import_names_rva);
        }
    }

    if (import_dir_rva == 0) {
        // Get import directory from data directories if not provided
        if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
            PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            import_dir_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        } else {  // 64-bit
            PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
            import_dir_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        }
    }

    if (import_dir_rva == 0) {
        if (verbose) printf("[INFO] No import directory found.\n");
        return;
    }

    // Convert RVA to file offset using helper function
    PIMAGE_SECTION_HEADER section_table;
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;
    WORD size_of_optional_header = nt_headers->FileHeader.SizeOfOptionalHeader;

    section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + size_of_optional_header);

    DWORD import_dir_offset = rva_to_file_offset(import_dir_rva, section_table, num_sections, file_size);

    if (import_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing import directory.\n");
        return;
    }

    PIMAGE_IMPORT_DESCRIPTOR import_desc = (PIMAGE_IMPORT_DESCRIPTOR)(buffer + import_dir_offset);

    printf("[IMPORTS ANALYSIS]\n");

    // Process each import descriptor
    int import_count = 0;
    while (import_desc->Name != 0) {
        // Convert DLL name RVA to file offset using helper function
        DWORD dll_name_offset = rva_to_file_offset(import_desc->Name, section_table, num_sections, file_size);

        if (dll_name_offset != 0) {
            const char *dll_name = (const char *)(buffer + dll_name_offset);
            printf("  Imported DLL: %s\n", dll_name);

            // Process imported functions from this DLL
            // Convert thunk RVAs to file offsets using helper function
            DWORD thunk_offset = rva_to_file_offset(import_desc->FirstThunk, section_table, num_sections, file_size);

            DWORD orig_thunk_rva = (import_desc->OriginalFirstThunk != 0) ?
                                   import_desc->OriginalFirstThunk : import_desc->FirstThunk;
            DWORD original_thunk_offset = rva_to_file_offset(orig_thunk_rva, section_table, num_sections, file_size);

            if (thunk_offset != 0 && original_thunk_offset != 0) {
                if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
                    PIMAGE_THUNK_DATA32 thunk = (PIMAGE_THUNK_DATA32)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x80000000)) {  // Not an ordinal import
                            DWORD hint_name_offset = rva_to_file_offset(thunk->u1.AddressOfData, section_table, num_sections, file_size);

                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name = (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %d\n", thunk->u1.Ordinal & 0x7FFFFFFF);
                        }
                        thunk++;
                    }
                } else {  // 64-bit
                    PIMAGE_THUNK_DATA64 thunk = (PIMAGE_THUNK_DATA64)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x8000000000000000ULL)) {  // Not an ordinal import
                            DWORD hint_name_offset = rva_to_file_offset((DWORD)thunk->u1.AddressOfData, section_table, num_sections, file_size);

                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name = (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %lld\n", thunk->u1.Ordinal & 0x7FFFFFFFFFFFFFFFLL);
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

void analyze_exports(unsigned char *buffer, DWORD rva_to_exports, WORD machine, long file_size) {
    // Define DOS header at the beginning for access throughout
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;

    if (rva_to_exports == 0) {
        // Get export directory from data directories if not provided
        DWORD nt_headers_offset = dos_header->e_lfanew;
        PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);

        if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
            PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            rva_to_exports = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        } else {  // 64-bit
            PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
            rva_to_exports = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        }
    }

    if (rva_to_exports == 0) {
        if (verbose) printf("[INFO] No export directory found.\n");
        return;
    }

    // Convert RVA to file offset using helper function
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
    PIMAGE_SECTION_HEADER section_table;
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;
    WORD size_of_optional_header = nt_headers->FileHeader.SizeOfOptionalHeader;

    section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + size_of_optional_header);

    DWORD export_dir_offset = rva_to_file_offset(rva_to_exports, section_table, num_sections, file_size);

    if (export_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing export directory.\n");
        return;
    }

    PIMAGE_EXPORT_DIRECTORY export_dir = (PIMAGE_EXPORT_DIRECTORY)(buffer + export_dir_offset);

    // Get the name of the DLL (export name)
    DWORD name_offset = rva_to_file_offset(export_dir->Name, section_table, num_sections, file_size);

    const char *dll_name = "Unknown";
    if (name_offset != 0) {
        dll_name = (const char *)(buffer + name_offset);
    }

    printf("[EXPORTS ANALYSIS - %s]\n", dll_name);
    printf("  Base Ordinal: %d\n", export_dir->Base);
    printf("  Number of Functions: %d\n", export_dir->NumberOfFunctions);
    printf("  Number of Names: %d\n", export_dir->NumberOfNames);

    // Print function names if available
    if (export_dir->NumberOfNames > 0 && export_dir->AddressOfNames != 0) {
        // Convert AddressOfNames RVA to file offset using helper function
        DWORD name_array_offset = rva_to_file_offset(export_dir->AddressOfNames, section_table, num_sections, file_size);

        if (name_array_offset != 0) {
            DWORD *name_rvas = (DWORD *)(buffer + name_array_offset);

            for (DWORD i = 0; i < export_dir->NumberOfNames; i++) {
                DWORD name_rva = name_rvas[i];

                // Convert function name RVA to file offset using helper function
                DWORD func_name_offset = rva_to_file_offset(name_rva, section_table, num_sections, file_size);

                if (func_name_offset != 0) {
                    const char *func_name = (const char *)(buffer + func_name_offset);
                    printf("    - Function: %s\n", func_name);
                }
            }
        }
    }

    printf("[END EXPORTS ANALYSIS]\n\n");
}

void print_imports_exports_summary(unsigned char *buffer, WORD machine, long file_size) {
    // Get import/export directory RVAs
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);

    DWORD import_rva = 0, export_rva = 0;

    if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
        PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
        import_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } else {  // 64-bit
        PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
        import_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    }

    if (import_rva != 0) {
        analyze_imports(buffer, &import_rva, NULL, machine, file_size);
    }

    if (export_rva != 0) {
        analyze_exports(buffer, export_rva, machine, file_size);
    }

    if (import_rva == 0 && export_rva == 0) {
        printf("[INFO] No import or export tables found in this PE file.\n");
    }
}
