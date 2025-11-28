#ifndef ENTROPY_TEST_UTILS_H
#define ENTROPY_TEST_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

// Include only the entropy calculation function
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

#endif // ENTROPY_TEST_UTILS_H