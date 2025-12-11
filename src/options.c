/**
 * @file options.c
 * @brief Implementation of options parsing and management
 */

#include "../include/options.h"
#include "../include/section_analyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global options instance
ProgramOptions g_options;

void init_options(void) {
    memset(&g_options, 0, sizeof(ProgramOptions));
    g_options.output_format = OUTPUT_BINARY;
    g_options.show_progress = 0;
    g_options.include_hash = 0;
    g_options.include_entropy = 0;
    g_options.analyze_imports_exports = 0;
    g_options.verbose = 0;
    g_options.dry_run = 0;
    g_options.batch_mode = 0;
    g_options.interactive_mode = 0;
    g_options.batch_output_dir = NULL;
    g_options.batch_input_dir = NULL;
    g_options.batch_pattern = NULL;
    g_options.batch_recursive = 0;
    g_options.batch_log_file = NULL;
    g_options.min_section_size = 0;
}

void print_version(void) {
    printf("PE Shellcode Extractor v2.0 - Modular Edition\n");
    printf("Enterprise-grade tool for extracting executable sections from PE files\n");
    printf("Supports x86 (32-bit) and x64 (64-bit) PE files\n\n");
}

void print_usage(const char *program_name) {
    printf("Usage: %s [options] <input_pe_file> [output_file]\n", program_name);
    printf("   or: %s [options] --batch <input_dir> [batch_options]\n\n", program_name);
    printf("General Options:\n");
    printf("  -v, --verbose          Enable verbose output\n");
    printf("  -h, --hash             Calculate and display SHA256 hash\n");
    printf("  -e, --entropy          Calculate and display entropy\n");
    printf("  -i, --imports-exports  Analyze import/export tables\n");
    printf("  -f, --format <type>    Output format: binary, c, python, hex, json\n");
    printf("  --help                 Show this help message\n");
    printf("  --version              Show version information\n\n");
    printf("Batch Processing Options:\n");
    printf("  --batch <dir>          Process all PE files in directory\n");
    printf("  --batch-output-dir <dir>  Directory for batch output files (default: current)\n");
    printf("  --batch-pattern <pat>  File pattern to match (default: \"*.exe,*.dll\")\n");
    printf("  --batch-recursive      Process subdirectories recursively\n");
    printf("  --batch-log <file>     Log batch processing results to file\n");
    printf("  --batch-format <fmt>   Output format for batch processing (default: binary)\n\n");
    printf("Filtering Options:\n");
    printf("  --include <sections>   Only extract specified sections (comma-separated)\n");
    printf("  --exclude <sections>   Exclude specified sections (comma-separated)\n");
    printf("  --min-size <bytes>     Minimum section size to extract\n\n");
    printf("Examples:\n");
    printf("  %s malware.exe shellcode.bin\n", program_name);
    printf("  %s -v --hash malware.exe shellcode.bin\n", program_name);
    printf("  %s -f c malware.exe\n", program_name);
    printf("  %s --include .text,.data malware.exe output.bin\n", program_name);
    printf("  %s --batch ./samples --batch-output-dir ./output --batch-format c\n", program_name);
    printf("  %s --batch ./malware --batch-recursive --batch-pattern \"*.exe,*.dll\"\n\n", program_name);
}

int parse_arguments(int argc, char **argv, const char **input_path, const char **output_path) {
    if (argc < 2) {
        print_usage(argv[0]);
        return -1;
    }

    int file_args = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-help") == 0) {
            print_usage(argv[0]);
            return -1;
        } else if (strcmp(argv[i], "--version") == 0) {
            print_version();
            return -1;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            g_options.verbose = 1;
            verbose = 1;  // Set global verbose flag
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--hash") == 0) {
            g_options.include_hash = 1;
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--entropy") == 0) {
            g_options.include_entropy = 1;
        } else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--imports-exports") == 0) {
            g_options.analyze_imports_exports = 1;
        } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--format") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --format requires an argument\n");
                return 1;
            }
            i++;
            if (strcmp(argv[i], "binary") == 0) {
                g_options.output_format = OUTPUT_BINARY;
            } else if (strcmp(argv[i], "c") == 0 || strcmp(argv[i], "c-array") == 0) {
                g_options.output_format = OUTPUT_C_ARRAY;
            } else if (strcmp(argv[i], "python") == 0) {
                g_options.output_format = OUTPUT_PYTHON;
            } else if (strcmp(argv[i], "hex") == 0 || strcmp(argv[i], "hex-dump") == 0) {
                g_options.output_format = OUTPUT_HEX_DUMP;
            } else if (strcmp(argv[i], "json") == 0) {
                g_options.output_format = OUTPUT_JSON;
            } else {
                fprintf(stderr, "[-] Error: Unknown format '%s'\n", argv[i]);
                return 1;
            }
        } else if (strcmp(argv[i], "--batch") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --batch requires a directory argument\n");
                return 1;
            }
            i++;
            g_options.batch_mode = 1;
            g_options.batch_input_dir = argv[i];
        } else if (strcmp(argv[i], "--batch-output-dir") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --batch-output-dir requires a directory argument\n");
                return 1;
            }
            i++;
            g_options.batch_output_dir = argv[i];
        } else if (strcmp(argv[i], "--batch-pattern") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --batch-pattern requires a pattern argument\n");
                return 1;
            }
            i++;
            g_options.batch_pattern = argv[i];
        } else if (strcmp(argv[i], "--batch-recursive") == 0) {
            g_options.batch_recursive = 1;
        } else if (strcmp(argv[i], "--batch-log") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --batch-log requires a file argument\n");
                return 1;
            }
            i++;
            g_options.batch_log_file = argv[i];
        } else if (strcmp(argv[i], "--batch-format") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --batch-format requires a format argument\n");
                return 1;
            }
            i++;
            if (strcmp(argv[i], "binary") == 0) {
                g_options.output_format = OUTPUT_BINARY;
            } else if (strcmp(argv[i], "c") == 0 || strcmp(argv[i], "c-array") == 0) {
                g_options.output_format = OUTPUT_C_ARRAY;
            } else if (strcmp(argv[i], "python") == 0) {
                g_options.output_format = OUTPUT_PYTHON;
            } else if (strcmp(argv[i], "hex") == 0 || strcmp(argv[i], "hex-dump") == 0) {
                g_options.output_format = OUTPUT_HEX_DUMP;
            } else if (strcmp(argv[i], "json") == 0) {
                g_options.output_format = OUTPUT_JSON;
            } else {
                fprintf(stderr, "[-] Error: Unknown batch format '%s'\n", argv[i]);
                return 1;
            }
        } else if (strcmp(argv[i], "--include") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --include requires an argument\n");
                return 1;
            }
            i++;
            if (parse_section_name(argv[i], &include_sections, &include_count) != EXTRACT_SUCCESS) {
                fprintf(stderr, "[-] Error: Failed to parse include sections\n");
                return 1;
            }
        } else if (strcmp(argv[i], "--exclude") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --exclude requires an argument\n");
                return 1;
            }
            i++;
            if (parse_section_name(argv[i], &exclude_sections, &exclude_count) != EXTRACT_SUCCESS) {
                fprintf(stderr, "[-] Error: Failed to parse exclude sections\n");
                return 1;
            }
        } else if (strcmp(argv[i], "--min-size") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[-] Error: --min-size requires an argument\n");
                return 1;
            }
            i++;
            g_options.min_section_size = (DWORD)atoi(argv[i]);
            min_section_size = g_options.min_section_size;
        } else if (argv[i][0] != '-' && !g_options.batch_mode) {
            // File argument (only for non-batch mode)
            if (file_args == 0) {
                *input_path = argv[i];
                file_args++;
            } else if (file_args == 1) {
                *output_path = argv[i];
                file_args++;
            } else {
                fprintf(stderr, "[-] Error: Too many file arguments\n");
                return 1;
            }
        } else if (argv[i][0] != '-' && g_options.batch_mode) {
            fprintf(stderr, "[-] Error: Can't specify input file when in batch mode\n");
            return 1;
        } else {
            fprintf(stderr, "[-] Error: Unknown option '%s'\n", argv[i]);
            return 1;
        }
    }

    // Validate arguments
    if (!g_options.batch_mode) {
        if (file_args == 0) {
            fprintf(stderr, "[-] Error: No input file specified\n");
            return 1;
        }

        // For non-binary formats, output file is optional (stdout)
        if (g_options.output_format == OUTPUT_BINARY && file_args < 2) {
            fprintf(stderr, "[-] Error: Binary format requires both input and output files\n");
            return 1;
        }

        // Set default output path for non-binary formats
        if (file_args == 1 && g_options.output_format != OUTPUT_BINARY) {
            *output_path = "stdout";
        }
    } else {
        // Batch mode specific validation
        if (!g_options.batch_input_dir) {
            fprintf(stderr, "[-] Error: Batch mode requires --batch input directory\n");
            return 1;
        }
    }

    return 0;
}
