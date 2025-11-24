/**
 * @file hash_algorithms.h
 * @brief Cryptographic hash functions (MD5, SHA256)
 *
 * This module provides streaming implementations of MD5 and SHA256
 * hash algorithms with memory-efficient chunk-based processing.
 */

#ifndef HASH_ALGORITHMS_H
#define HASH_ALGORITHMS_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Calculate MD5 hash of data
 *
 * Computes the MD5 hash using a streaming algorithm that processes
 * data in chunks without requiring large memory allocations.
 *
 * @param data Input data to hash
 * @param len Length of input data in bytes
 * @param hash Output buffer for MD5 hash (must be at least 16 bytes)
 */
void calculate_md5(unsigned char *data, size_t len, unsigned char *hash);

/**
 * @brief Calculate SHA256 hash of data
 *
 * Computes the SHA256 hash using a streaming algorithm that processes
 * data in chunks without requiring large memory allocations.
 *
 * @param data Input data to hash
 * @param len Length of input data in bytes
 * @param hash Output buffer for SHA256 hash (must be at least 32 bytes)
 */
void calculate_sha256(unsigned char *data, size_t len, unsigned char *hash);

/**
 * @brief Print hash value in hexadecimal format
 *
 * Prints a hash value to stdout with appropriate label.
 *
 * @param hash Hash value to print
 * @param hash_len Length of hash in bytes (16 for MD5, 32 for SHA256)
 * @param format_type Hash algorithm name ("md5" or "sha256")
 */
void print_hash(unsigned char *hash, int hash_len, const char *format_type);

#endif // HASH_ALGORITHMS_H
