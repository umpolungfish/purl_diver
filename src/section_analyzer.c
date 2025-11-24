/**
 * @file section_analyzer.c
 * @brief Implementation of section filtering and overlap detection
 */

#define _GNU_SOURCE  // For strdup
#include "../include/section_analyzer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Global filter configuration
int verbose = 0;
char **include_sections = NULL;
char **exclude_sections = NULL;
size_t include_count = 0;
size_t exclude_count = 0;
DWORD min_section_size = 0;

int is_section_included(PIMAGE_SECTION_HEADER section) {
    char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
    memcpy(section_name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
    section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';  // Ensure null termination

    // Check minimum section size filter
    if (min_section_size > 0 && section->SizeOfRawData < min_section_size) {
        if (verbose) {
            printf("[DEBUG] Skipping section '%s' - smaller than minimum size (%u < %u)\n",
                   section_name, section->SizeOfRawData, min_section_size);
        }
        return 0;
    }

    // If include sections are specified, only these are allowed
    if (include_sections && include_count > 0) {
        for (size_t i = 0; i < include_count; i++) {
            if (strcmp(section_name, include_sections[i]) == 0) {
                if (verbose) {
                    printf("[DEBUG] Including section '%s' (whitelist match)\n", section_name);
                }
                return 1;  // This section is explicitly included
            }
        }
        if (verbose) {
            printf("[DEBUG] Excluding section '%s' (not in include list)\n", section_name);
        }
        return 0;  // Not in the include list
    }

    // If exclude sections are specified, these are not allowed
    if (exclude_sections && exclude_count > 0) {
        for (size_t i = 0; i < exclude_count; i++) {
            if (strcmp(section_name, exclude_sections[i]) == 0) {
                if (verbose) {
                    printf("[DEBUG] Excluding section '%s' (blacklist match)\n", section_name);
                }
                return 0;  // This section is explicitly excluded
            }
        }
    }

    // Default: include the section if it passes other filters
    return 1;
}

ExtractError parse_section_name(const char *section_str, char ***section_names, size_t *count) {
    if (!section_str || !section_names || !count) {
        return ERR_INVALID_ARGUMENTS;
    }

    // Single pass: count commas to estimate count
    size_t estimated_count = 1;
    for (const char *p = section_str; *p; p++) {
        if (*p == ',') estimated_count++;
    }

    *section_names = (char **)malloc(estimated_count * sizeof(char *));
    if (!*section_names) {
        return ERR_MEMORY_ALLOCATION;
    }

    *count = 0;
    char *temp = strdup(section_str);
    if (!temp) {
        free(*section_names);
        return ERR_MEMORY_ALLOCATION;
    }

    char *token = strtok(temp, ",");
    while (token && *count < estimated_count) {
        // Skip leading/trailing whitespace
        while (*token == ' ') token++;
        char *end = token + strlen(token) - 1;
        while (end > token && *end == ' ') end--;
        *(end + 1) = '\0';

        (*section_names)[*count] = strdup(token);
        if (!(*section_names)[*count]) {
            // Cleanup on error
            for (size_t i = 0; i < *count; i++) {
                free((*section_names)[i]);
            }
            free(*section_names);
            free(temp);
            return ERR_MEMORY_ALLOCATION;
        }
        (*count)++;
        token = strtok(NULL, ",");
    }

    free(temp);
    return EXTRACT_SUCCESS;
}

void free_section_filters(void) {
    if (include_sections) {
        for (size_t i = 0; i < include_count; i++) {
            free(include_sections[i]);
        }
        free(include_sections);
        include_sections = NULL;
        include_count = 0;
    }

    if (exclude_sections) {
        for (size_t i = 0; i < exclude_count; i++) {
            free(exclude_sections[i]);
        }
        free(exclude_sections);
        exclude_sections = NULL;
        exclude_count = 0;
    }
}

ExtractError detect_overlaps_and_calculate_size(PIMAGE_SECTION_HEADER *valid_sections,
                                               size_t num_valid_sections,
                                               size_t *total_shellcode_size) {
    *total_shellcode_size = 0;
    DWORD last_section_end = 0;

    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = valid_sections[i];

        // Check for potential integer overflows in section bounds
        if (section->PointerToRawData > UINT32_MAX - section->SizeOfRawData) {
            fprintf(stderr, "[-] Error: Section extends beyond addressable space.\n");
            return ERR_INTEGER_OVERFLOW;
        }

        // Check for overlapping sections
        if (section->PointerToRawData < last_section_end) {
            fprintf(stdout, "[!] Warning: Skipping overlapping section '%.8s'.\n",
                    (char*)section->Name);
            continue;
        }

        // Integer overflow protection for size calculation
        if (section->SizeOfRawData > SIZE_MAX - *total_shellcode_size) {
            fprintf(stderr, "[-] Error: Size calculation would overflow.\n");
            return ERR_INTEGER_OVERFLOW;
        }

        *total_shellcode_size += section->SizeOfRawData;
        last_section_end = section->PointerToRawData + section->SizeOfRawData;
    }

    if (*total_shellcode_size == 0) {
        fprintf(stdout, "[!] Warning: All executable sections were overlapping or empty.\n");
    }

    return EXTRACT_SUCCESS;
}
