#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "entropy_test_utils.h"

// Simple test framework
int tests_run = 0;
int tests_passed = 0;

#define TEST_ASSERT(condition, message) \
    do { \
        tests_run++; \
        if (condition) { \
            tests_passed++; \
            printf("PASS: %s\n", message); \
        } else { \
            printf("FAIL: %s - %s\n", message, #condition); \
        } \
    } while(0)

void test_entropy_zero(void) {
    unsigned char data[] = {0, 0, 0, 0};
    double entropy = calculate_entropy(data, 4);
    // All zeros should have entropy of 0.0
    TEST_ASSERT(fabs(entropy - 0.0) < 0.0001, "Entropy of all zeros should be 0.0");
}

void test_entropy_random(void) {
    // Data that should give high entropy (approaching 8.0 for uniform random data)
    unsigned char data[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    double entropy = calculate_entropy(data, 8);
    // High entropy should be > 2.0 (exact value depends on distribution)
    TEST_ASSERT(entropy > 2.0, "Entropy of diverse data should be > 2.0");
}

void test_entropy_uniform(void) {
    // Data with uniform distribution
    unsigned char data[] = {0x00, 0x55, 0xAA, 0xFF}; // Each byte is different
    double entropy = calculate_entropy(data, 4);
    // Uniform distribution should have higher entropy than repeated bytes
    TEST_ASSERT(entropy > 0.0, "Entropy of uniform data should be > 0.0");
}

void test_entropy_empty(void) {
    // Empty data should have entropy of 0.0
    unsigned char data[1];
    double entropy = calculate_entropy(data, 0);
    TEST_ASSERT(fabs(entropy - 0.0) < 0.0001, "Entropy of empty data should be 0.0");
}

void test_entropy_repeating_pattern(void) {
    // Test with a repeating pattern - should have lower entropy than random
    unsigned char data[] = {0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01};
    double entropy = calculate_entropy(data, 8);
    // Repeating pattern should have lower entropy than fully random
    TEST_ASSERT(entropy < 2.0, "Entropy of repeating pattern should be low");
}

int main(void) {
    printf("Running entropy tests...\n\n");
    
    test_entropy_zero();
    test_entropy_random();
    test_entropy_uniform();
    test_entropy_empty();
    test_entropy_repeating_pattern();
    
    printf("\nTests run: %d, Tests passed: %d\n", tests_run, tests_passed);
    printf("Tests failed: %d\n", tests_run - tests_passed);
    
    if (tests_run == tests_passed) {
        printf("All tests PASSED!\n");
        return 0;
    } else {
        printf("Some tests FAILED!\n");
        return 1;
    }
}