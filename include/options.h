/**
 * @file options.h
 * @brief Global configuration and command-line options
 *
 * Centralized storage for all command-line options and global configuration.
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "pe_types.h"

// Output format enumeration
typedef enum {
    OUTPUT_BINARY,   // Default: raw binary
    OUTPUT_C_ARRAY,  // C array format
    OUTPUT_PYTHON,   // Python byte string
    OUTPUT_HEX_DUMP, // Hex dump format
    OUTPUT_JSON      // JSON format with metadata
} OutputFormat;

// Global configuration structure
typedef struct {
    // Output options
    OutputFormat output_format;
    int show_progress;
    int include_hash;
    int include_entropy;

    // Analysis options
    int analyze_imports_exports;
    int analyze_imports_only;
    int analyze_exports_only;
    int verbose;

    // Processing options
    int dry_run;
    int batch_mode;
    int interactive_mode;

    // Batch processing
    char *batch_output_dir;

    // Section filtering (managed by section_analyzer module)
    DWORD min_section_size;
} ProgramOptions;

// Global options instance (defined in options.c)
extern ProgramOptions g_options;

/**
 * @brief Initialize options to default values
 */
void init_options(void);

/**
 * @brief Parse command-line arguments
 *
 * @param argc Argument count from main()
 * @param argv Argument vector from main()
 * @param input_path Output: pointer to input file path
 * @param output_path Output: pointer to output file path
 * @return 0 on success, -1 for help/version, 1 on error
 */
int parse_arguments(int argc, char **argv, const char **input_path, const char **output_path);

/**
 * @brief Print usage information
 */
void print_usage(const char *program_name);

/**
 * @brief Print version information
 */
void print_version(void);

#endif // OPTIONS_H
