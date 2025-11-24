/**
 * @file utils.h
 * @brief Utility functions for batch processing and user interaction
 *
 * Provides helper functions for managing input file lists and interactive
 * section selection.
 */

#ifndef UTILS_H
#define UTILS_H

#include "pe_types.h"
#include <stddef.h>

/**
 * @brief Add a file path to the batch input list
 *
 * Dynamically expands the input file array and adds a new file path.
 * Used for batch processing multiple PE files.
 *
 * @param file_path Path to PE file to add to the batch list
 * @return 0 on success, 1 on failure (memory allocation error)
 */
int add_input_file(const char *file_path);

/**
 * @brief Interactive section selection interface
 *
 * Displays available executable sections and prompts user to select
 * which sections to extract. User can enter:
 * - "all" or "ALL" to select all sections
 * - Comma-separated section numbers (e.g., "1,3,5")
 *
 * Selected sections are automatically added to the include_sections filter.
 *
 * @param sections Array of section header pointers
 * @param num_sections Number of sections in array
 * @return 1 on success, 0 if no sections available, -1 on error
 */
int interactive_section_selection(PIMAGE_SECTION_HEADER *sections, size_t num_sections);

// Global variables for batch processing (defined in utils.c)
extern char **input_files;         // Array of input file paths
extern int num_input_files;        // Number of input files
extern size_t input_files_capacity;  // Capacity of input_files array

// Global filter variables (defined in section_analyzer.c)
extern char **include_sections;
extern char **exclude_sections;
extern size_t include_count;
extern size_t exclude_count;

#endif // UTILS_H
