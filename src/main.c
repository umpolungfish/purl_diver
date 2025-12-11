/**
 * @file main.c
 * @brief Main entry point for modular PE shellcode extractor
 *
 * This is the modular version that uses separated functionality modules
 * for better maintainability, testing, and code organization.
 */

#include "../include/error_codes.h"
#include "../include/pe_parser.h"
#include "../include/section_analyzer.h"
#include "../include/output_formats.h"
#include "../include/hash_algorithms.h"
#include "../include/entropy.h"
#include "../include/import_export_analyzer.h"
#include "../include/options.h"
#include "../include/batch_processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * @brief Extract shellcode from a single PE file
 *
 * Core extraction logic that:
 * 1. Initializes PE context
 * 2. Finds executable sections
 * 3. Detects overlaps and calculates size
 * 4. Extracts shellcode
 * 5. Outputs in requested format
 *
 * @param input_path Path to input PE file
 * @param output_path Path to output file
 * @param output_path_can_be_null If true, non-binary formats can output to stdout
 * @return ExtractError code
 */
ExtractError extract_shellcode_internal(const char *input_path, const char *output_path) {
    PE_Context ctx;
    ExtractError err;

    // Initialize PE context
    err = initialize_pe_context(input_path, &ctx);
    if (err != EXTRACT_SUCCESS) {
        fprintf(stderr, "[-] Error: %s\n", error_string(err));
        return err;
    }

    // Find executable sections
    PIMAGE_SECTION_HEADER *valid_sections = NULL;
    size_t num_valid_sections = 0;

    err = find_executable_sections(&ctx, &valid_sections, &num_valid_sections);
    if (err != EXTRACT_SUCCESS) {
        cleanup_pe_context(&ctx);
        fprintf(stderr, "[-] Error: %s\n", error_string(err));
        return err;
    }

    if (num_valid_sections == 0) {
        fprintf(stdout, "[!] Warning: No executable sections found in '%s'.\n", input_path);
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return EXTRACT_SUCCESS;
    }

    if (g_options.verbose) {
        printf("[+] Found %zu executable sections in '%s':\n", num_valid_sections, input_path);
        for (size_t i = 0; i < num_valid_sections; i++) {
            char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
            safe_copy_section_name(valid_sections[i]->Name, section_name, sizeof(section_name));
            printf("  - Section '%s': %u bytes at offset 0x%X\n",
                   section_name, valid_sections[i]->SizeOfRawData,
                   valid_sections[i]->PointerToRawData);
        }
    }

    // Detect overlaps and calculate total size
    size_t total_shellcode_size = 0;
    err = detect_overlaps_and_calculate_size(valid_sections, num_valid_sections, &total_shellcode_size);
    if (err != EXTRACT_SUCCESS) {
        free(valid_sections);
        cleanup_pe_context(&ctx);
        fprintf(stderr, "[-] Error: %s\n", error_string(err));
        return err;
    }

    if (total_shellcode_size == 0) {
        fprintf(stdout, "[!] Warning: All executable sections were overlapping or empty in '%s'.\n", input_path);
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return EXTRACT_SUCCESS;
    }

    // Allocate output buffer
    unsigned char *output_buffer = (unsigned char *)malloc(total_shellcode_size);
    if (!output_buffer) {
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return ERR_MEMORY_ALLOCATION;
    }

    // Extract section data
    size_t current_pos = 0;
    DWORD last_section_end = 0;

    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = valid_sections[i];

        // Skip overlapping sections
        if (section->PointerToRawData < last_section_end) {
            continue;
        }

        // Copy section data
        memcpy(output_buffer + current_pos,
               ctx.buffer + section->PointerToRawData,
               section->SizeOfRawData);

        current_pos += section->SizeOfRawData;
        last_section_end = section->PointerToRawData + section->SizeOfRawData;
    }

    // Output in requested format
    if (g_options.output_format == OUTPUT_BINARY) {
        if (!output_path) {
            fprintf(stderr, "[-] Error: Output path required for binary format\n");
            free(output_buffer);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return ERR_INVALID_ARGUMENTS;
        }

        FILE *out_f = fopen(output_path, "wb");
        if (!out_f) {
            fprintf(stderr, "[-] Error: Failed to open output file '%s'\n", output_path);
            free(output_buffer);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return ERR_FILE_WRITE;
        }

        fwrite(output_buffer, 1, current_pos, out_f);
        fclose(out_f);

        if (g_options.verbose) {
            printf("[+] Success: Extracted %zu bytes from %zu sections to '%s'\n",
                   current_pos, num_valid_sections, output_path);
        }
    } else {
        // Non-binary formats output to stdout
        char base_filename[256] = "shellcode";

        // Extract base filename for C arrays if output path is provided
        if (output_path) {
            const char *p = strrchr(output_path, '/');
            if (!p) p = strrchr(output_path, '\\');
            if (p) p++; else p = output_path;

            strncpy(base_filename, p, sizeof(base_filename) - 1);
            base_filename[sizeof(base_filename) - 1] = '\0';

            // Remove extension
            char *ext = strrchr(base_filename, '.');
            if (ext) *ext = '\0';

            // Replace hyphens with underscores
            for (int i = 0; base_filename[i]; i++) {
                if (base_filename[i] == '-') base_filename[i] = '_';
            }
        }

        switch (g_options.output_format) {
            case OUTPUT_C_ARRAY:
                output_as_c_array(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_PYTHON:
                output_as_python(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_HEX_DUMP:
                output_as_hex_dump(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_JSON:
                output_as_json(output_buffer, current_pos, input_path,
                               valid_sections, num_valid_sections,
                               ctx.entry_point_rva, ctx.machine);
                break;
            default:
                fprintf(stderr, "[-] Error: Unknown output format\n");
                free(output_buffer);
                free(valid_sections);
                cleanup_pe_context(&ctx);
                return ERR_INVALID_ARGUMENTS;
        }

        if (g_options.verbose) {
            printf("[+] Success: Extracted %zu bytes from %zu sections\n",
                   current_pos, num_valid_sections);
        }
    }

    // Calculate hash if requested
    if (g_options.include_hash) {
        unsigned char hash[32];
        calculate_sha256(output_buffer, current_pos, hash);
        if (g_options.verbose) {
            print_hash(hash, 32, "sha256");
        }
    }

    // Calculate entropy if requested
    if (g_options.include_entropy) {
        double entropy = calculate_entropy(output_buffer, current_pos);
        if (g_options.verbose) {
            printf("[INFO] Entropy: %.4f bits/byte\n", entropy);
        }
    }

    // Analyze imports/exports if requested
    if (g_options.analyze_imports_exports) {
        if (g_options.verbose) {
            printf("\n");
            print_imports_exports_summary(ctx.buffer, ctx.machine, ctx.file_size);
        }
    }

    // Cleanup
    free(output_buffer);
    free(valid_sections);
    cleanup_pe_context(&ctx);

    return EXTRACT_SUCCESS;
}

/**
 * @brief Extract shellcode from PE file (public interface)
 *
 * Main extraction logic that calls the internal function with normal output path requirements
 *
 * @param input_path Path to input PE file
 * @param output_path Path to output file
 * @return ExtractError code
 */
ExtractError extract_shellcode(const char *input_path, const char *output_path) {
    return extract_shellcode_internal(input_path, output_path);
}

int main(int argc, char **argv) {
    const char *input_path = NULL;
    const char *output_path = NULL;

    // Initialize options
    init_options();

    // Parse command-line arguments
    int result = parse_arguments(argc, argv, &input_path, &output_path);
    if (result != 0) {
        free_section_filters();
        return (result == -1) ? 0 : 1;  // 0 for help/version, 1 for error
    }

    ExtractError err = EXTRACT_SUCCESS;

    if (g_options.batch_mode) {
        // Perform batch processing
        if (g_options.verbose) {
            printf("[+] Starting batch processing in directory: %s\n", g_options.batch_input_dir);
            printf("    Output directory: %s\n", g_options.batch_output_dir ? g_options.batch_output_dir : "current directory");
            printf("    File pattern: %s\n", g_options.batch_pattern ? g_options.batch_pattern : "default (*.exe,*.dll)");
            printf("    Recursive: %s\n", g_options.batch_recursive ? "YES" : "NO");
        }

        err = process_batch(g_options.batch_input_dir,
                           g_options.batch_output_dir,
                           g_options.batch_pattern,
                           g_options.batch_recursive,
                           g_options.batch_log_file);

        if (err == EXTRACT_SUCCESS) {
            BatchStats stats = get_batch_stats();
            printf("\n[+] Batch processing completed:\n");
            printf("    Total files processed: %d\n", stats.total_files_processed);
            printf("    Successful extractions: %d\n", stats.successful_extractions);
            printf("    Failed extractions: %d\n", stats.failed_extractions);
        } else {
            fprintf(stderr, "[-] Batch processing failed\n");
        }
    } else {
        // Perform single file extraction
        err = extract_shellcode(input_path, output_path);
    }

    // Cleanup
    free_section_filters();

    if (err != EXTRACT_SUCCESS) {
        fprintf(stderr, "[-] Operation failed: %s\n", error_string(err));
        return 1;
    }

    return 0;
}
