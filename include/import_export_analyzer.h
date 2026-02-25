/**
 * @file import_export_analyzer.h
 * @brief Import and Export Table Analysis
 *
 * Provides functionality to analyze and display PE import and export tables,
 * including imported DLLs, functions, and exported symbols.
 */

#ifndef IMPORT_EXPORT_ANALYZER_H
#define IMPORT_EXPORT_ANALYZER_H

#include "pe_types.h"

/**
 * @brief Analyze and display PE import table
 *
 * Parses the Import Address Table (IAT) and Import Name Table (INT) to display:
 * - Imported DLL names
 * - Imported function names with hints
 * - Ordinal imports
 *
 * Supports both 32-bit and 64-bit PE files.
 *
 * @param buffer PE file buffer
 * @param rva_to_imports Optional pointer to import directory RVA (NULL to auto-detect)
 * @param rva_to_names Optional pointer to import names RVA (NULL to skip)
 * @param machine Machine type (IMAGE_FILE_MACHINE_I386 or IMAGE_FILE_MACHINE_AMD64)
 * @param file_size Size of PE file buffer
 */
void analyze_imports(unsigned char *buffer, DWORD *rva_to_imports, DWORD *rva_to_names,
                     WORD machine, long file_size);

/**
 * @brief Analyze and display PE export table
 *
 * Parses the Export Address Table (EAT) to display:
 * - DLL name
 * - Base ordinal
 * - Number of functions exported
 * - Exported function names
 *
 * Supports both 32-bit and 64-bit PE files.
 *
 * @param buffer PE file buffer
 * @param rva_to_exports Export directory RVA (0 to auto-detect)
 * @param machine Machine type (IMAGE_FILE_MACHINE_I386 or IMAGE_FILE_MACHINE_AMD64)
 * @param file_size Size of PE file buffer
 */
void analyze_exports(unsigned char *buffer, DWORD rva_to_exports, WORD machine, long file_size);

/**
 * @brief Print combined import/export summary
 *
 * Convenience function that analyzes and displays both import and export tables.
 * Auto-detects import/export directory locations from PE headers.
 *
 * @param buffer PE file buffer
 * @param machine Machine type (IMAGE_FILE_MACHINE_I386 or IMAGE_FILE_MACHINE_AMD64)
 * @param file_size Size of PE file buffer
 */
void print_imports_exports_summary(unsigned char *buffer, WORD machine, long file_size);

#include "options.h"

#endif // IMPORT_EXPORT_ANALYZER_H
