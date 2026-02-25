/**
 * @file pe_parser.h
 * @brief PE file parsing and validation
 *
 * This module handles parsing and validation of Portable Executable (PE) files,
 * including structure validation, header parsing, and section enumeration.
 */

#ifndef PE_PARSER_H
#define PE_PARSER_H

#include "pe_types.h"
#include "error_codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum file size (500 MB) to prevent resource exhaustion
#define MAX_FILE_SIZE (500 * 1024 * 1024)

/**
 * @brief PE Context structure consolidating PE file information
 *
 * This structure holds all PE-related data in one place to avoid
 * repeated parameter passing and redundant calculations.
 */
typedef struct {
    unsigned char *buffer;              /**< File buffer containing entire PE file */
    long file_size;                     /**< Size of the PE file in bytes */

    // DOS and NT headers
    PIMAGE_DOS_HEADER dos_header;       /**< Pointer to DOS header */
    PIMAGE_NT_HEADERS32 nt_headers;     /**< Pointer to NT headers (32-bit) */
    WORD machine;                       /**< Machine architecture (x86/x64) */

    // Entry point information
    DWORD entry_point_rva;              /**< Relative virtual address of entry point */

    // Section information
    PIMAGE_SECTION_HEADER section_table; /**< Pointer to section table */
    WORD num_sections;                  /**< Number of sections in PE file */

    // Output buffer and configuration
    unsigned char *output_buffer;        /**< Buffer for extracted shellcode */
    size_t total_shellcode_size;        /**< Total size of extracted shellcode */
} PE_Context;

/**
 * @brief Validate PE file structure
 *
 * Performs comprehensive validation of PE file structure:
 * - File size validation (not empty, not too large)
 * - DOS signature check ('MZ')
 * - PE signature check ('PE\0\0')
 * - Architecture validation (x86/x64 only)
 *
 * @param f File handle (will be closed by this function)
 * @param buffer Output: allocated buffer containing file contents
 * @param file_size Output: size of the file
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 *
 * @note On success, caller must free *buffer. On failure, buffer is freed internally.
 * @note File handle is always closed, regardless of success/failure.
 */
ExtractError validate_pe_structure(FILE *f, unsigned char **buffer, long *file_size);

/**
 * @brief Initialize PE context from input file
 *
 * Opens and validates a PE file, then initializes the PE_Context structure
 * with all relevant PE headers and metadata.
 *
 * @param input_path Path to input PE file
 * @param ctx PE context structure to initialize (must be zeroed before call)
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 *
 * @note On success, ctx->buffer contains allocated memory that must be freed with cleanup_pe_context()
 */
ExtractError initialize_pe_context(const char *input_path, PE_Context *ctx);

/**
 * @brief Clean up PE context and free all associated resources
 *
 * Frees all dynamically allocated memory in the PE context and resets
 * all fields to zero.
 *
 * @param ctx PE context to clean up (may be NULL)
 */
void cleanup_pe_context(PE_Context *ctx);

/**
 * @brief Internal function to extract shellcode (for batch processing)
 *
 * @param input_path Path to input PE file
 * @param output_path Path to output file
 * @param output_path_can_be_null If true, non-binary formats can output to stdout
 * @return ExtractError code
 */
ExtractError extract_shellcode_internal(const char *input_path, const char *output_path);

/**
 * @brief Find all executable sections in PE file
 *
 * Searches for sections with IMAGE_SCN_CNT_CODE or IMAGE_SCN_MEM_EXECUTE
 * characteristics and returns pointers to them.
 *
 * @param ctx Initialized PE context
 * @param valid_sections Output: array of pointers to executable sections
 * @param num_valid_sections Output: number of executable sections found
 * @return ExtractError code (EXTRACT_SUCCESS on success)
 *
 * @note Caller must free *valid_sections on success
 */
ExtractError find_executable_sections(PE_Context *ctx,
                                     PIMAGE_SECTION_HEADER **valid_sections,
                                     size_t *num_valid_sections);

/**
 * @brief Safely copy PE section name
 *
 * PE section names are 8 bytes and may not be null-terminated.
 * This function safely copies and null-terminates the section name.
 *
 * @param src Source section name (8 bytes, may not be null-terminated)
 * @param dst Destination buffer (must be at least IMAGE_SIZEOF_SHORT_NAME + 1 bytes)
 * @param dst_size Size of destination buffer
 */
void safe_copy_section_name(const BYTE *src, char *dst, size_t dst_size);

/**
 * @brief Safe integer addition with overflow checking
 *
 * Performs addition with overflow detection to prevent integer overflow
 * vulnerabilities in size calculations.
 *
 * @param a First operand
 * @param b Second operand
 * @param result Output: result of a + b (only valid if return value is 0)
 * @return 0 on success, 1 if overflow would occur
 */
int safe_add_size(size_t a, size_t b, size_t *result);

/**
 * @brief Convert RVA (Relative Virtual Address) to file offset
 *
 * Translates an RVA to the corresponding file offset by searching through
 * the section table.
 *
 * @param rva Relative virtual address to convert
 * @param section_table Array of section headers
 * @param num_sections Number of sections
 * @param file_size Size of file (for bounds checking)
 * @return File offset, or 0 if RVA is invalid
 */
DWORD rva_to_file_offset(DWORD rva, PIMAGE_SECTION_HEADER section_table,
                         WORD num_sections, long file_size);

/**
 * @brief Compare two sections by raw data offset (for qsort)
 *
 * Comparison function used to sort sections by their PointerToRawData field.
 *
 * @param a Pointer to first PIMAGE_SECTION_HEADER*
 * @param b Pointer to second PIMAGE_SECTION_HEADER*
 * @return Negative if a < b, 0 if equal, positive if a > b
 */
int compare_sections(const void *a, const void *b);

#include "options.h"

#endif // PE_PARSER_H
