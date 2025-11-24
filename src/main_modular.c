/**
 * @file main_modular.c
 * @brief Modular version of PE shellcode extractor (demonstration)
 *
 * This is a simplified modular implementation to demonstrate the
 * new module structure. The full monolithic version remains in
 * extract_shellcode.c during the transition period.
 */

#define _GNU_SOURCE  // For strdup
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/error_codes.h"
#include "../include/pe_parser.h"

// Global verbose flag
int verbose = 0;

// Stub for section filtering (will be in section_analyzer module)
int is_section_included(PIMAGE_SECTION_HEADER section) {
    // For now, include all sections
    (void)section;
    return 1;
}

void print_usage(const char *program_name) {
    printf("PE Shellcode Extractor (Modular Version - Demo)\n\n");
    printf("Usage: %s [options] <input_pe_file>\n\n", program_name);
    printf("Options:\n");
    printf("  -v, --verbose          Enable verbose output\n");
    printf("  -h, --help             Display this help message\n\n");
    printf("This is a demonstration of the modular architecture.\n");
}

int main(int argc, char *argv[]) {
    const char *input_path = NULL;

    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (argv[i][0] != '-') {
            input_path = argv[i];
        }
    }

    if (!input_path) {
        fprintf(stderr, "Error: No input file specified\n\n");
        print_usage(argv[0]);
        return 1;
    }

    printf("[*] Analyzing PE file: %s\n", input_path);

    // Initialize PE context
    PE_Context ctx;
    memset(&ctx, 0, sizeof(PE_Context));

    ExtractError err = initialize_pe_context(input_path, &ctx);
    if (err != EXTRACT_SUCCESS) {
        fprintf(stderr, "[-] Failed to initialize PE context: %s\n", error_string(err));
        return err;
    }

    printf("[+] PE file loaded successfully\n");
    printf("[+] Architecture: %s\n",
           ctx.machine == IMAGE_FILE_MACHINE_I386 ? "x86 (32-bit)" : "x64 (64-bit)");
    printf("[+] File size: %ld bytes\n", ctx.file_size);
    printf("[+] Number of sections: %d\n", ctx.num_sections);
    printf("[+] Entry point RVA: 0x%X\n", ctx.entry_point_rva);

    // Find executable sections
    PIMAGE_SECTION_HEADER *valid_sections = NULL;
    size_t num_valid_sections = 0;

    err = find_executable_sections(&ctx, &valid_sections, &num_valid_sections);
    if (err != EXTRACT_SUCCESS) {
        fprintf(stderr, "[-] Failed to find executable sections: %s\n", error_string(err));
        cleanup_pe_context(&ctx);
        return err;
    }

    printf("[+] Found %zu executable sections:\n", num_valid_sections);
    for (size_t i = 0; i < num_valid_sections; i++) {
        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
        safe_copy_section_name(valid_sections[i]->Name, section_name, sizeof(section_name));

        printf("    [%zu] %-8s  RVA: 0x%08X  Size: %u bytes  Characteristics: 0x%08X\n",
               i, section_name,
               valid_sections[i]->VirtualAddress,
               valid_sections[i]->SizeOfRawData,
               valid_sections[i]->Characteristics);
    }

    // Cleanup
    free(valid_sections);
    cleanup_pe_context(&ctx);

    printf("[+] Analysis complete\n");
    return 0;
}
