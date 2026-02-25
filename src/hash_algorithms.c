/**
 * @file hash_algorithms.c
 * @brief Implementation of MD5 and SHA256 hash algorithms
 *
 * Provides streaming implementations that process data in chunks
 * without requiring large memory allocations for padding.
 */

#include "../include/hash_algorithms.h"
#include <string.h>
#include <stdio.h>

// MD5 streaming context for chunk-based processing
typedef struct {
    uint32_t h[4];           // Hash state
    unsigned char buffer[64]; // Working buffer (512 bits)
    size_t buffer_len;       // Current bytes in buffer
    uint64_t total_len;      // Total bytes processed
} MD5_Context;

// SHA256 streaming context for chunk-based processing
typedef struct {
    uint32_t h[8];           // Hash state
    unsigned char buffer[64]; // Working buffer (512 bits)
    size_t buffer_len;       // Current bytes in buffer
    uint64_t total_len;      // Total bytes processed
} SHA256_Context;

// Forward declarations
static void md5_init(MD5_Context *ctx);
static void md5_process_block(MD5_Context *ctx, const unsigned char *block);
static void md5_update(MD5_Context *ctx, const unsigned char *data, size_t len);
static void md5_final(MD5_Context *ctx, unsigned char *hash);

static void sha256_init(SHA256_Context *ctx);
static void sha256_process_block(SHA256_Context *ctx, const unsigned char *block);
static void sha256_update(SHA256_Context *ctx, const unsigned char *data, size_t len);
static void sha256_final(SHA256_Context *ctx, unsigned char *hash);

// ============================================================================
// MD5 Implementation
// ============================================================================

static void md5_init(MD5_Context *ctx) {
    ctx->h[0] = 0x67452301;
    ctx->h[1] = 0xefcdab89;
    ctx->h[2] = 0x98badcfe;
    ctx->h[3] = 0x10325476;
    ctx->buffer_len = 0;
    ctx->total_len = 0;
}

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

    /* MD5 per-round left-rotation amounts (RFC 1321) */
    static const int s[64] = {
        7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
    };

    uint32_t w[16];
    for (int i = 0; i < 16; i++) {
        /* Cast to uint32_t before shifting to avoid signed-integer overflow UB */
        w[i] = (uint32_t)block[i * 4] |
               ((uint32_t)block[i * 4 + 1] << 8) |
               ((uint32_t)block[i * 4 + 2] << 16) |
               ((uint32_t)block[i * 4 + 3] << 24);
    }

    uint32_t a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3];

    /* Main loop — each round: compute F and index g, then
     * b += ROTL(F + a + K[i] + M[g], s[i])  (RFC 1321 §3.4) */
    for (int i = 0; i < 64; i++) {
        uint32_t f;
        int      g;

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

        uint32_t temp = f + a + k[i] + w[g];
        a = d;
        d = c;
        c = b;
        /* Apply the mandatory left-rotation before adding to b */
        b = b + ((temp << s[i]) | (temp >> (32 - s[i])));
    }

    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
}

static void md5_update(MD5_Context *ctx, const unsigned char *data, size_t len) {
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

static void md5_final(MD5_Context *ctx, unsigned char *hash) {
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

void calculate_md5(unsigned char *data, size_t len, unsigned char *hash) {
    MD5_Context ctx;
    md5_init(&ctx);
    md5_update(&ctx, data, len);
    md5_final(&ctx, hash);
}

// ============================================================================
// SHA256 Implementation
// ============================================================================

static void sha256_init(SHA256_Context *ctx) {
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

    /* Prepare message schedule — cast to uint32_t before shifting to
     * avoid signed-integer overflow UB when bytes >= 0x80 are shifted
     * into or past the sign bit (e.g. 0x80u << 24 is UB for signed int) */
    for (int i = 0; i < 16; i++) {
        w[i] = ((uint32_t)block[i * 4]     << 24) |
               ((uint32_t)block[i * 4 + 1] << 16) |
               ((uint32_t)block[i * 4 + 2] <<  8) |
                (uint32_t)block[i * 4 + 3];
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

static void sha256_update(SHA256_Context *ctx, const unsigned char *data, size_t len) {
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

static void sha256_final(SHA256_Context *ctx, unsigned char *hash) {
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

void calculate_sha256(unsigned char *data, size_t len, unsigned char *hash) {
    SHA256_Context ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, data, len);
    sha256_final(&ctx, hash);
}

// ============================================================================
// Utility Functions
// ============================================================================

void print_hash(unsigned char *hash, int hash_len, const char *format_type) {
    if (strcmp(format_type, "sha256") == 0) {
        printf("[INFO] SHA256: ");
    } else if (strcmp(format_type, "md5") == 0) {
        printf("[INFO] MD5: ");
    } else {
        printf("[INFO] Hash: ");
    }

    for (int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
