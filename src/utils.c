/**
 * @file utils.c
 * @brief Implementation of utility functions
 */

#define _GNU_SOURCE  // For strdup
#include "../include/utils.h"
#include "../include/pe_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables for batch processing
char **input_files = NULL;
int num_input_files = 0;
size_t input_files_capacity = 0;

int add_input_file(const char *file_path) {
    if ((size_t)num_input_files >= input_files_capacity) {
        // Need to expand the array
        size_t new_capacity = (input_files_capacity == 0) ? 4 : input_files_capacity * 2;
        char **new_array = (char **)realloc(input_files, new_capacity * sizeof(char *));
        if (!new_array) {
            fprintf(stderr, "[-] Error: Memory allocation failed for input file list.\n");
            return 1;
        }
        input_files = new_array;
        input_files_capacity = new_capacity;
    }

    input_files[num_input_files] = strdup(file_path);
    if (!input_files[num_input_files]) {
        fprintf(stderr, "[-] Error: Memory allocation failed for input file path.\n");
        return 1;
    }
    num_input_files++;

    return 0;
}

int interactive_section_selection(PIMAGE_SECTION_HEADER *sections, size_t num_sections) {
    if (num_sections == 0) {
        printf("[!] No executable sections available to select.\n");
        return 0; // No sections to process
    }

    printf("\nFound %zu executable sections:\n", num_sections);
    for (size_t i = 0; i < num_sections; i++) {
        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
        safe_copy_section_name(sections[i]->Name, section_name, sizeof(section_name));

        printf("  [%zu] %s (%u bytes at RVA 0x%X)\n",
               i + 1, section_name, sections[i]->SizeOfRawData, sections[i]->VirtualAddress);
    }

    printf("\nEnter section numbers to extract (e.g., '1,3' or 'all'): ");
    fflush(stdout);

    char input[1024];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "[-] Error reading input.\n");
        return -1; // Error
    }

    // Process the input
    if (strncmp(input, "all", 3) == 0 || strncmp(input, "ALL", 3) == 0) {
        // Select all sections - this is handled by not filtering sections
        return 1; // Continue with all sections
    }

    // Parse comma-separated list of section numbers
    // For simplicity, we'll implement a different approach:
    // We'll create include_filters for the selected sections
    char *token = strtok(input, ", \n");
    while (token != NULL) {
        char *endptr;
        long section_num = strtol(token, &endptr, 10);

        if (*endptr != '\0' || section_num < 1 || section_num > (long)num_sections) {
            printf("[!] Invalid section number: %s\n", token);
        } else {
            // Add this section to include list
            char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
            safe_copy_section_name(sections[section_num - 1]->Name, section_name, sizeof(section_name));

            // Add to include sections filter
            char **temp_include = (char **)realloc(include_sections, (include_count + 1) * sizeof(char *));
            if (!temp_include) {
                fprintf(stderr, "[-] Error: Memory allocation failed for section filter.\n");
                return -1;
            }
            include_sections = temp_include;

            include_sections[include_count] = strdup(section_name);
            if (!include_sections[include_count]) {
                fprintf(stderr, "[-] Error: Memory allocation failed for section name.\n");
                // Free previously allocated sections to prevent memory leak
                for (size_t j = 0; j < include_count; j++) {
                    free(include_sections[j]);
                }
                free(include_sections);
                include_sections = NULL;
                include_count = 0;
                return -1;
            }
            include_count++;
        }

        token = strtok(NULL, ", \n");
    }

    return 1; // Process with selected filters
}
