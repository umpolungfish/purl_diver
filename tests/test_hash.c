/**
 * @file test_hash.c
 * @brief Unit tests for MD5 and SHA256 implementations against NIST/RFC test vectors.
 *
 * Compile: gcc tests/test_hash.c src/hash_algorithms.c -o tests/test_hash -O2 -Wall -std=c99 -Iinclude
 * Run:     ./tests/test_hash
 */

#include "../include/hash_algorithms.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* -------------------------------------------------------------------------
 * Helpers
 * ---------------------------------------------------------------------- */

static int hexdump_eq(const unsigned char *got, const char *expected_hex, int len)
{
    for (int i = 0; i < len; i++) {
        unsigned int exp;
        sscanf(expected_hex + i * 2, "%02x", &exp);
        if (got[i] != (unsigned char)exp) return 0;
    }
    return 1;
}

static void print_hex(const unsigned char *buf, int len)
{
    for (int i = 0; i < len; i++) printf("%02x", buf[i]);
}

static int run_test(const char *label,
                    const unsigned char *data, size_t len,
                    const char *expected_md5,
                    const char *expected_sha256)
{
    unsigned char md5_out[16];
    unsigned char sha256_out[32];
    int ok = 1;

    calculate_md5((unsigned char *)data, len, md5_out);
    calculate_sha256((unsigned char *)data, len, sha256_out);

    int md5_pass    = hexdump_eq(md5_out,    expected_md5,    16);
    int sha256_pass = hexdump_eq(sha256_out, expected_sha256, 32);

    printf("  %-40s  MD5:%s  SHA256:%s\n",
           label,
           md5_pass    ? "PASS" : "FAIL",
           sha256_pass ? "PASS" : "FAIL");

    if (!md5_pass) {
        printf("    MD5 expected: %s\n", expected_md5);
        printf("    MD5 got:      "); print_hex(md5_out, 16); printf("\n");
        ok = 0;
    }
    if (!sha256_pass) {
        printf("    SHA256 expected: %s\n", expected_sha256);
        printf("    SHA256 got:      "); print_hex(sha256_out, 32); printf("\n");
        ok = 0;
    }

    return ok;
}

/* -------------------------------------------------------------------------
 * Test vectors (RFC 1321 for MD5, FIPS 180-4 / NIST for SHA256)
 * ---------------------------------------------------------------------- */

int main(void)
{
    int all_pass = 1;
    printf("Hash algorithm tests\n");
    printf("====================\n");

    /* --- Empty string --- */
    all_pass &= run_test(
        "empty string \"\"",
        (const unsigned char *)"", 0,
        "d41d8cd98f00b204e9800998ecf8427e",
        "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
    );

    /* --- "abc" (RFC 1321 / FIPS 180-4) --- */
    all_pass &= run_test(
        "\"abc\"",
        (const unsigned char *)"abc", 3,
        "900150983cd24fb0d6963f7d28e17f72",
        "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"
    );

    /* --- "message digest" (RFC 1321) --- */
    all_pass &= run_test(
        "\"message digest\"",
        (const unsigned char *)"message digest", 14,
        "f96b697d7cb7938d525a2f31aaf161d0",
        "f7846f55cf23e14eebeab5b4e1550cad5b509e3348fbc4efa3a1413d393cb650"
    );

    /* --- 55-byte input (exercises single-block padding path) --- */
    {
        unsigned char buf55[55];
        memset(buf55, 'a', sizeof(buf55));
        all_pass &= run_test(
            "55 x 'a'",
            buf55, sizeof(buf55),
            "ef1772b6dff9a122358552954ad0df65",
            "9f4390f8d30c2dd92ec9f095b65e2b9ae9b0a925a5258e241c9f1e910f734318"
        );
    }

    /* --- 64-byte input (exercises two-block padding path) --- */
    {
        unsigned char buf64[64];
        memset(buf64, 'a', sizeof(buf64));
        all_pass &= run_test(
            "64 x 'a'",
            buf64, sizeof(buf64),
            "014842d480b571495a4a0363793f7367",
            "ffe054fe7ae0cb6dc65c3af9b61d5209f439851db43d0ba5997337df154668eb"
        );
    }

    /* --- 1000 x 'a' (stresses multi-block streaming) --- */
    {
        unsigned char big[1000];
        memset(big, 'a', sizeof(big));
        all_pass &= run_test(
            "1000 x 'a'",
            big, sizeof(big),
            "cabe45dcc9ae5b66ba86600cca6b8ba8",
            "41edece42d63e8d9bf515a9ba6932e1c20cbc9f5a5d134645adb5db1b9737ea3"
        );
    }

    /* --- "The quick brown fox jumps over the lazy dog" --- */
    {
        const char *msg = "The quick brown fox jumps over the lazy dog";
        all_pass &= run_test(
            "\"The quick brown fox...\"",
            (const unsigned char *)msg, strlen(msg),
            "9e107d9d372bb6826bd81d3542a419d6",
            "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592"
        );
    }

    printf("====================\n");
    printf("Result: %s\n", all_pass ? "ALL PASSED" : "SOME TESTS FAILED");
    return all_pass ? 0 : 1;
}
