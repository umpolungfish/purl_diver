/**
 * @file error_codes.h
 * @brief Error code definitions for purl_diver
 *
 * Provides structured error handling with descriptive error codes
 * instead of magic numbers (0/1 returns).
 */

#ifndef ERROR_CODES_H
#define ERROR_CODES_H

/**
 * @brief Error codes returned by extraction functions
 */
typedef enum {
    EXTRACT_SUCCESS = 0,              /**< Operation completed successfully */

    // File I/O errors (1-10)
    ERR_FILE_OPEN,                    /**< Failed to open input file */
    ERR_FILE_READ,                    /**< Failed to read from file */
    ERR_FILE_WRITE,                   /**< Failed to write to output file */
    ERR_FILE_TOO_LARGE,               /**< File exceeds size limit (500MB) */
    ERR_FILE_SEEK,                    /**< Failed to seek in file */

    // Memory errors (11-20)
    ERR_MEMORY_ALLOCATION,            /**< Memory allocation failed */
    ERR_INTEGER_OVERFLOW,             /**< Integer overflow detected */

    // PE validation errors (21-40)
    ERR_INVALID_DOS_SIGNATURE,        /**< Invalid DOS signature (not 'MZ') */
    ERR_INVALID_PE_SIGNATURE,         /**< Invalid PE signature (not 'PE\\0\\0') */
    ERR_UNSUPPORTED_ARCHITECTURE,     /**< Architecture not x86/x64 */
    ERR_INVALID_SECTION_TABLE,        /**< Section table outside file bounds */
    ERR_INVALID_NT_HEADERS,           /**< NT headers outside file bounds */
    ERR_INVALID_OPTIONAL_HEADER,      /**< Invalid optional header size */

    // Section analysis errors (41-50)
    ERR_NO_EXECUTABLE_SECTIONS,       /**< No executable sections found */
    ERR_SECTION_OVERLAP,              /**< Overlapping sections detected */
    ERR_SECTION_OUT_OF_BOUNDS,        /**< Section extends beyond file */

    // Argument/usage errors (51-60)
    ERR_INVALID_ARGUMENTS,            /**< Invalid command-line arguments */
    ERR_MISSING_REQUIRED_ARG,         /**< Required argument missing */
    ERR_INVALID_FORMAT_OPTION,        /**< Invalid output format specified */
    ERR_INVALID_SECTION_NAME,         /**< Invalid section name filter */
    ERR_FILE_ACCESS,                  /**< Failed to access file/directory */

    // Analysis errors (61-70)
    ERR_IMPORT_TABLE_INVALID,         /**< Corrupt import table */
    ERR_EXPORT_TABLE_INVALID,         /**< Corrupt export table */

    ERR_UNKNOWN                       /**< Unknown error */
} ExtractError;

/**
 * @brief Get human-readable error message for error code
 * @param err Error code
 * @return Constant string describing the error
 */
const char* error_string(ExtractError err);

/**
 * @brief Check if error code represents success
 * @param err Error code to check
 * @return 1 if success, 0 if error
 */
static inline int is_success(ExtractError err) {
    return err == EXTRACT_SUCCESS;
}

/**
 * @brief Check if error code represents a file I/O error
 * @param err Error code to check
 * @return 1 if file error, 0 otherwise
 */
static inline int is_file_error(ExtractError err) {
    return err >= ERR_FILE_OPEN && err <= ERR_FILE_SEEK;
}

/**
 * @brief Check if error code represents a PE format error
 * @param err Error code to check
 * @return 1 if PE format error, 0 otherwise
 */
static inline int is_pe_error(ExtractError err) {
    return err >= ERR_INVALID_DOS_SIGNATURE && err <= ERR_INVALID_OPTIONAL_HEADER;
}

#endif // ERROR_CODES_H
