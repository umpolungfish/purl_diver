/*
 * Enterprise-Grade Shellcode Extraction Tool for PE Files
 *
 * This tool extracts executable code from PE (Portable Executable) files,
 * supporting both 32-bit and 64-bit architectures. It is designed to be
 * cross-platform, compilable with MSVC, GCC, and Clang.
 *
 * Features:
 * - Cross-platform (Windows, Linux, macOS).
 * - Supports x86 (32-bit) and x64 (64-bit) PE files.
 * - Extracts from all executable sections.
 * - Safely handles and skips overlapping sections to prevent data corruption.
 * - Robust validation of PE file format.
 * - Memory-safe with precise buffer allocation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <errno.h>

#include "pe_parser.h"
#include "utils.h"

// Output format enum
typedef enum {
    OUTPUT_BINARY,  // Default: raw binary
    OUTPUT_C_ARRAY, // C array format
    OUTPUT_PYTHON,  // Python byte string
    OUTPUT_HEX_DUMP, // Hex dump format
    OUTPUT_JSON     // JSON format
} OutputFormat;

// Global flags and options
static int verbose = 0;
static char **include_sections = NULL;
static char **exclude_sections = NULL;
static size_t include_count = 0;
static size_t exclude_count = 0;
static DWORD min_section_size = 0;
static int dry_run = 0;
static OutputFormat output_format = OUTPUT_BINARY;
static int include_hash = 0;  // Flag to include hash calculation
static int include_entropy = 0;  // Flag to include entropy calculation
static int analyze_imports_exports = 0;  // Flag to include import/export analysis
static int batch_mode = 0;  // Flag to enable batch processing mode
static char *batch_output_dir = NULL;  // Directory for batch output files
static int interactive_mode = 0;  // Flag to enable interactive section selection mode
static int show_progress = 0;  // Flag to show progress indicator for large files

// For batch processing
static char **input_files = NULL;  // Array of input file paths
static int num_input_files = 0;    // Number of input files
static size_t input_files_capacity = 0;  // Capacity of input_files array

// Forward declaration for functions used in cleanup_all
void free_section_filters(void);

// Global cleanup function to be called on exit to ensure all resources are freed
void cleanup_all(void) {
    free_section_filters();

    // Free batch input files
    if (input_files) {
        for (int i = 0; i < num_input_files; i++) {
            free(input_files[i]);
        }
        free(input_files);
        input_files = NULL;
        num_input_files = 0;
        input_files_capacity = 0;
    }
}





// Hash function declarations
void calculate_md5(unsigned char *data, size_t len, unsigned char *hash);
void calculate_sha256(unsigned char *data, size_t len, unsigned char *hash);
void print_hash(unsigned char *hash, int hash_len, const char *format_type);

// Entropy calculation function declaration
double calculate_entropy(unsigned char *data, size_t len);

// Import/Export analysis function declarations
void analyze_imports(unsigned char *buffer, DWORD *rva_to_imports, DWORD *rva_to_names, WORD machine, long file_size);
void analyze_exports(unsigned char *buffer, DWORD rva_to_exports, WORD machine, long file_size);
void print_imports_exports_summary(unsigned char *buffer, WORD machine, long file_size);





// Cleanup function for error recovery
void cleanup_and_exit(unsigned char *buf, PIMAGE_SECTION_HEADER *secs, FILE *f, int exit_code) {
    if (buf) free(buf);
    if (secs) free(secs);
    if (f) fclose(f);
    exit(exit_code);
}

// Helper function to check if a section name matches the include/exclude filters
int is_section_included(PIMAGE_SECTION_HEADER section) {
    char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
    memcpy(section_name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
    section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';  // Ensure null termination

    // Check minimum section size filter
    if (min_section_size > 0 && section->SizeOfRawData < min_section_size) {
        if (verbose) {
            printf("[DEBUG] Skipping section '%s' - smaller than minimum size (%d < %d)\n",
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

// Helper function to parse section names from a comma-separated string
int parse_section_name(const char *section_str, char ***section_names, size_t *count) {
    if (!section_str || !section_names || !count) return 1;

    // Single pass: count commas to estimate count
    size_t estimated_count = 1;
    for (const char *p = section_str; *p; p++) {
        if (*p == ',') estimated_count++;
    }

    *section_names = (char **)malloc(estimated_count * sizeof(char *));
    if (!*section_names) return 1;

    *count = 0;
    char *temp = my_strdup(section_str);
    if (!temp) {
        free(*section_names);
        return 1;
    }

    char *token = strtok(temp, ",");
    while (token && *count < estimated_count) {
        // Skip leading/trailing whitespace
        while (*token == ' ') token++;
        char *end = token + strlen(token) - 1;
        while (end > token && *end == ' ') end--;
        *(end + 1) = '\0';

        (*section_names)[*count] = my_strdup(token);
        if (!(*section_names)[*count]) {
            // Cleanup
            for (size_t i = 0; i < *count; i++) free((*section_names)[i]);
            free(*section_names);
            free(temp);
            return 1;
        }
        (*count)++;
        token = strtok(NULL, ",");
    }

    free(temp);
    return 0;
}

// Helper function to free section filter arrays
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

// Output shellcode as C array
void output_as_c_array(unsigned char *data, size_t size, const char *filename) {
    printf("unsigned char %s[] = {", filename ? filename : "shellcode");
    for (size_t i = 0; i < size; i++) {
        if (i % 12 == 0) printf("\n  ");
        printf("0x%02X", data[i]);
        if (i < size - 1) printf(",");
    }
    printf("\n};\n");
}

// Output shellcode as Python byte string
void output_as_python(unsigned char *data, size_t size, const char *filename) {
    (void)filename; // Suppress unused parameter warning
    printf("shellcode = b\"");
    for (size_t i = 0; i < size; i++) {
        printf("\\x%02X", data[i]);
    }
    printf("\"\n");
}

// Output shellcode as hex dump
void output_as_hex_dump(unsigned char *data, size_t size, const char *filename) {
    (void)filename; // Suppress unused parameter warning
    for (size_t i = 0; i < size; i += 16) {
        printf("%08zX: ", i);
        for (int j = 0; j < 16; j++) {
            if (i + j < size) {
                printf("%02X ", data[i + j]);
            } else {
                printf("   ");
            }
            if (j == 7) printf(" ");
        }
        printf(" |");
        for (int j = 0; j < 16; j++) {
            if (i + j < size) {
                unsigned char c = data[i + j];
                printf("%c", (c >= 32 && c <= 126) ? c : '.');
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

// Output shellcode and metadata as JSON
void output_as_json(unsigned char *data, size_t size, const char *input_path, 
                    PIMAGE_SECTION_HEADER *valid_sections, size_t num_valid_sections, 
                    DWORD entry_point_rva, WORD machine) {
    printf("{\n");
    printf("  \"input_file\": \"%s\",\n", input_path);
    printf("  \"architecture\": \"%s\",\n", (machine == IMAGE_FILE_MACHINE_I386) ? "x86" : "x64");
    printf("  \"entry_point_rva\": %u,\n", entry_point_rva);
    printf("  \"sections_extracted\": %zu,\n", num_valid_sections);
    printf("  \"total_bytes\": %zu,\n", size);
    printf("  \"total_entropy\": %.4f,\n", calculate_entropy(data, size));  // Overall entropy of extracted data
    printf("  \"sections\": [\n");
    
    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = valid_sections[i];
        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
        memcpy(section_name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
        section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';
        
        // Properly escape the section name to ensure valid JSON
        printf("    {\n");
        printf("      \"name\": \"");
        for (int j = 0; j < IMAGE_SIZEOF_SHORT_NAME && section_name[j] != '\0'; j++) {
            if (section_name[j] == '\\' || section_name[j] == '"') {
                printf("\\%c", section_name[j]);
            } else if (section_name[j] == '\b') {
                printf("\\b");
            } else if (section_name[j] == '\f') {
                printf("\\f");
            } else if (section_name[j] == '\n') {
                printf("\\n");
            } else if (section_name[j] == '\r') {
                printf("\\r");
            } else if (section_name[j] == '\t') {
                printf("\\t");
            } else {
                printf("%c", section_name[j]);
            }
        }
        printf("\",\n");
        printf("      \"size\": %u,\n", section->SizeOfRawData);
        printf("      \"virtual_address\": %u,\n", section->VirtualAddress);
        printf("      \"raw_data_offset\": %u,\n", section->PointerToRawData);
        printf("      \"characteristics\": %u\n", section->Characteristics);
        // Note: We can't provide section entropy from this function context since we don't have access to the full file buffer
        // Section entropy would need to be calculated in the extract_shellcode function
        
        if (i < num_valid_sections - 1) {
            printf("    },\n");
        } else {
            printf("    }\n");
        }
    }
    printf("  ]\n");
    printf("}\n");
}

// Hash calculation functions

// A real implementation would use proper SHA256 and MD5 algorithms
// For this demonstration, I'll implement simplified versions
// In a production environment, you would want to include a proper cryptographic library

// MD5 streaming context for chunk-based processing
typedef struct {
    uint32_t h[4];           // Hash state
    unsigned char buffer[64]; // Working buffer (512 bits)
    size_t buffer_len;       // Current bytes in buffer
    uint64_t total_len;      // Total bytes processed
} MD5_Context;

// Initialize MD5 context
void md5_init(MD5_Context *ctx) {
    ctx->h[0] = 0x67452301;
    ctx->h[1] = 0xefcdab89;
    ctx->h[2] = 0x98badcfe;
    ctx->h[3] = 0x10325476;
    ctx->buffer_len = 0;
    ctx->total_len = 0;
}

// Process a single 512-bit block
// MD5 implementation following RFC 1321 - The MD5 Message-Digest Algorithm
static void md5_process_block(MD5_Context *ctx, const unsigned char *block) {
    uint32_t k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    uint32_t w[16];
    for (int i = 0; i < 16; i++) {
        w[i] = (block[i * 4]) |
               (block[i * 4 + 1] << 8) |
               (block[i * 4 + 2] << 16) |
               (block[i * 4 + 3] << 24);
    }

    uint32_t a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3];

    // Main loop
    for (int i = 0; i < 64; i++) {
        uint32_t f, g;

        if (i < 16) {
            f = (b & c) | (~b & d);
            g = i;
        } else if (i < 32) {
            f = (d & b) | (~d & c);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        } else {
            f = c ^ (b | ~d);
            g = (7 * i) % 16;
        }

        f = f + a + k[i] + w[g];
        a = d;
        d = c;
        c = b;
        b = b + f;
    }

    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
}

// Update context with new data
void md5_update(MD5_Context *ctx, const unsigned char *data, size_t len) {
    ctx->total_len += len;

    // If we have buffered data, try to fill the buffer first
    if (ctx->buffer_len > 0) {
        size_t to_copy = 64 - ctx->buffer_len;
        if (to_copy > len) to_copy = len;

        memcpy(ctx->buffer + ctx->buffer_len, data, to_copy);
        ctx->buffer_len += to_copy;
        data += to_copy;
        len -= to_copy;

        // If buffer is full, process it
        if (ctx->buffer_len == 64) {
            md5_process_block(ctx, ctx->buffer);
            ctx->buffer_len = 0;
        }
    }

    // Process complete 64-byte blocks directly from input
    while (len >= 64) {
        md5_process_block(ctx, data);
        data += 64;
        len -= 64;
    }

    // Buffer remaining bytes
    if (len > 0) {
        memcpy(ctx->buffer, data, len);
        ctx->buffer_len = len;
    }
}

// Finalize and produce hash
void md5_final(MD5_Context *ctx, unsigned char *hash) {
    // Append 1 bit (0x80 byte)
    ctx->buffer[ctx->buffer_len++] = 0x80;

    // If not enough room for length, pad and process
    if (ctx->buffer_len > 56) {
        while (ctx->buffer_len < 64) {
            ctx->buffer[ctx->buffer_len++] = 0;
        }
        md5_process_block(ctx, ctx->buffer);
        ctx->buffer_len = 0;
    }

    // Pad with zeros until 56 bytes
    while (ctx->buffer_len < 56) {
        ctx->buffer[ctx->buffer_len++] = 0;
    }

    // Append length in bits as 64-bit little-endian
    uint64_t bit_len = ctx->total_len * 8;
    for (int i = 0; i < 8; i++) {
        ctx->buffer[56 + i] = (bit_len >> (8 * i)) & 0xff;
    }

    // Process final block
    md5_process_block(ctx, ctx->buffer);

    // Produce final hash (little-endian)
    for (int i = 0; i < 4; i++) {
        hash[i] = (ctx->h[0] >> (i * 8)) & 0xff;
        hash[i+4] = (ctx->h[1] >> (i * 8)) & 0xff;
        hash[i+8] = (ctx->h[2] >> (i * 8)) & 0xff;
        hash[i+12] = (ctx->h[3] >> (i * 8)) & 0xff;
    }
}

// MD5 implementation
void calculate_md5(unsigned char *data, size_t len, unsigned char *hash) {
    MD5_Context ctx;
    md5_init(&ctx);
    md5_update(&ctx, data, len);
    md5_final(&ctx, hash);
}

// SHA256 streaming context for chunk-based processing
typedef struct {
    uint32_t h[8];           // Hash state
    unsigned char buffer[64]; // Working buffer (512 bits)
    size_t buffer_len;       // Current bytes in buffer
    uint64_t total_len;      // Total bytes processed
} SHA256_Context;

// Initialize SHA256 context
void sha256_init(SHA256_Context *ctx) {
    ctx->h[0] = 0x6a09e667;
    ctx->h[1] = 0xbb67ae85;
    ctx->h[2] = 0x3c6ef372;
    ctx->h[3] = 0xa54ff53a;
    ctx->h[4] = 0x510e527f;
    ctx->h[5] = 0x9b05688c;
    ctx->h[6] = 0x1f83d9ab;
    ctx->h[7] = 0x5be0cd19;
    ctx->buffer_len = 0;
    ctx->total_len = 0;
}

// Process a single 512-bit block
// SHA256 implementation following FIPS PUB 180-4 - Secure Hash Standard (SHS)
static void sha256_process_block(SHA256_Context *ctx, const unsigned char *block) {
    uint32_t w[64];
    uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Prepare message schedule
    for (int i = 0; i < 16; i++) {
        w[i] = (block[i * 4] << 24) |
               (block[i * 4 + 1] << 16) |
               (block[i * 4 + 2] << 8) |
               (block[i * 4 + 3]);
    }

    for (int i = 16; i < 64; i++) {
        uint32_t s0 = (w[i-15] >> 7) | (w[i-15] << 25);
        s0 ^= ((w[i-15] >> 18) | (w[i-15] << 14));
        s0 ^= (w[i-15] >> 3);

        uint32_t s1 = (w[i-2] >> 17) | (w[i-2] << 15);
        s1 ^= ((w[i-2] >> 19) | (w[i-2] << 13));
        s1 ^= (w[i-2] >> 10);

        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }

    // Working variables
    uint32_t a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3];
    uint32_t e = ctx->h[4], f = ctx->h[5], g = ctx->h[6], h = ctx->h[7];

    // Main loop
    for (int i = 0; i < 64; i++) {
        uint32_t S1 = ((e >> 6) | (e << 26)) ^ ((e >> 11) | (e << 21)) ^ ((e >> 25) | (e << 7));
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + S1 + ch + k[i] + w[i];
        uint32_t S0 = ((a >> 2) | (a << 30)) ^ ((a >> 13) | (a << 19)) ^ ((a >> 22) | (a << 10));
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    // Add to hash state
    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
    ctx->h[4] += e;
    ctx->h[5] += f;
    ctx->h[6] += g;
    ctx->h[7] += h;
}

// Update context with new data
void sha256_update(SHA256_Context *ctx, const unsigned char *data, size_t len) {
    ctx->total_len += len;

    // If we have buffered data, try to fill the buffer first
    if (ctx->buffer_len > 0) {
        size_t to_copy = 64 - ctx->buffer_len;
        if (to_copy > len) to_copy = len;

        memcpy(ctx->buffer + ctx->buffer_len, data, to_copy);
        ctx->buffer_len += to_copy;
        data += to_copy;
        len -= to_copy;

        // If buffer is full, process it
        if (ctx->buffer_len == 64) {
            sha256_process_block(ctx, ctx->buffer);
            ctx->buffer_len = 0;
        }
    }

    // Process complete 64-byte blocks directly from input
    while (len >= 64) {
        sha256_process_block(ctx, data);
        data += 64;
        len -= 64;
    }

    // Buffer remaining bytes
    if (len > 0) {
        memcpy(ctx->buffer, data, len);
        ctx->buffer_len = len;
    }
}

// Finalize and produce hash
void sha256_final(SHA256_Context *ctx, unsigned char *hash) {
    // Append 1 bit (0x80 byte)
    ctx->buffer[ctx->buffer_len++] = 0x80;

    // If not enough room for length, pad and process
    if (ctx->buffer_len > 56) {
        while (ctx->buffer_len < 64) {
            ctx->buffer[ctx->buffer_len++] = 0;
        }
        sha256_process_block(ctx, ctx->buffer);
        ctx->buffer_len = 0;
    }

    // Pad with zeros until 56 bytes
    while (ctx->buffer_len < 56) {
        ctx->buffer[ctx->buffer_len++] = 0;
    }

    // Append length in bits as 64-bit big-endian
    uint64_t bit_len = ctx->total_len * 8;
    for (int i = 0; i < 8; i++) {
        ctx->buffer[56 + i] = (bit_len >> (8 * (7 - i))) & 0xff;
    }

    // Process final block
    sha256_process_block(ctx, ctx->buffer);

    // Produce final hash (big-endian)
    for (int i = 0; i < 8; i++) {
        hash[i * 4]     = (ctx->h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (ctx->h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (ctx->h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = ctx->h[i] & 0xff;
    }
}

// Simple SHA256 implementation structure (simplified for this tool)
void calculate_sha256(unsigned char *data, size_t len, unsigned char *hash) {
    SHA256_Context ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, data, len);
    sha256_final(&ctx, hash);
}

void print_hash(unsigned char *hash, int hash_len, const char *format_type) {
    if (strcmp(format_type, "sha256") == 0) {
        printf("[INFO] SHA256: ");
    } else {
        printf("[INFO] Hash: ");
    }
    
    for (int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Calculate Shannon entropy to detect packed/encrypted sections
double calculate_entropy(unsigned char *data, size_t len) {
    if (len == 0) return 0.0;
    
    // Count frequency of each byte value (0-255)
    int freq[256] = {0};
    for (size_t i = 0; i < len; i++) {
        freq[data[i]]++;
    }
    
    // Calculate entropy using Shannon's formula: -sum(p_i * log2(p_i))
    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / len;
            entropy -= p * (log(p) / log(2.0));  // log2(p) = log(p) / log(2)
        }
    }
    
    return entropy;
}



// Analyze imports for the PE file
void analyze_imports(unsigned char *buffer, DWORD *rva_to_imports, DWORD *rva_to_names, WORD machine, long file_size) {
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);

    DWORD import_dir_rva = 0;
    DWORD import_names_rva = 0;

    if (rva_to_imports) import_dir_rva = *rva_to_imports;
    if (rva_to_names) {
        import_names_rva = *rva_to_names;
        // Use the import_names_rva value if additional analysis is available
        if (verbose && import_names_rva != 0) {
            printf("[INFO] Additional import names analysis available at RVA: 0x%08X\n", import_names_rva);
        }
    }
    
    if (import_dir_rva == 0) {
        // Get import directory from data directories if not provided
        if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
            PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            import_dir_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        } else {  // 64-bit
            PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
            import_dir_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        }
    }
    
    if (import_dir_rva == 0) {
        if (verbose) printf("[INFO] No import directory found.\n");
        return;
    }
    
    // Convert RVA to file offset using helper function
    PIMAGE_SECTION_HEADER section_table;
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;
    WORD size_of_optional_header = nt_headers->FileHeader.SizeOfOptionalHeader;

    section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + size_of_optional_header);

    DWORD import_dir_offset = rva_to_file_offset(import_dir_rva, section_table, num_sections, file_size);

    if (import_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing import directory.\n");
        return;
    }
    
    PIMAGE_IMPORT_DESCRIPTOR import_desc = (PIMAGE_IMPORT_DESCRIPTOR)(buffer + import_dir_offset);
    
    printf("[IMPORTS ANALYSIS]\n");
    
    // Process each import descriptor
    int import_count = 0;
    while (import_desc->Name != 0) {
        // Convert DLL name RVA to file offset using helper function
        DWORD dll_name_offset = rva_to_file_offset(import_desc->Name, section_table, num_sections, file_size);

        if (dll_name_offset != 0) {
            const char *dll_name = (const char *)(buffer + dll_name_offset);
            printf("  Imported DLL: %s\n", dll_name);
            
            // Process imported functions from this DLL
            // Convert thunk RVAs to file offsets using helper function
            DWORD thunk_offset = rva_to_file_offset(import_desc->FirstThunk, section_table, num_sections, file_size);

            DWORD orig_thunk_rva = (import_desc->DUMMYUNIONNAME.OriginalFirstThunk != 0) ?
                                   import_desc->DUMMYUNIONNAME.OriginalFirstThunk : import_desc->FirstThunk;
            DWORD original_thunk_offset = rva_to_file_offset(orig_thunk_rva, section_table, num_sections, file_size);
            
            if (thunk_offset != 0 && original_thunk_offset != 0) {
                int func_count = 0;
                if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
                    PIMAGE_THUNK_DATA32 thunk = (PIMAGE_THUNK_DATA32)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x80000000)) {  // Not an ordinal import
                            DWORD hint_name_offset = rva_to_file_offset(thunk->u1.AddressOfData, section_table, num_sections, file_size);

                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name = (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %d\n", thunk->u1.Ordinal & 0x7FFFFFFF);
                        }
                        thunk++;
                        func_count++;
                    }
                } else {  // 64-bit
                    PIMAGE_THUNK_DATA64 thunk = (PIMAGE_THUNK_DATA64)(buffer + original_thunk_offset);
                    while (thunk->u1.AddressOfData != 0) {
                        if (!(thunk->u1.Ordinal & 0x8000000000000000ULL)) {  // Not an ordinal import
                            DWORD hint_name_offset = rva_to_file_offset((DWORD)thunk->u1.AddressOfData, section_table, num_sections, file_size);

                            if (hint_name_offset != 0) {
                                PIMAGE_IMPORT_BY_NAME hint_name = (PIMAGE_IMPORT_BY_NAME)(buffer + hint_name_offset);
                                printf("    - Function: %s (Hint: %d)\n",
                                       hint_name->Name, hint_name->Hint);
                            }
                        } else {
                            printf("    - Ordinal: %lld\n", thunk->u1.Ordinal & 0x7FFFFFFFFFFFFFFFLL);
                        }
                        thunk++;
                        func_count++;
                    }
                }
            }
        }
        
        import_desc++;
        import_count++;
    }
    
    printf("[END IMPORTS ANALYSIS - %d DLLs imported]\n\n", import_count);
}

// Analyze exports for the PE file
void analyze_exports(unsigned char *buffer, DWORD rva_to_exports, WORD machine, long file_size) {
    // Define DOS header at the beginning for access throughout
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    
    if (rva_to_exports == 0) {
        // Get export directory from data directories if not provided
        DWORD nt_headers_offset = dos_header->e_lfanew;
        PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
        
        if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
            PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
            rva_to_exports = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        } else {  // 64-bit
            PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
            rva_to_exports = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
        }
    }
    
    if (rva_to_exports == 0) {
        if (verbose) printf("[INFO] No export directory found.\n");
        return;
    }
    
    // Convert RVA to file offset using helper function
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
    PIMAGE_SECTION_HEADER section_table;
    WORD num_sections = nt_headers->FileHeader.NumberOfSections;
    WORD size_of_optional_header = nt_headers->FileHeader.SizeOfOptionalHeader;

    section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + size_of_optional_header);

    DWORD export_dir_offset = rva_to_file_offset(rva_to_exports, section_table, num_sections, file_size);

    if (export_dir_offset == 0) {
        if (verbose) printf("[WARNING] Could not find section containing export directory.\n");
        return;
    }

    PIMAGE_EXPORT_DIRECTORY export_dir = (PIMAGE_EXPORT_DIRECTORY)(buffer + export_dir_offset);

    // Get the name of the DLL (export name)
    DWORD name_offset = rva_to_file_offset(export_dir->Name, section_table, num_sections, file_size);

    const char *dll_name = "Unknown";
    if (name_offset != 0) {
        dll_name = (const char *)(buffer + name_offset);
    }
    
    printf("[EXPORTS ANALYSIS - %s]\n", dll_name);
    printf("  Base Ordinal: %d\n", export_dir->Base);
    printf("  Number of Functions: %d\n", export_dir->NumberOfFunctions);
    printf("  Number of Names: %d\n", export_dir->NumberOfNames);
    
    // Print function names if available
    if (export_dir->NumberOfNames > 0 && export_dir->AddressOfNames != 0) {
        // Convert AddressOfNames RVA to file offset using helper function
        DWORD name_array_offset = rva_to_file_offset(export_dir->AddressOfNames, section_table, num_sections, file_size);

        if (name_array_offset != 0) {
            DWORD *name_rvas = (DWORD *)(buffer + name_array_offset);

            for (DWORD i = 0; i < export_dir->NumberOfNames; i++) {
                DWORD name_rva = name_rvas[i];

                // Convert function name RVA to file offset using helper function
                DWORD func_name_offset = rva_to_file_offset(name_rva, section_table, num_sections, file_size);

                if (func_name_offset != 0) {
                    const char *func_name = (const char *)(buffer + func_name_offset);
                    printf("    - Function: %s\n", func_name);
                }
            }
        }
    }
    
    printf("[END EXPORTS ANALYSIS]\n\n");
}



// Function to add a file to the input list for batch processing
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

    input_files[num_input_files] = my_strdup(file_path);
    if (!input_files[num_input_files]) {
        fprintf(stderr, "[-] Error: Memory allocation failed for input file path.\n");
        return 1;
    }
    num_input_files++;

    return 0;
}

// Interactive section selection - show available sections and let user choose
int interactive_section_selection(PIMAGE_SECTION_HEADER *sections, size_t num_sections) {
    if (num_sections == 0) {
        printf("[!] No executable sections available to select.\n");
        return 0; // No sections to process
    }
    
    printf("\nFound %zu executable sections:\n", num_sections);
    for (size_t i = 0; i < num_sections; i++) {
        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
        memcpy(section_name, sections[i]->Name, IMAGE_SIZEOF_SHORT_NAME);
        section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';
        
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
    size_t selections_made = 0;  // Track if any valid selections were made
    while (token != NULL) {
        // Skip empty tokens
        if (strlen(token) == 0) {
            token = strtok(NULL, ", \n");
            continue;
        }

        char *endptr;
        long section_num = strtol(token, &endptr, 10);

        if (*endptr != '\0' || section_num < 1 || section_num > (long)num_sections) {
            printf("[!] Invalid section number: %s\n", token);
        } else {
            // Add this section to include list
            char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
            memcpy(section_name, sections[section_num - 1]->Name, IMAGE_SIZEOF_SHORT_NAME);
            section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';

            // Add to include sections filter
            char **temp_include = (char **)realloc(include_sections, (include_count + 1) * sizeof(char *));
            if (!temp_include) {
                fprintf(stderr, "[-] Error: Memory allocation failed for section filter.\n");
                return -1;
            }
            include_sections = temp_include;

            include_sections[include_count] = my_strdup(section_name);
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
            selections_made++;
        }

        token = strtok(NULL, ", \n");
    }

    // If no valid selections were made, return 0 to indicate no sections selected
    if (selections_made == 0) {
        return 0;
    }

    return 1; // Process with selected filters
}

// Combined function to print import/export summary
void print_imports_exports_summary(unsigned char *buffer, WORD machine, long file_size) {
    // Get import/export directory RVAs
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
    DWORD nt_headers_offset = dos_header->e_lfanew;
    PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
    
    DWORD import_rva = 0, export_rva = 0;
    
    if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
        PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
        import_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = opt_header->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    } else {  // 64-bit
        PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
        import_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
        export_rva = nt_headers64->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
    }
    
    if (import_rva != 0) {
        analyze_imports(buffer, &import_rva, NULL, machine, file_size);
    }
    
    if (export_rva != 0) {
        analyze_exports(buffer, export_rva, machine, file_size);
    }
    
    if (import_rva == 0 && export_rva == 0) {
        printf("[INFO] No import or export tables found in this PE file.\n");
    }
}





// Detect overlapping sections and calculate total size
int detect_overlaps_and_calculate_size(PIMAGE_SECTION_HEADER *valid_sections,
                                       size_t num_valid_sections, size_t *total_shellcode_size) {
    // Create a copy of the sections array to sort without modifying the original
    PIMAGE_SECTION_HEADER *sorted_sections = (PIMAGE_SECTION_HEADER *)malloc(num_valid_sections * sizeof(PIMAGE_SECTION_HEADER));
    if (!sorted_sections) {
        fprintf(stderr, "[-] Error: Memory allocation failed for section sorting.\n");
        return 1;
    }

    // Copy pointers to the new array
    for (size_t i = 0; i < num_valid_sections; i++) {
        sorted_sections[i] = valid_sections[i];
    }

    // Sort the copy by raw data address to ensure proper overlap detection
    qsort(sorted_sections, num_valid_sections, sizeof(PIMAGE_SECTION_HEADER), compare_sections);

    *total_shellcode_size = 0;
    DWORD last_section_end = 0;
    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = sorted_sections[i];

        // Check for potential integer overflows in section bounds
        if (section->PointerToRawData > UINT32_MAX - section->SizeOfRawData) {
            fprintf(stderr, "[-] Error: Section extends beyond addressable space.\n");
            free(sorted_sections);
            return 1;
        }

        if (section->PointerToRawData < last_section_end) {
            fprintf(stdout, "[!] Warning: Skipping overlapping section '%.8s'.\n", (char*)section->Name);
            continue;
        }

        // Integer overflow protection for size calculation
        if (section->SizeOfRawData > SIZE_MAX - *total_shellcode_size) {
            fprintf(stderr, "[-] Error: Size calculation would overflow.\n");
            free(sorted_sections);
            return 1;
        }

        *total_shellcode_size += section->SizeOfRawData;
        last_section_end = section->PointerToRawData + section->SizeOfRawData;
    }

    free(sorted_sections);

    if (*total_shellcode_size == 0) {
        fprintf(stdout, "[!] Warning: All executable sections were overlapping or empty.\n");
        return 0;  // Not an error, just no executable code was extracted
    }
    
    return 0;  // Success
}

// Main extraction logic
int extract_shellcode(const char *input_path, const char *output_path) {
    PE_Context ctx;
    if (initialize_pe_context(input_path, &ctx) != 0) {
        return 1;
    }

    PIMAGE_SECTION_HEADER *valid_sections = NULL;
    size_t num_valid_sections = 0;

    // Find executable sections using the PE Context
    if (find_executable_sections(&ctx, &valid_sections, &num_valid_sections) != 0) {
        cleanup_pe_context(&ctx);
        return 1;
    }

    if (num_valid_sections == 0) {
        fprintf(stdout, "[!] Warning: No executable sections found.\n");
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return 0;  // Not an error, just no executable code found
    }

    // Create a sorted copy of sections for overlap detection
    PIMAGE_SECTION_HEADER *sorted_sections = (PIMAGE_SECTION_HEADER *)malloc(num_valid_sections * sizeof(PIMAGE_SECTION_HEADER));
    if (!sorted_sections) {
        fprintf(stderr, "[-] Error: Memory allocation failed for section sorting.\n");
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return 1;
    }

    // Copy the section pointers for sorting
    for (size_t i = 0; i < num_valid_sections; i++) {
        sorted_sections[i] = valid_sections[i];
    }

    // Sort the copy by raw data address to ensure proper overlap detection
    qsort(sorted_sections, num_valid_sections, sizeof(PIMAGE_SECTION_HEADER), compare_sections);

    // First pass: calculate total size of non-overlapping sections using sorted order
    size_t total_shellcode_size = 0;
    DWORD last_section_end = 0;
    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = sorted_sections[i];

        // Check for potential integer overflows in section bounds
        if (section->PointerToRawData > UINT32_MAX - section->SizeOfRawData) {
            fprintf(stderr, "[-] Error: Section extends beyond addressable space.\n");
            free(sorted_sections);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return 1;
        }

        if (section->PointerToRawData < last_section_end) {
            fprintf(stdout, "[!] Warning: Skipping overlapping section '%.8s'.\n", (char*)section->Name);
            continue;
        }

        // Integer overflow protection for size calculation
        if (section->SizeOfRawData > SIZE_MAX - total_shellcode_size) {
            fprintf(stderr, "[-] Error: Size calculation would overflow.\n");
            free(sorted_sections);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return 1;
        }

        total_shellcode_size += section->SizeOfRawData;
        last_section_end = section->PointerToRawData + section->SizeOfRawData;
    }

    // Free the sorted copy as we no longer need it for size calculation
    free(sorted_sections);

    if (total_shellcode_size == 0) {
        fprintf(stdout, "[!] Warning: All executable sections were overlapping or empty.\n");
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return 0;  // Not an error, just no executable code was extracted
    }

    unsigned char *output_buffer = (unsigned char *)malloc(total_shellcode_size);
    if (!output_buffer) {
        fprintf(stderr, "[-] Error: Memory allocation failed for output buffer.\n");
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return 1;
    }

    // Create another sorted copy for the second pass (actual data copying)
    PIMAGE_SECTION_HEADER *copy_sections = (PIMAGE_SECTION_HEADER *)malloc(num_valid_sections * sizeof(PIMAGE_SECTION_HEADER));
    if (!copy_sections) {
        fprintf(stderr, "[-] Error: Memory allocation failed for section copying.\n");
        free(output_buffer);
        free(valid_sections);
        cleanup_pe_context(&ctx);
        return 1;
    }

    // Copy the section pointers again for the copying phase
    for (size_t i = 0; i < num_valid_sections; i++) {
        copy_sections[i] = valid_sections[i];
    }

    // Sort for copying in the correct order to maintain proper sequencing
    qsort(copy_sections, num_valid_sections, sizeof(PIMAGE_SECTION_HEADER), compare_sections);

    // Second pass: copy section data to the output buffer
    size_t current_pos = 0;
    last_section_end = 0;

    // Show progress if enabled and file is large enough to warrant it
    if (show_progress && total_shellcode_size > 1024 * 1024) {  // Only for files > 1MB
        printf("[*] Progress: 0%%\r");
        fflush(stdout);
    }

    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = copy_sections[i];
        if (section->PointerToRawData < last_section_end) {
            continue; // Skip overlapping sections that were detected in first pass
        }

        // Integer overflow protection for position calculation
        if (section->SizeOfRawData > SIZE_MAX - current_pos) {
            fprintf(stderr, "[-] Error: Position calculation would overflow.\n");
            free(copy_sections);
            free(output_buffer);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return 1;
        }

        memcpy(output_buffer + current_pos, ctx.buffer + section->PointerToRawData, section->SizeOfRawData);
        current_pos += section->SizeOfRawData;
        last_section_end = section->PointerToRawData + section->SizeOfRawData;

        // Show progress if enabled
        if (show_progress && total_shellcode_size > 1024 * 1024) {  // Only for files > 1MB
            int progress_percent = (int)((current_pos * 100) / total_shellcode_size);
            printf("[*] Progress: %d%%\r", progress_percent);
            fflush(stdout);
        }
    }

    // Free the copy used for data copying
    free(copy_sections);

    // Final progress update
    if (show_progress && total_shellcode_size > 1024 * 1024) {
        printf("[*] Progress: 100%%\n");
    }

    // Handle different output formats
    if (output_format == OUTPUT_BINARY) {
        FILE *out_f = fopen(output_path, "wb");
        if (!out_f) {
            fprintf(stderr, "[-] Error: Failed to open output file '%s'.\n", output_path);
            free(output_buffer);
            free(valid_sections);
            cleanup_pe_context(&ctx);
            return 1;
        }

        fwrite(output_buffer, 1, current_pos, out_f);
        fclose(out_f);

        // Calculate and print hash if requested
        if (include_hash) {
            unsigned char hash[32];  // For SHA256
            calculate_sha256(output_buffer, current_pos, hash);
            print_hash(hash, 32, "sha256");
        }

        printf("[+] Success: Extracted %zu bytes from %zu sections to '%s'.\n", current_pos, num_valid_sections, output_path);
    } else {
        // For non-binary formats, we don't write to a file but output to stdout
        // Extract the base filename without extension for C arrays
        char base_filename[256];
        const char *p = strrchr(output_path, '/');
        if (!p) p = strrchr(output_path, '\\');
        if (!p) p = output_path - 1;  // Start from beginning if no path separator
        else p++;  // Skip the separator
        strncpy(base_filename, p, sizeof(base_filename) - 1);
        base_filename[sizeof(base_filename) - 1] = '\0';

        // Remove extension if present
        char *ext = strrchr(base_filename, '.');
        if (ext) *ext = '\0';

        // Replace hyphens with underscores for C compatibility
        for (int i = 0; base_filename[i]; i++) {
            if (base_filename[i] == '-') base_filename[i] = '_';
        }

        switch (output_format) {
            case OUTPUT_C_ARRAY:
                output_as_c_array(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_PYTHON:
                output_as_python(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_HEX_DUMP:
                output_as_hex_dump(output_buffer, current_pos, base_filename);
                break;
            case OUTPUT_JSON:
                // For JSON, we need to pass additional metadata
                output_as_json(output_buffer, current_pos, input_path, valid_sections, num_valid_sections,
                               ctx.entry_point_rva, ctx.machine);
                break;
            default:
                fprintf(stderr, "[-] Error: Unknown output format\n");
                free(output_buffer);
                free(valid_sections);
                cleanup_pe_context(&ctx);
                return 1;
        }

        printf("[+] Success: Extracted %zu bytes from %zu sections (output as %s format).\n",
               current_pos, num_valid_sections,
               output_format == OUTPUT_C_ARRAY ? "C array" :
               output_format == OUTPUT_PYTHON ? "Python" :
               output_format == OUTPUT_HEX_DUMP ? "hex dump" :
               output_format == OUTPUT_JSON ? "json" : "unknown");

        // Calculate and print hash if requested
        if (include_hash) {
            unsigned char hash[32];  // For SHA256
            calculate_sha256(output_buffer, current_pos, hash);
            print_hash(hash, 32, "sha256");
        }
    }

    // Perform import/export analysis if requested
    if (analyze_imports_exports) {
        print_imports_exports_summary(ctx.buffer, ctx.machine, ctx.file_size);
    }

    free(output_buffer);
    free(valid_sections);
    cleanup_pe_context(&ctx);

    return 0;
}

// Parse command-line arguments
int parse_arguments(int argc, char **argv, const char **input_path, const char **output_path) {
    *input_path = NULL;
    *output_path = NULL;

    // Track which arguments are options to distinguish from file arguments
    // Use heap allocation to avoid VLA stack overflow risk
    #define MAX_ARGS 10000
    if (argc < 1 || argc > MAX_ARGS) {
        fprintf(stderr, "[-] Error: Invalid argument count (max %d)\n", MAX_ARGS);
        return 1;
    }

    int *arg_processed = (int *)calloc(argc, sizeof(int));
    if (!arg_processed) {
        fprintf(stderr, "[-] Error: Memory allocation failed for argument processing\n");
        return 1;
    }
    arg_processed[0] = 1;  // Program name is always processed

    // Parse options first
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && !arg_processed[i]) {
            arg_processed[i] = 1;  // Mark this as processed
            if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
                verbose = 1;
            } else if (strcmp(argv[i], "--section") == 0 || strcmp(argv[i], "-s") == 0) {
                // Parse next argument as comma-separated list of section names to include
                i++;
                if (i >= argc) {
                    fprintf(stderr, "[-] Error: --section requires an argument\n");
                    free(arg_processed);
                    return 1;
                }
                arg_processed[i] = 1;  // Mark the argument as processed too
                // Parse comma-separated list of section names to include
                char **temp_include = NULL;
                size_t temp_count = 0;

                if (parse_section_name(argv[i], &temp_include, &temp_count) != 0) {
                    fprintf(stderr, "[-] Error: Failed to parse section list: %s\n", argv[i]);
                    free(arg_processed);
                    return 1;
                }

                // Add to the main include array
                include_sections = (char **)realloc(include_sections, (include_count + temp_count) * sizeof(char *));
                if (!include_sections) {
                    fprintf(stderr, "[-] Error: Memory allocation failed for include sections filter\n");
                    for (size_t j = 0; j < temp_count; j++) {
                        free(temp_include[j]);
                    }
                    free(temp_include);
                    free(arg_processed);
                    return 1;
                }

                for (size_t j = 0; j < temp_count; j++) {
                    include_sections[include_count + j] = temp_include[j];
                }
                include_count += temp_count;
                free(temp_include);
            } else if (strcmp(argv[i], "--exclude") == 0) {
                // Parse next argument as comma-separated list of section names to exclude
                i++;
                if (i >= argc) {
                    fprintf(stderr, "[-] Error: --exclude requires an argument\n");
                    free(arg_processed);
                    return 1;
                }
                arg_processed[i] = 1;  // Mark the argument as processed too
                // Parse comma-separated list of section names to exclude
                char **temp_exclude = NULL;
                size_t temp_count = 0;

                if (parse_section_name(argv[i], &temp_exclude, &temp_count) != 0) {
                    fprintf(stderr, "[-] Error: Failed to parse section list: %s\n", argv[i]);
                    free(arg_processed);
                    return 1;
                }

                // Add to the main exclude array
                exclude_sections = (char **)realloc(exclude_sections, (exclude_count + temp_count) * sizeof(char *));
                if (!exclude_sections) {
                    fprintf(stderr, "[-] Error: Memory allocation failed for exclude sections filter\n");
                    for (size_t j = 0; j < temp_count; j++) {
                        free(temp_exclude[j]);
                    }
                    free(temp_exclude);
                    free(arg_processed);
                    return 1;
                }

                for (size_t j = 0; j < temp_count; j++) {
                    exclude_sections[exclude_count + j] = temp_exclude[j];
                }
                exclude_count += temp_count;
                free(temp_exclude);
            } else if (strcmp(argv[i], "--min-size") == 0) {
                // Parse next argument as minimum section size
                i++;
                if (i >= argc) {
                    fprintf(stderr, "[-] Error: --min-size requires an argument\n");
                    free(arg_processed);
                    return 1;
                }
                arg_processed[i] = 1;  // Mark the argument as processed too
                char *endptr;
                errno = 0;  // Reset errno to detect errors
                unsigned long long_val = strtoul(argv[i], &endptr, 10);

                // Check if conversion was successful
                if (*endptr != '\0') {
                    fprintf(stderr, "[-] Error: Invalid number for --min-size: %s\n", argv[i]);
                    free(arg_processed);
                    return 1;
                }

                // Check for overflow and clamp to DWORD
                if (errno == ERANGE || long_val > UINT32_MAX) {
                    fprintf(stderr, "[-] Error: --min-size value too large: %s\n", argv[i]);
                    free(arg_processed);
                    return 1;
                }

                // Clamp to 0 if underflow (though unsigned long doesn't underflow, it's good practice)
                min_section_size = (DWORD)long_val;
            } else if (strcmp(argv[i], "--dry-run") == 0) {
                dry_run = 1;
            } else if (strcmp(argv[i], "--hash") == 0 || strcmp(argv[i], "--include-hash") == 0) {
                include_hash = 1;
            } else if (strcmp(argv[i], "--entropy") == 0 || strcmp(argv[i], "--include-entropy") == 0) {
                include_entropy = 1;
            } else if (strcmp(argv[i], "--imports") == 0 || strcmp(argv[i], "--exports") == 0 || strcmp(argv[i], "--analyze-imports-exports") == 0) {
                analyze_imports_exports = 1;
            } else if (strcmp(argv[i], "--batch") == 0) {
                batch_mode = 1;
            } else if (strcmp(argv[i], "--interactive") == 0 || strcmp(argv[i], "-i") == 0) {
                interactive_mode = 1;
            } else if (strcmp(argv[i], "--progress") == 0) {
                show_progress = 1;
            } else if (strcmp(argv[i], "--output-dir") == 0 || strcmp(argv[i], "--outdir") == 0) {
                // Parse next argument as output directory
                i++;
                if (i >= argc) {
                    fprintf(stderr, "[-] Error: --output-dir requires an argument\n");
                    free(arg_processed);
                    return 1;
                }
                arg_processed[i] = 1;  // Mark the argument as processed too
                batch_output_dir = argv[i];
            } else if (strcmp(argv[i], "--format") == 0 || strcmp(argv[i], "-f") == 0) {
                // Parse next argument as output format
                i++;
                if (i >= argc) {
                    fprintf(stderr, "[-] Error: --format requires an argument (binary, c, python, hex)\n");
                    free(arg_processed);
                    return 1;
                }
                arg_processed[i] = 1;  // Mark the argument as processed too
                if (strcmp(argv[i], "binary") == 0) {
                    output_format = OUTPUT_BINARY;
                } else if (strcmp(argv[i], "c") == 0 || strcmp(argv[i], "c-array") == 0) {
                    output_format = OUTPUT_C_ARRAY;
                } else if (strcmp(argv[i], "python") == 0) {
                    output_format = OUTPUT_PYTHON;
                } else if (strcmp(argv[i], "hex") == 0 || strcmp(argv[i], "hex-dump") == 0) {
                    output_format = OUTPUT_HEX_DUMP;
                } else if (strcmp(argv[i], "json") == 0) {
                    output_format = OUTPUT_JSON;
                } else {
                    fprintf(stderr, "[-] Error: Unknown output format: %s (use binary, c, python, hex, or json)\n", argv[i]);
                    free(arg_processed);
                    return 1;
                }
            } else if (strcmp(argv[i], "--help") == 0) {
                fprintf(stderr, "PE Shellcode Extractor\n");
                fprintf(stderr, "Usage: %s [options] <input.exe> <output.bin>\n", argv[0]);
                fprintf(stderr, "Options:\n");
                fprintf(stderr, "  -v, --verbose    Enable verbose output\n");
                fprintf(stderr, "  -s, --section    Include specific section (e.g., -s .text)\n");
                fprintf(stderr, "  --exclude        Exclude specific section (e.g., --exclude .rsrc)\n");
                fprintf(stderr, "  --min-size       Minimum section size to include (in bytes)\n");
                fprintf(stderr, "  -f, --format     Output format: binary, c, python, hex, json (default: binary)\n");
                fprintf(stderr, "  --hash           Include hash (SHA256) of extracted code in output\n");
                fprintf(stderr, "  --entropy        Include entropy calculation of sections\n");
                fprintf(stderr, "  --imports        Analyze import table (DLLs and functions imported)\n");
                fprintf(stderr, "  --batch          Enable batch processing mode for multiple files\n");
                fprintf(stderr, "  --interactive, -i  Enable interactive section selection mode\n");
                fprintf(stderr, "  --progress       Show progress indicator for large files\n");
                fprintf(stderr, "  --output-dir     Directory for output files (for batch mode)\n");
                fprintf(stderr, "  --dry-run        Analyze only, don't extract\n");
                fprintf(stderr, "  --help           Show this help message\n");
                free(arg_processed);
                return -1;  // Special return to indicate help was shown
            } else {
                fprintf(stderr, "Unknown option: %s\n", argv[i]);
                fprintf(stderr, "Use --help for usage information.\n");
                free(arg_processed);
                return 1;
            }
        }
    }

    // Handle batch mode vs single file mode
    if (batch_mode) {
        // In batch mode, treat all unprocessed arguments as input files
        for (int i = 1; i < argc; i++) {
            if (!arg_processed[i]) {
                if (add_input_file(argv[i]) != 0) {
                    free(arg_processed);
                    return 1;  // Error already reported
                }
            }
        }

        // Verify we have at least one input file for batch processing
        if (num_input_files == 0) {
            fprintf(stderr, "PE Shellcode Extractor\n");
            fprintf(stderr, "Usage: %s --batch [options] <input1.exe> [input2.exe ...] [--output-dir directory]\n", argv[0]);
            fprintf(stderr, "Use --help for more options.\n");
            free(arg_processed);
            return 1;
        }
    } else {
        // Single file mode (existing behavior)
        int file_args_count = 0;
        for (int i = 1; i < argc; i++) {
            if (!arg_processed[i]) {
                if (file_args_count == 0) {
                    *input_path = argv[i];
                } else if (file_args_count == 1) {
                    *output_path = argv[i];
                }
                file_args_count++;
            }
        }

        if (output_format == OUTPUT_BINARY) {
            if (file_args_count == 0) {
                // No input file provided
                fprintf(stderr, "PE Shellcode Extractor\n");
                fprintf(stderr, "Usage: %s [options] <input.exe> [output.bin]\n", argv[0]);
                fprintf(stderr, "Use --help for more options.\n");
                free(arg_processed);
                return 1;
            } else if (file_args_count == 1) {
                // Only input file provided - will handle default output path in main processing
                // Set a marker that we need default output path
                *output_path = NULL;  // Signal that we need to generate a default path
            } else if (file_args_count == 2) {
                // Both input and output files provided - normal case
            } else {
                // Too many file arguments
                fprintf(stderr, "PE Shellcode Extractor\n");
                fprintf(stderr, "Usage: %s [options] <input.exe> [output.bin]\n", argv[0]);
                fprintf(stderr, "Use --help for more options.\n");
                free(arg_processed);
                return 1;
            }
        } else {
            // Non-binary formats can work with just input file (output to stdout)
            if (file_args_count == 0) {
                fprintf(stderr, "PE Shellcode Extractor\n");
                fprintf(stderr, "Usage: %s [options] <input.exe> [output_name]\n", argv[0]);
                fprintf(stderr, "Use --help for more options.\n");
                free(arg_processed);
                return 1;
            }
            // If only input file provided for non-binary format, set output_path to a default name
            if (file_args_count == 1) {
                *output_path = "shellcode";
            }
        }
    }

    free(arg_processed);
    return 0;  // Success
}

int main(int argc, char **argv) {
    // Register global cleanup function to run on exit
    atexit(cleanup_all);

    const char *input_path = NULL;
    const char *output_path = NULL;

    int result = parse_arguments(argc, argv, &input_path, &output_path);
    if (result != 0) {
        // No need to call free_section_filters() as cleanup_all() will be called via atexit()
        return (result == -1) ? 0 : 1;  // Return 0 for help, 1 for error
    }

    if (batch_mode) {
        // Process each input file in batch mode
        for (int i = 0; i < num_input_files; i++) {
            printf("[*] Processing file %d/%d: %s\n", i + 1, num_input_files, input_files[i]);
            
            // Determine output path for this file
            char output_file_path[1024];
            if (batch_output_dir) {
                // Use output directory with original filename
                const char *filename = strrchr(input_files[i], '/');
                if (!filename) filename = strrchr(input_files[i], '\\');
                if (!filename) filename = input_files[i];
                else filename++; // Skip the slash
                
                snprintf(output_file_path, sizeof(output_file_path), "%s/%s_shellcode.bin", 
                        batch_output_dir, filename);
            } else {
                // Use same directory as input file but with _shellcode suffix
                char *temp_path = my_strdup(input_files[i]);
                char *ext = strrchr(temp_path, '.');
                if (ext) *ext = '\0';  // Remove extension
                snprintf(output_file_path, sizeof(output_file_path), "%s_shellcode.bin", temp_path);
                free(temp_path);
            }

            // Process this specific file
            if (dry_run) {
                printf("[*] Dry-run mode: Analyzing PE file '%s' without extracting\n", input_files[i]);
                unsigned char *buffer = NULL;
                long file_size = 0;
                DWORD entry_point_rva = 0;
                WORD machine;

                // Load and validate the file
                FILE *f = fopen(input_files[i], "rb");
                if (!f) {
                    fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_files[i]);
                    continue;  // Continue with next file
                }

                if (validate_pe_structure(f, &buffer, &file_size) != 0) {
                    continue;  // Error message already printed by validate_pe_structure
                }

                // Load the file again since validate_pe_structure closed it
                f = fopen(input_files[i], "rb");
                if (!f) {
                    fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_files[i]);
                    free(buffer);
                    continue;
                }

                fseek(f, 0, SEEK_SET);
                if (fread(buffer, 1, file_size, f) != (size_t)file_size) {
                    fprintf(stderr, "[-] Error: Failed to read input file.\n");
                    fclose(f);
                    free(buffer);
                    continue;
                }
                fclose(f);

                // Get machine type
                PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
                DWORD nt_headers_offset = dos_header->e_lfanew;
                PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
                machine = nt_headers->FileHeader.Machine;

                // Find executable sections
                PIMAGE_SECTION_HEADER *valid_sections = NULL;
                size_t num_valid_sections = 0;
                // Create temporary PE context for this function call
                PE_Context temp_ctx;
                memset(&temp_ctx, 0, sizeof(PE_Context));
                temp_ctx.buffer = buffer;
                temp_ctx.file_size = file_size;
                temp_ctx.dos_header = dos_header;
                temp_ctx.nt_headers = nt_headers;
                temp_ctx.machine = machine;
                temp_ctx.entry_point_rva = entry_point_rva;  // entry point already set earlier
                temp_ctx.section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + nt_headers->FileHeader.SizeOfOptionalHeader);
                temp_ctx.num_sections = nt_headers->FileHeader.NumberOfSections;

                result = find_executable_sections(&temp_ctx, &valid_sections, &num_valid_sections);

                if (result == 0) {
                    printf("[+] Found %zu executable sections to extract:\n", num_valid_sections);
                    for (size_t j = 0; j < num_valid_sections; j++) {
                        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
                        memcpy(section_name, valid_sections[j]->Name, IMAGE_SIZEOF_SHORT_NAME);
                        section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';
                        printf("  - Section '%s': %u bytes at offset 0x%X\n",
                               section_name, valid_sections[j]->SizeOfRawData, valid_sections[j]->PointerToRawData);
                    }

                    // Calculate total size
                    size_t total_size = 0;
                    for (size_t j = 0; j < num_valid_sections; j++) {
                        total_size += valid_sections[j]->SizeOfRawData;
                    }
                    printf("[+] Total shellcode size: %zu bytes\n", total_size);
                }

                // Cleanup
                if (valid_sections) free(valid_sections);
                free(buffer);
            } else {
                // Process the file normally with extraction
                result = extract_shellcode(input_files[i], output_file_path);
                if (result != 0) {
                    printf("[-] Failed to process file: %s\n", input_files[i]);
                    // Continue with next file instead of exiting
                    continue;
                }
            }
        }
        
        // Free batch input files and return
        for (int i = 0; i < num_input_files; i++) {
            free(input_files[i]);
        }
        free(input_files);
        free_section_filters();
        return 0;
    } else {
        // Single file mode - existing behavior
        // Check for dry-run mode
        if (dry_run) {
            printf("[*] Dry-run mode: Analyzing PE file '%s' without extracting\n", input_path);
            unsigned char *buffer = NULL;
            long file_size = 0;
            DWORD entry_point_rva = 0;
            WORD machine;

            // Load and validate the file
            FILE *f = fopen(input_path, "rb");
            if (!f) {
                fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_path);
                free_section_filters();
                return 1;
            }

            if (validate_pe_structure(f, &buffer, &file_size) != 0) {
                free_section_filters();
                return 1;  // Error message already printed by validate_pe_structure
            }

            // Load the file again since validate_pe_structure closed it
            f = fopen(input_path, "rb");
            if (!f) {
                fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_path);
                free(buffer);
                free_section_filters();
                return 1;
            }

            fseek(f, 0, SEEK_SET);
            if (fread(buffer, 1, file_size, f) != (size_t)file_size) {
                fprintf(stderr, "[-] Error: Failed to read input file.\n");
                fclose(f);
                free(buffer);
                free_section_filters();
                return 1;
            }
            fclose(f);

            // Get machine type
            PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
            DWORD nt_headers_offset = dos_header->e_lfanew;
            PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
            machine = nt_headers->FileHeader.Machine;

            // Find executable sections
            PIMAGE_SECTION_HEADER *valid_sections = NULL;
            size_t num_valid_sections = 0;
            // Create temporary PE context for this function call
            PE_Context temp_ctx;
            memset(&temp_ctx, 0, sizeof(PE_Context));
            temp_ctx.buffer = buffer;
            temp_ctx.file_size = file_size;
            temp_ctx.dos_header = dos_header;
            temp_ctx.nt_headers = nt_headers;
            temp_ctx.machine = machine;
            temp_ctx.entry_point_rva = entry_point_rva;  // entry point already set earlier
            temp_ctx.section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + nt_headers->FileHeader.SizeOfOptionalHeader);
            temp_ctx.num_sections = nt_headers->FileHeader.NumberOfSections;

            result = find_executable_sections(&temp_ctx, &valid_sections, &num_valid_sections);

            if (result == 0) {
                printf("[+] Found %zu executable sections to extract:\n", num_valid_sections);
                for (size_t i = 0; i < num_valid_sections; i++) {
                    char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
                    memcpy(section_name, valid_sections[i]->Name, IMAGE_SIZEOF_SHORT_NAME);
                    section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';
                    printf("  - Section '%s': %u bytes at offset 0x%X\n",
                           section_name, valid_sections[i]->SizeOfRawData, valid_sections[i]->PointerToRawData);
                }

                // Calculate total size
                size_t total_size = 0;
                for (size_t i = 0; i < num_valid_sections; i++) {
                    total_size += valid_sections[i]->SizeOfRawData;
                }
                printf("[+] Total shellcode size: %zu bytes\n", total_size);
            }

            // Cleanup
            if (valid_sections) free(valid_sections);
            free(buffer);
            free_section_filters();
            return result;
        } else {
            if (interactive_mode) {
                // In interactive mode, first analyze file to show available sections
                printf("[*] Interactive mode: Analyzing sections for selection...\n");
                
                // Load and validate the file
                FILE *f = fopen(input_path, "rb");
                if (!f) {
                    fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_path);
                    free_section_filters();
                    return 1;
                }

                unsigned char *buffer = NULL;
                long file_size = 0;
                if (validate_pe_structure(f, &buffer, &file_size) != 0) {
                    free_section_filters();
                    return 1;  // Error message already printed by validate_pe_structure
                }

                // Load the file again since validate_pe_structure closed it
                f = fopen(input_path, "rb");
                if (!f) {
                    fprintf(stderr, "[-] Error: Failed to open input file '%s'.\n", input_path);
                    free(buffer);
                    free_section_filters();
                    return 1;
                }

                fseek(f, 0, SEEK_SET);
                if (fread(buffer, 1, file_size, f) != (size_t)file_size) {
                    fprintf(stderr, "[-] Error: Failed to read input file.\n");
                    fclose(f);
                    free(buffer);
                    free_section_filters();
                    return 1;
                }
                fclose(f);

                // Get machine type
                PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)buffer;
                DWORD nt_headers_offset = dos_header->e_lfanew;
                PIMAGE_NT_HEADERS32 nt_headers = (PIMAGE_NT_HEADERS32)(buffer + nt_headers_offset);
                WORD machine = nt_headers->FileHeader.Machine;

                // Find executable sections
                PIMAGE_SECTION_HEADER *valid_sections = NULL;
                size_t num_valid_sections = 0;

                // Create temporary PE context for this function call
                PE_Context temp_ctx;
                memset(&temp_ctx, 0, sizeof(PE_Context));
                temp_ctx.buffer = buffer;
                temp_ctx.file_size = file_size;
                temp_ctx.dos_header = dos_header;
                temp_ctx.nt_headers = nt_headers;
                temp_ctx.machine = machine;

                // Calculate and store entry point RVA to avoid unused variable warning
                DWORD entry_point_rva = 0;
                if (machine == IMAGE_FILE_MACHINE_I386) {  // 32-bit
                    PIMAGE_OPTIONAL_HEADER32 opt_header = (PIMAGE_OPTIONAL_HEADER32)&nt_headers->OptionalHeader;
                    entry_point_rva = opt_header->AddressOfEntryPoint;
                    temp_ctx.entry_point_rva = opt_header->AddressOfEntryPoint;
                } else {  // 64-bit
                    PIMAGE_NT_HEADERS64 nt_headers64 = (PIMAGE_NT_HEADERS64)nt_headers;
                    entry_point_rva = nt_headers64->OptionalHeader.AddressOfEntryPoint;
                    temp_ctx.entry_point_rva = nt_headers64->OptionalHeader.AddressOfEntryPoint;
                }

                // Actually use the entry_point_rva to satisfy the compiler
                if (verbose && entry_point_rva != 0) {
                    printf("[INFO] Entry point RVA: 0x%08X\n", entry_point_rva);
                }
                temp_ctx.section_table = (PIMAGE_SECTION_HEADER)((BYTE *)nt_headers + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + nt_headers->FileHeader.SizeOfOptionalHeader);
                temp_ctx.num_sections = nt_headers->FileHeader.NumberOfSections;

                result = find_executable_sections(&temp_ctx, &valid_sections, &num_valid_sections);

                if (result != 0) {
                    free(buffer);
                    free_section_filters();
                    return result;
                }

                // Show available sections and get user selection
                result = interactive_section_selection(valid_sections, num_valid_sections);

                if (result < 0) {
                    // Error in interactive selection
                    if (valid_sections) free(valid_sections);
                    free(buffer);
                    free_section_filters();
                    return 1;
                } else if (result == 0) {
                    // User selected no sections
                    fprintf(stderr, "[-] Error: No sections selected for extraction.\n");
                    if (valid_sections) free(valid_sections);
                    free(buffer);
                    free_section_filters();
                    return 1;  // Return error code instead of 0, as no extraction occurred
                }

                // Cleanup analysis data, keep filters
                if (valid_sections) free(valid_sections);
                free(buffer);
            }
            
            // For binary output format, if no output path was specified, generate a default
            if (output_format == OUTPUT_BINARY && output_path == NULL) {
                // Generate default output path as input + ".shellcode.bin"
                const char *input_filename = strrchr(input_path, '/');
                if (!input_filename) {
                    input_filename = strrchr(input_path, '\\');
                }
                if (!input_filename) {
                    input_filename = input_path;
                } else {
                    input_filename++; // Skip the separator
                }

                // Allocate memory for the default output path
                size_t input_len = strlen(input_filename);
                size_t output_path_len = input_len + 15; // +15 for ".shellcode.bin" and null terminator
                char *default_output = malloc(output_path_len);
                if (!default_output) {
                    fprintf(stderr, "[-] Error: Memory allocation failed for default output path.\n");
                    free_section_filters();
                    return 1;
                }

                snprintf(default_output, output_path_len, "%s.shellcode.bin", input_filename);

                // Run extraction with generated output path
                result = extract_shellcode(input_path, default_output);

                // Free the generated output path
                free(default_output);
            } else {
                // Run extraction with specified output path
                result = extract_shellcode(input_path, output_path);
            }

            free_section_filters();  // Free any allocated filters
            return result;
        }
    }
}
