/**
 * @file pe_parser.c
 * @brief Implementation of PE file parsing and validation
 */

#include "../include/pe_parser.h"
#include <limits.h>

// External dependencies (filtering functions from section_analyzer)
extern int is_section_included(PIMAGE_SECTION_HEADER section);

ExtractError validate_pe_structure(FILE *f, unsigned char **buffer, long *file_size) {
    // Get file size
    fseek(f, 0, SEEK_END);
    *file_size = ftell(f);

    if (*file_size <= (long)sizeof(IMAGE_DOS_HEADER)) {
        fprintf(stderr, "[-] Error: Invalid or empty file.\n");
        fclose(f);
        return ERR_FILE_READ;
    }

    // File size limit check (500 MB)
    if (*file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "[-] Error: File too large (max %d MB).\n", MAX_FILE_SIZE / (1024*1024));
        fclose(f);
        return ERR_FILE_TOO_LARGE;
    }

    fseek(f, 0, SEEK_SET);

    // Allocate buffer for entire file
    *buffer = (unsigned char *)malloc(*file_size);
    if (!*buffer) {
        fprintf(stderr, "[-] Error: Memory allocation failed for file buffer.\n");
        fclose(f);
        return ERR_MEMORY_ALLOCATION;
    }

    // Read entire file into buffer
    if (fread(*buffer, 1, *file_size, f) != (size_t)*file_size) {
        fprintf(stderr, "[-] Error: Failed to read input file.\n");
        free(*buffer);
        fclose(f);
        return ERR_FILE_READ;
    }
    fclose(f);

    // Validate DOS header
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)*buffer;
    if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
        fprintf(stderr, "[-] Error: Not a valid PE file (Invalid DOS signature).\n");
        free(*buffer);
        return ERR_INVALID_DOS_SIGNATURE;
    }

    // Validate NT headers offset
    DWORD nt_headers_offset = dos_header->e_lfanew;
    if (nt_headers_offset + sizeof(IMAGE_NT_HEADERS32) > (size_t)*file_size) {
        fprintf(stderr, "[-] Error: Invalid NT headers offset.\n");
        free(*buffer);
        return ERR_INVALID_NT_HEADERS;
    }

    // Validate PE signature
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(*buffer + nt_headers_offset);
    if (nt_headers->Signature != IMAGE_NT_SIGNATURE) {
        fprintf(stderr, "[-] Error: Invalid PE signature.\n");
        free(*buffer);
        return ERR_INVALID_PE_SIGNATURE;
    }

    // Validate architecture (only x86 and x64 supported)
    WORD machine = nt_headers->FileHeader.Machine;
    if (machine != IMAGE_FILE_MACHINE_I386 && machine != IMAGE_FILE_MACHINE_AMD64) {
        fprintf(stderr, "[-] Error: Unsupported architecture (Machine: 0x%X).\n", machine);
        free(*buffer);
        return ERR_UNSUPPORTED_ARCHITECTURE;
    }

    return EXTRACT_SUCCESS;
}

ExtractError initialize_pe_context(const char *input_path, PE_Context *ctx) {
    // Initialize context to zero to ensure all fields are set
    memset(ctx, 0, sizeof(PE_Context));

    FILE *f = fopen(input_path, "rb");
    if (!f) {
        fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_path);
        return ERR_FILE_OPEN;
    }

    // Validate PE structure and load file into buffer
    ExtractError err = validate_pe_structure(f, &ctx->buffer, &ctx->file_size);
    if (err != EXTRACT_SUCCESS) {
        return err;  // validate_pe_structure already freed resources and printed errors
    }

    // Initialize PE headers from buffer
    ctx->dos_header = (PIMAGE_DOS_HEADER)ctx->buffer;
    DWORD nt_headers_offset = ctx->dos_header->e_lfanew;
    ctx->nt_headers = (PIMAGE_NT_HEADERS32)(ctx->buffer + nt_headers_offset);
    ctx->machine = ctx->nt_headers->FileHeader.Machine;

    // Calculate derived values
    WORD size_of_optional_header = ctx->nt_headers->FileHeader.SizeOfOptionalHeader;
    ctx->section_table = (PIMAGE_SECTION_HEADER)((BYTE *)ctx->nt_headers +
                            sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + size_of_optional_header);
    ctx->num_sections = ctx->nt_headers->FileHeader.NumberOfSections;

    // Validate section table is within file bounds
    if ((BYTE*)ctx->section_table + ctx->num_sections * sizeof(IMAGE_SECTION_HEADER) >
        ctx->buffer + ctx->file_size) {
        fprintf(stderr, "[-] Error: Section table is outside the file bounds.\n");
        free(ctx->buffer);
        ctx->buffer = NULL;
        return ERR_INVALID_SECTION_TABLE;
    }

    // Detect and report entry point
    if (ctx->machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
        PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&ctx->nt_headers->OptionalHeader;
        ctx->entry_point_rva = opt_header->AddressOfEntryPoint;
    } else {  // 64-bit
        PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)ctx->nt_headers;
        ctx->entry_point_rva = nt_headers64->OptionalHeader.AddressOfEntryPoint;
    }

    if (verbose) {
        printf("[INFO] Entry point RVA: 0x%X\n", ctx->entry_point_rva);
        printf("[INFO] Machine type: %s\n",
               ctx->machine == IMAGE_FILE_MACHINE_I386 ? "x86 (32-bit)" :
               ctx->machine == IMAGE_FILE_MACHINE_AMD64 ? "x64 (64-bit)" : "Unknown");
        printf("[INFO] Number of sections: %d\n", ctx->num_sections);
    }

    return EXTRACT_SUCCESS;
}

void cleanup_pe_context(PE_Context *ctx) {
    if (ctx) {
        if (ctx->buffer) {
            free(ctx->buffer);
            ctx->buffer = NULL;
        }
        if (ctx->output_buffer) {
            free(ctx->output_buffer);
            ctx->output_buffer = NULL;
        }
        // Reset all values to zero
        memset(ctx, 0, sizeof(PE_Context));
    }
}

ExtractError find_executable_sections(PE_Context *ctx,
                                     PIMAGE_SECTION_HEADER **valid_sections,
                                     size_t *num_valid_sections) {
    // Validate PE characteristics
    WORD characteristics = ctx->nt_headers->FileHeader.Characteristics;
    if (characteristics & IMAGE_FILE_DLL) {
        if (verbose) printf("[INFO] Input file is a DLL.\n");
    } else if (characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) {
        if (verbose) printf("[INFO] Input file is an executable.\n");
    }

    *valid_sections = (PIMAGE_SECTION_HEADER *)malloc(ctx->num_sections * sizeof(PIMAGE_SECTION_HEADER));
    if (!*valid_sections) {
        fprintf(stderr, "[-] Error: Memory allocation failed for section list.\n");
        return ERR_MEMORY_ALLOCATION;
    }

    *num_valid_sections = 0;
    for (WORD i = 0; i < ctx->num_sections; i++) {
        PIMAGE_SECTION_HEADER section = &ctx->section_table[i];

        // Check if section is executable (has CODE or EXECUTE characteristics)
        if (section->Characteristics & (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE)) {
            // Check for potential integer overflows in section bounds
            if (section->PointerToRawData > (DWORD)(ctx->file_size - section->SizeOfRawData)) {
                fprintf(stderr, "[-] Error: Section extends beyond file bounds.\n");
                free(*valid_sections);
                return ERR_SECTION_OUT_OF_BOUNDS;
            }

            // Only include sections with actual data
            if (section->PointerToRawData > 0 && section->SizeOfRawData > 0) {
                // Apply section filtering (include/exclude lists, size filters, etc.)
                if (is_section_included(section)) {
                    if (verbose) {
                        printf("[DEBUG] Processing section '%.8s': RVA=0x%X, Raw=0x%X, Size=0x%X\n",
                               (char*)section->Name, section->VirtualAddress,
                               section->PointerToRawData, section->SizeOfRawData);
                    }

                    // Check if entry point is in this section
                    if (ctx->entry_point_rva >= section->VirtualAddress &&
                        ctx->entry_point_rva < section->VirtualAddress + section->Misc.VirtualSize) {
                        if (verbose) {
                            printf("[INFO] Entry point is in section '%.8s'\n", (char*)section->Name);
                        }
                    }

                    (*valid_sections)[*num_valid_sections] = section;
                    (*num_valid_sections)++;
                }
            }
        }
    }

    return EXTRACT_SUCCESS;
}

void safe_copy_section_name(const BYTE *src, char *dst, size_t dst_size) {
    if (!src || !dst || dst_size < IMAGE_SIZEOF_SHORT_NAME + 1) {
        if (dst && dst_size > 0) dst[0] = '\0';
        return;
    }

    // Calculate actual length (section names may not be null-terminated)
    size_t len = 0;
    for (size_t i = 0; i < IMAGE_SIZEOF_SHORT_NAME && src[i] != '\0'; i++) {
        len++;
    }

    // Copy the name
    memcpy(dst, src, len);
    dst[len] = '\0';

    // Strip trailing spaces/nulls for cleaner display
    while (len > 0 && (dst[len-1] == ' ' || dst[len-1] == '\0')) {
        len--;
        dst[len] = '\0';
    }
}

int safe_add_size(size_t a, size_t b, size_t *result) {
    if (b > SIZE_MAX - a) {
        return 1; // Overflow would occur
    }
    *result = a + b;
    return 0; // Success
}

DWORD rva_to_file_offset(DWORD rva, PIMAGE_SECTION_HEADER section_table,
                         WORD num_sections, long file_size) {
    if (rva == 0) return 0;

    // Search through sections to find which one contains this RVA
    for (WORD i = 0; i < num_sections; i++) {
        PIMAGE_SECTION_HEADER section = &section_table[i];
        DWORD section_start = section->VirtualAddress;
        DWORD section_end = section_start + section->Misc.VirtualSize;

        if (rva >= section_start && rva < section_end) {
            // Calculate file offset from RVA
            DWORD offset = section->PointerToRawData + (rva - section->VirtualAddress);

            // Bounds check to ensure offset is within file
            if (offset < (DWORD)file_size) {
                return offset;
            }
        }
    }

    return 0;  // RVA not found in any section
}

int compare_sections(const void *a, const void *b) {
    PIMAGE_SECTION_HEADER s1 = *(PIMAGE_SECTION_HEADER*)a;
    PIMAGE_SECTION_HEADER s2 = *(PIMAGE_SECTION_HEADER*)b;

    if (s1->PointerToRawData > s2->PointerToRawData) return 1;
    if (s1->PointerToRawData < s2->PointerToRawData) return -1;
    return 0;
}
