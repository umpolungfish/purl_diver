/**
 * @file entropy.c
 * @brief Implementation of Shannon entropy calculation
 */

#include "../include/entropy.h"
#include <math.h>

double calculate_entropy(unsigned char *data, size_t len) {
    if (!data || len == 0) {
        return 0.0;
    }

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
