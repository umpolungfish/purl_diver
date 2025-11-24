/**
 * @file entropy.h
 * @brief Shannon entropy calculation for data analysis
 *
 * Provides entropy calculation to detect packed, encrypted, or compressed data.
 */

#ifndef ENTROPY_H
#define ENTROPY_H

#include <stddef.h>

/**
 * @brief Calculate Shannon entropy of data
 *
 * Computes the Shannon entropy to measure randomness/information density.
 * Useful for detecting packed/encrypted code sections.
 *
 * Entropy interpretation:
 * - < 5.0: Low entropy (plain text, uncompressed)
 * - 5.0 - 7.0: Normal compiled code
 * - > 7.0: High entropy (packed/encrypted/compressed)
 *
 * @param data Input data to analyze
 * @param len Length of data in bytes
 * @return Entropy value (0.0 - 8.0)
 */
double calculate_entropy(unsigned char *data, size_t len);

#endif // ENTROPY_H
