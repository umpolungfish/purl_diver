/**
 * @file batch_processor.h
 * @brief Batch processing functionality for PE shellcode extraction
 *
 * This module handles batch processing of multiple PE files from a directory,
 * with options for recursive processing, pattern matching, and output management.
 */

#ifndef BATCH_PROCESSOR_H
#define BATCH_PROCESSOR_H

#include "pe_parser.h"
#include "error_codes.h"
#include "options.h"
#include <stdio.h>

/**
 * @brief Structure to hold batch processing statistics
 */
typedef struct {
    int total_files_processed;
    int successful_extractions;
    int failed_extractions;
    int skipped_files;
} BatchStats;

/**
 * @brief Process all PE files in a directory batch-wise
 *
 * Processes all PE files in the specified directory according to the current
 * global options, extracting shellcode from each file and saving to output
 * directory with appropriate naming.
 *
 * @param input_dir Directory containing PE files to process
 * @param output_dir Directory for output files (can be NULL for current dir)
 * @param pattern File pattern to match (e.g., "*.exe,*.dll") (can be NULL for default)
 * @param recursive Whether to process subdirectories recursively
 * @param log_file Path to log file for batch processing results (can be NULL)
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 */
ExtractError process_batch(const char *input_dir, const char *output_dir, 
                          const char *pattern, int recursive, const char *log_file);

/**
 * @brief Get batch processing statistics
 *
 * Returns statistics about the last batch processing run.
 *
 * @return BatchStats containing processing statistics
 */
BatchStats get_batch_stats(void);

/**
 * @brief Initialize batch processing statistics
 */
void init_batch_stats(void);

/**
 * @brief Log batch processing result to file
 *
 * Logs the result of processing a single file to the specified log file.
 *
 * @param log_file FILE pointer to log file (can be NULL)
 * @param filename Name of the file processed
 * @param success Whether processing was successful
 * @param bytes_extracted Number of bytes extracted (if successful)
 * @param error_msg Error message (if failed)
 */
void log_batch_result(FILE *log_file, const char *filename, int success, 
                     size_t bytes_extracted, const char *error_msg);

#endif // BATCH_PROCESSOR_H