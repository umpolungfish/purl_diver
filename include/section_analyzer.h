/**
 * @file section_analyzer.h
 * @brief Section filtering and overlap detection
 *
 * Provides functionality for filtering PE sections based on include/exclude
 * lists and detecting overlapping sections.
 */

#ifndef SECTION_ANALYZER_H
#define SECTION_ANALYZER_H

#include "pe_types.h"
#include "error_codes.h"
#include <stddef.h>

/**
 * @brief Check if a section should be included based on filters
 *
 * Applies include/exclude filters and size filters to determine if a
 * section should be processed.
 *
 * @param section Section header to check
 * @return 1 if section should be included, 0 otherwise
 */
int is_section_included(PIMAGE_SECTION_HEADER section);

/**
 * @brief Parse comma-separated section names
 *
 * Parses a string like ".text,.data,.rdata" into an array of section names.
 *
 * @param section_str Input string with comma-separated section names
 * @param section_names Output: array of section name strings
 * @param count Output: number of sections parsed
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 *
 * @note Caller must free each string in section_names and the array itself
 */
ExtractError parse_section_name(const char *section_str, char ***section_names, size_t *count);

/**
 * @brief Free section filter arrays
 *
 * Frees all memory allocated for include and exclude section filters.
 */
void free_section_filters(void);

/**
 * @brief Detect overlapping sections and calculate total size
 *
 * Sorts sections by raw data offset and detects overlaps. Calculates
 * the total size of non-overlapping executable sections.
 *
 * @param valid_sections Array of section pointers
 * @param num_valid_sections Number of sections in array
 * @param total_shellcode_size Output: total size of non-overlapping sections
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 */
ExtractError detect_overlaps_and_calculate_size(PIMAGE_SECTION_HEADER *valid_sections,
                                               size_t num_valid_sections,
                                               size_t *total_shellcode_size);

// Global filter configuration (set by command-line parsing)
extern int verbose;
extern char **include_sections;
extern char **exclude_sections;
extern size_t include_count;
extern size_t exclude_count;
extern DWORD min_section_size;

#endif // SECTION_ANALYZER_H
