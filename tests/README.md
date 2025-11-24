# Test Suite

This directory contains unit tests and integration tests for purl_diver.

## Structure

```
tests/
├── README.md                 # This file
├── test_main.c               # Test runner (planned)
├── test_pe_parser.c          # PE parser unit tests (planned)
├── test_section_filter.c     # Section filtering tests (planned)
├── test_hash.c               # Hash algorithm tests (planned)
├── test_entropy.c            # Entropy calculation tests (planned)
├── test_error_codes.c        # Error code tests (planned)
└── fixtures/                 # Test PE files
    ├── valid_x86.exe         # Valid 32-bit PE (needed)
    ├── valid_x64.exe         # Valid 64-bit PE (needed)
    ├── malformed.bin         # Invalid PE (needed)
    └── README.md             # Fixture documentation
```

## Testing Framework

We will use a minimal custom testing framework or Unity (https://github.com/ThrowTheSwitch/Unity).

## Current Tests

The legacy shell-based test suite exists at the project root:
- `test_suite.sh` - Integration tests for the complete tool

## Running Tests

### CMake Build:
```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```

### Manual:
```bash
./test_runner
```

## Test Coverage Goals

- **Target**: 80%+ code coverage
- **Priority**: PE parsing, section analysis, error handling
- **Tools**: gcov/lcov for coverage analysis

## Adding New Tests

1. Create `test_<module>.c` file
2. Include the module header
3. Write test functions following pattern:
   ```c
   void test_function_name(void) {
       // Setup
       // Execute
       // Assert
       // Cleanup
   }
   ```
4. Register test in test_main.c
5. Run and verify

## Fixture Requirements

Test fixtures should cover:
- ✅ Valid PE files (x86, x64)
- ✅ Malformed PE files (invalid signatures, truncated)
- ✅ Edge cases (empty sections, overlapping sections, packed)
- ✅ Large files (for performance testing)
