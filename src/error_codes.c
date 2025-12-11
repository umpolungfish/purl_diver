/**
 * @file error_codes.c
 * @brief Implementation of error code utilities
 */

#include "../include/error_codes.h"

const char* error_string(ExtractError err) {
    switch (err) {
        case EXTRACT_SUCCESS:
            return "Success";

        // File I/O errors
        case ERR_FILE_OPEN:
            return "Failed to open file";
        case ERR_FILE_READ:
            return "Failed to read from file";
        case ERR_FILE_WRITE:
            return "Failed to write to output file";
        case ERR_FILE_TOO_LARGE:
            return "File exceeds maximum size limit (500MB)";
        case ERR_FILE_SEEK:
            return "Failed to seek in file";

        // Memory errors
        case ERR_MEMORY_ALLOCATION:
            return "Memory allocation failed";
        case ERR_INTEGER_OVERFLOW:
            return "Integer overflow detected in size calculation";

        // PE validation errors
        case ERR_INVALID_DOS_SIGNATURE:
            return "Invalid DOS signature - not a valid PE file";
        case ERR_INVALID_PE_SIGNATURE:
            return "Invalid PE signature - corrupt or malformed PE file";
        case ERR_UNSUPPORTED_ARCHITECTURE:
            return "Unsupported architecture - only x86 and x64 are supported";
        case ERR_INVALID_SECTION_TABLE:
            return "Section table is outside file bounds";
        case ERR_INVALID_NT_HEADERS:
            return "NT headers are outside file bounds";
        case ERR_INVALID_OPTIONAL_HEADER:
            return "Invalid optional header size";

        // Section analysis errors
        case ERR_NO_EXECUTABLE_SECTIONS:
            return "No executable sections found in PE file";
        case ERR_SECTION_OVERLAP:
            return "Overlapping sections detected";
        case ERR_SECTION_OUT_OF_BOUNDS:
            return "Section extends beyond file boundaries";

        // Argument errors
        case ERR_INVALID_ARGUMENTS:
            return "Invalid command-line arguments";
        case ERR_MISSING_REQUIRED_ARG:
            return "Missing required argument";
        case ERR_INVALID_FORMAT_OPTION:
            return "Invalid output format specified";
        case ERR_INVALID_SECTION_NAME:
            return "Invalid section name in filter";
        case ERR_FILE_ACCESS:
            return "Failed to access file or directory";

        // Analysis errors
        case ERR_IMPORT_TABLE_INVALID:
            return "Import table is corrupt or invalid";
        case ERR_EXPORT_TABLE_INVALID:
            return "Export table is corrupt or invalid";

        case ERR_UNKNOWN:
        default:
            return "Unknown error";
    }
}
