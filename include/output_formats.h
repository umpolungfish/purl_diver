/**
 * @file output_formats.h
 * @brief Output formatters for extracted shellcode
 *
 * Provides multiple output formats: C array, Python bytes, hex dump, and JSON.
 */

#ifndef OUTPUT_FORMATS_H
#define OUTPUT_FORMATS_H

#include "pe_types.h"
#include <stddef.h>

/**
 * @brief Output shellcode as C array
 *
 * Generates C source code with a byte array initialized with the shellcode data.
 * Output format:
 *   unsigned char shellcode[] = {
 *     0x4D, 0x5A, 0x90, 0x00, ...
 *   };
 *
 * @param data Shellcode data to output
 * @param size Size of data in bytes
 * @param filename Optional name for the array (defaults to "shellcode")
 */
void output_as_c_array(unsigned char *data, size_t size, const char *filename);

/**
 * @brief Output shellcode as Python byte string
 *
 * Generates Python source code with a byte string.
 * Output format:
 *   shellcode = b"\x4D\x5A\x90\x00..."
 *
 * @param data Shellcode data to output
 * @param size Size of data in bytes
 * @param filename Optional parameter (unused, kept for API consistency)
 */
void output_as_python(unsigned char *data, size_t size, const char *filename);

/**
 * @brief Output shellcode as hex dump
 *
 * Generates a traditional hex dump with ASCII representation.
 * Output format:
 *   00000000: 4D 5A 90 00 03 00 00 00  04 00 00 00 FF FF 00 00 |MZ..............|
 *   00000010: B8 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00 |........@.......|
 *
 * @param data Shellcode data to output
 * @param size Size of data in bytes
 * @param filename Optional parameter (unused, kept for API consistency)
 */
void output_as_hex_dump(unsigned char *data, size_t size, const char *filename);

/**
 * @brief Output shellcode and metadata as JSON
 *
 * Generates a JSON document with shellcode metadata including:
 * - Input file path
 * - Architecture (x86/x64)
 * - Entry point RVA
 * - Section information
 * - Total size and entropy
 *
 * @param data Shellcode data (used for entropy calculation)
 * @param size Size of data in bytes
 * @param input_path Path to original PE file
 * @param valid_sections Array of extracted section headers
 * @param num_valid_sections Number of sections in array
 * @param entry_point_rva Entry point relative virtual address
 * @param machine Machine type (IMAGE_FILE_MACHINE_I386 or IMAGE_FILE_MACHINE_AMD64)
 */
void output_as_json(unsigned char *data, size_t size, const char *input_path,
                    PIMAGE_SECTION_HEADER *valid_sections, size_t num_valid_sections,
                    DWORD entry_point_rva, WORD machine);

/**
 * @brief Parse an output format name string into an OutputFormat enum value
 *
 * Accepts: "binary", "c", "c-array", "python", "hex", "hex-dump", "json"
 *
 * @param str Format name string
 * @param format Output: parsed OutputFormat value (only set on success)
 * @return 0 on success, -1 if str is not a recognized format name
 */
int parse_output_format(const char *str, OutputFormat *format);

/**
 * @brief Get the appropriate file extension for an output format
 *
 * @param format Output format to get extension for
 * @return Constant string with the extension (without the dot)
 */
const char* get_output_extension(OutputFormat format);

#endif // OUTPUT_FORMATS_H
