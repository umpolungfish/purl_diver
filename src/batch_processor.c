#define _GNU_SOURCE  // Required for strcasecmp and strdup on Linux

/**
 * @file batch_processor.c
 * @brief Batch processing functionality for PE shellcode extraction
 *
 * This module handles batch processing of multiple PE files from a directory,
 * with options for recursive processing, pattern matching, and output management.
 */

#include "../include/batch_processor.h"
#include "../include/pe_parser.h"
#include "../include/section_analyzer.h"
#include "../include/output_formats.h"
#include "../include/hash_algorithms.h"
#include "../include/entropy.h"
#include "../include/import_export_analyzer.h"
#include "../include/utils.h"
#include "../include/options.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <shlwapi.h>
#else
#include <dirent.h>
#include <fnmatch.h>
#include <unistd.h>
#endif

// Global batch statistics
static BatchStats g_batch_stats = {0};

void init_batch_stats(void) {
    g_batch_stats.total_files_processed = 0;
    g_batch_stats.successful_extractions = 0;
    g_batch_stats.failed_extractions = 0;
    g_batch_stats.skipped_files = 0;
}

BatchStats get_batch_stats(void) {
    return g_batch_stats;
}

void log_batch_result(FILE *log_file, const char *filename, int success, 
                     size_t bytes_extracted, const char *error_msg) {
    if (!log_file) return;
    
    if (success) {
        fprintf(log_file, "[SUCCESS] %s: Extracted %zu bytes\n", filename, bytes_extracted);
    } else {
        fprintf(log_file, "[FAILED]  %s: %s\n", filename, error_msg ? error_msg : "Unknown error");
    }
    fflush(log_file);
}

#ifdef _WIN32

/**
 * @brief Check if a file matches the given pattern on Windows
 */
static int matches_pattern(const char *filename, const char *pattern) {
    if (!pattern || strlen(pattern) == 0) {
        // Default pattern: .exe and .dll files
        const char *ext = strrchr(filename, '.');
        if (ext) {
            if (strcasecmp(ext, ".exe") == 0 || strcasecmp(ext, ".dll") == 0 || strcasecmp(ext, ".sys") == 0) {
                return 1;
            }
        }
        return 0;
    }

    // Handle comma-separated patterns
    char *pattern_copy = _strdup(pattern);
    if (!pattern_copy) return 0;
    
    char *token = strtok(pattern_copy, ",");
    while (token) {
        // Trim whitespace
        while (*token == ' ') token++;
        char *end = token + strlen(token) - 1;
        while (end > token && *end == ' ') *end = '\0';
        
        if (PathMatchSpecA(filename, token)) {
            free(pattern_copy);
            return 1;
        }
        token = strtok(NULL, ",");
    }
    
    free(pattern_copy);
    return 0;
}

/**
 * @brief Process a single directory on Windows
 */
static ExtractError process_directory_win(const char *dir_path, const char *output_dir,
                                         const char *pattern, int recursive, FILE *log_file) {
    // Build search path
    char search_path[MAX_PATH];
    snprintf(search_path, sizeof(search_path), "%s\\*", dir_path);

    WIN32_FIND_DATAA find_data;
    HANDLE h_find = FindFirstFileA(search_path, &find_data);

    if (h_find == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[-] Error: Cannot access directory '%s'\n", dir_path);
        return ERR_FILE_ACCESS;
    }

    do {
        // Skip current and parent directory entries
        if (strcmp(find_data.cFileName, ".") == 0 || strcmp(find_data.cFileName, "..") == 0) {
            continue;
        }

        // Build full file path
        char full_path[MAX_PATH];
        int path_n = snprintf(full_path, sizeof(full_path), "%s\\%s", dir_path, find_data.cFileName);
        if (path_n < 0 || (size_t)path_n >= sizeof(full_path)) {
            fprintf(stderr, "[-] Warning: Path too long, skipping: %s\\%s\n",
                    dir_path, find_data.cFileName);
            g_batch_stats.skipped_files++;
            continue;
        }

        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // Process subdirectory if recursive mode is enabled
            if (recursive) {
                process_directory_win(full_path, output_dir, pattern, recursive, log_file);
            }
        } else {
            // Check if file matches pattern
            if (matches_pattern(find_data.cFileName, pattern)) {
                // Process the PE file
                g_batch_stats.total_files_processed++;

                // Generate output filename
                char output_filename[MAX_PATH];
                int out_n;
                if (output_dir) {
                    const char *base_name = strrchr(find_data.cFileName, '\\');
                    if (base_name) base_name++;
                    else base_name = find_data.cFileName;
                    out_n = snprintf(output_filename, sizeof(output_filename),
                                    "%s/%s_shellcode", output_dir, base_name);
                } else {
                    out_n = snprintf(output_filename, sizeof(output_filename),
                                    "%s_shellcode", find_data.cFileName);
                }
                if (out_n < 0 || (size_t)out_n >= sizeof(output_filename)) {
                    fprintf(stderr, "[-] Warning: Output path too long, skipping: %s\n",
                            find_data.cFileName);
                    g_batch_stats.skipped_files++;
                    continue;
                }

                // Ensure correct extension based on format
                const char *ext = get_output_extension(g_options.output_format);
                if (ext) {
                    int ext_n = snprintf(output_filename + out_n,
                                        sizeof(output_filename) - (size_t)out_n,
                                        ".%s", ext);
                    if (ext_n < 0 || (size_t)ext_n >= sizeof(output_filename) - (size_t)out_n) {
                        fprintf(stderr, "[-] Warning: Output path too long after extension, skipping: %s\n",
                                find_data.cFileName);
                        g_batch_stats.skipped_files++;
                        continue;
                    }
                }

                // Call extract_shellcode function for this file
                ExtractError err = extract_shellcode_internal(full_path, output_filename);

                if (err == EXTRACT_SUCCESS) {
                    g_batch_stats.successful_extractions++;
                    log_batch_result(log_file, find_data.cFileName, 1, 0, NULL);
                } else {
                    g_batch_stats.failed_extractions++;
                    log_batch_result(log_file, find_data.cFileName, 0, 0, error_string(err));
                }
            }
        }
    } while (FindNextFileA(h_find, &find_data));

    FindClose(h_find);
    return EXTRACT_SUCCESS;
}

#else  // Unix/Linux/macOS

/**
 * @brief Check if a file matches the given pattern on Unix systems
 */
static int matches_pattern(const char *filename, const char *pattern) {
    if (!pattern || strlen(pattern) == 0) {
        // Default pattern: .exe and .dll files
        const char *ext = strrchr(filename, '.');
        if (ext) {
            if (strcasecmp(ext, ".exe") == 0 || strcasecmp(ext, ".dll") == 0 || strcasecmp(ext, ".sys") == 0) {
                return 1;
            }
        }
        return 0;
    }

    // Handle comma-separated patterns
    char *pattern_copy = strdup(pattern);
    if (!pattern_copy) return 0;
    
    char *token = strtok(pattern_copy, ",");
    while (token) {
        // Trim whitespace
        while (*token == ' ') token++;
        char *end = token + strlen(token) - 1;
        while (end > token && *end == ' ') *end = '\0';
        
        if (fnmatch(token, filename, 0) == 0) {
            free(pattern_copy);
            return 1;
        }
        token = strtok(NULL, ",");
    }
    
    free(pattern_copy);
    return 0;
}

/**
 * @brief Process a single directory on Unix systems
 */
static ExtractError process_directory_unix(const char *dir_path, const char *output_dir,
                                         const char *pattern, int recursive, FILE *log_file) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "[-] Error: Cannot open directory '%s'\n", dir_path);
        return ERR_FILE_ACCESS;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build full file path
        char full_path[1024];
        int path_n = snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (path_n < 0 || (size_t)path_n >= sizeof(full_path)) {
            fprintf(stderr, "[-] Warning: Path too long, skipping: %s/%s\n",
                    dir_path, entry->d_name);
            g_batch_stats.skipped_files++;
            continue;
        }

        struct stat path_stat;
        if (stat(full_path, &path_stat) == -1) {
            continue;  // Skip if we can't stat the file
        }

        if (S_ISDIR(path_stat.st_mode)) {
            // Process subdirectory if recursive mode is enabled
            if (recursive) {
                process_directory_unix(full_path, output_dir, pattern, recursive, log_file);
            }
        } else if (S_ISREG(path_stat.st_mode)) {
            // Check if file matches pattern
            if (matches_pattern(entry->d_name, pattern)) {
                // Process the PE file
                g_batch_stats.total_files_processed++;

                // Generate output filename
                char output_filename[1024];
                int out_n;
                if (output_dir) {
                    out_n = snprintf(output_filename, sizeof(output_filename),
                                    "%s/%s_shellcode", output_dir, entry->d_name);
                } else {
                    out_n = snprintf(output_filename, sizeof(output_filename),
                                    "%s_shellcode", entry->d_name);
                }
                if (out_n < 0 || (size_t)out_n >= sizeof(output_filename)) {
                    fprintf(stderr, "[-] Warning: Output path too long, skipping: %s\n",
                            entry->d_name);
                    g_batch_stats.skipped_files++;
                    continue;
                }

                // Ensure correct extension based on format
                const char *ext = get_output_extension(g_options.output_format);
                if (ext) {
                    int ext_n = snprintf(output_filename + out_n,
                                        sizeof(output_filename) - (size_t)out_n,
                                        ".%s", ext);
                    if (ext_n < 0 || (size_t)ext_n >= sizeof(output_filename) - (size_t)out_n) {
                        fprintf(stderr, "[-] Warning: Output path too long after extension, skipping: %s\n",
                                entry->d_name);
                        g_batch_stats.skipped_files++;
                        continue;
                    }
                }

                // Call extract_shellcode function for this file
                ExtractError err = extract_shellcode_internal(full_path, output_filename);

                if (err == EXTRACT_SUCCESS) {
                    g_batch_stats.successful_extractions++;
                    log_batch_result(log_file, entry->d_name, 1, 0, NULL);
                } else {
                    g_batch_stats.failed_extractions++;
                    log_batch_result(log_file, entry->d_name, 0, 0, error_string(err));
                }
            }
        }
    }

    closedir(dir);
    return EXTRACT_SUCCESS;
}

#endif  // _WIN32

ExtractError process_batch(const char *input_dir, const char *output_dir, 
                          const char *pattern, int recursive, const char *log_file_path) {
    // Initialize statistics
    init_batch_stats();
    
    // Open log file if specified
    FILE *log_file = NULL;
    if (log_file_path) {
        log_file = fopen(log_file_path, "w");
        if (!log_file) {
            fprintf(stderr, "[-] Warning: Cannot open log file '%s'\n", log_file_path);
        } else {
            fprintf(log_file, "Batch processing log - Directory: %s\n", input_dir);
            fprintf(log_file, "Output directory: %s\n", output_dir ? output_dir : "current directory");
            fprintf(log_file, "Pattern: %s\n", pattern ? pattern : "default (*.exe,*.dll)");
            fprintf(log_file, "Recursive: %s\n\n", recursive ? "YES" : "NO");
        }
    }
    
    // Process the directory
    ExtractError result;
#ifdef _WIN32
    result = process_directory_win(input_dir, output_dir, pattern, recursive, log_file);
#else
    result = process_directory_unix(input_dir, output_dir, pattern, recursive, log_file);
#endif

    // Log summary
    if (log_file) {
        fprintf(log_file, "\n[SUMMARY]\n");
        fprintf(log_file, "Total files processed: %d\n", g_batch_stats.total_files_processed);
        fprintf(log_file, "Successful extractions: %d\n", g_batch_stats.successful_extractions);
        fprintf(log_file, "Failed extractions: %d\n", g_batch_stats.failed_extractions);
        fprintf(log_file, "Skipped files: %d\n", g_batch_stats.skipped_files);
    }
    
    if (log_file) {
        fclose(log_file);
    }
    
    return result;
}