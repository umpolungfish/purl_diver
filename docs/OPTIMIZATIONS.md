# Optimization Roadmap for purl_diver

This document outlines a comprehensive optimization strategy for the purl_diver PE shellcode extraction tool, organized by priority and impact.

## Priority Legend

- **P0 (Critical)**: Foundational improvements that enable other optimizations
- **P1 (High)**: Significant impact on maintainability, performance, or code quality
- **P2 (Medium)**: Important improvements with moderate impact
- **P3 (Low)**: Nice-to-have enhancements

---

## P0: Critical - Foundational Improvements

### 1. Add Build System (CMake + Makefile)
**Impact**: Enables proper multi-file compilation, cross-platform builds, testing integration
**Effort**: 2-3 hours
**Files**: `CMakeLists.txt`, `Makefile`

**Benefits**:
- Automated dependency management
- Cross-platform build configuration
- Integration with testing frameworks
- Support for sanitizers and static analysis

**Implementation**:
```cmake
cmake_minimum_required(VERSION 3.10)
project(purl_diver VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Source files (will expand as we modularize)
set(SOURCES
    src/extract_shellcode.c
)

add_executable(extract_shellcode ${SOURCES})

# Platform-specific settings
if(UNIX AND NOT APPLE)
    target_link_libraries(extract_shellcode m)
endif()

# Compiler warnings
if(MSVC)
    target_compile_options(extract_shellcode PRIVATE /W4)
else()
    target_compile_options(extract_shellcode PRIVATE -Wall -Wextra -O2)
endif()

# Optional sanitizers
option(ENABLE_ASAN "Enable Address Sanitizer" OFF)
option(ENABLE_UBSAN "Enable Undefined Behavior Sanitizer" OFF)

if(ENABLE_ASAN)
    target_compile_options(extract_shellcode PRIVATE -fsanitize=address)
    target_link_options(extract_shellcode PRIVATE -fsanitize=address)
endif()

if(ENABLE_UBSAN)
    target_compile_options(extract_shellcode PRIVATE -fsanitize=undefined)
    target_link_options(extract_shellcode PRIVATE -fsanitize=undefined)
endif()

# Install
install(TARGETS extract_shellcode DESTINATION bin)

# Testing
enable_testing()
add_subdirectory(tests)
```

**Simple Makefile**:
```makefile
CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c11
LDFLAGS = -lm

TARGET = extract_shellcode
SRC = extract_shellcode.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

asan: CFLAGS += -fsanitize=address -g
asan: LDFLAGS += -fsanitize=address
asan: $(TARGET)

clean:
	rm -f $(TARGET) *.o

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

.PHONY: all debug asan clean install
```

---

### 2. Split Monolithic File into Modules
**Impact**: Essential for maintainability, testing, and parallel development
**Effort**: 6-8 hours
**Files**: Refactor 2386 lines into 8 separate modules

**Proposed Structure**:
```
src/
├── main.c                    # Entry point, argument parsing (300 lines)
├── pe_parser.c/.h            # PE structure parsing & validation (400 lines)
├── section_analyzer.c/.h     # Section detection & filtering (300 lines)
├── hash_algorithms.c/.h      # MD5/SHA256 implementations (400 lines)
├── entropy.c/.h              # Entropy calculation (100 lines)
├── import_export.c/.h        # Import/export analysis (300 lines)
├── output_formats.c/.h       # All output format handlers (400 lines)
└── utils.c/.h                # Helper functions (200 lines)
```

**Module Responsibilities**:

**pe_parser.h**:
```c
typedef struct {
    unsigned char *buffer;
    long file_size;
    PIMAGE_DOS_HEADER dos_header;
    PIMAGE_NT_HEADERS32 nt_headers;
    WORD machine;
    DWORD entry_point_rva;
    PIMAGE_SECTION_HEADER section_table;
    WORD num_sections;
    unsigned char *output_buffer;
    size_t total_shellcode_size;
    int is_mapped;  // For mmap optimization
} PE_Context;

int validate_pe_structure(FILE *f, unsigned char **buffer, long *file_size);
int initialize_pe_context(const char *input_path, PE_Context *ctx);
void cleanup_pe_context(PE_Context *ctx);
```

**section_analyzer.h**:
```c
int find_executable_sections(PE_Context *ctx,
                             PIMAGE_SECTION_HEADER **valid_sections,
                             size_t *num_valid_sections);
int detect_overlaps_and_calculate_size(PIMAGE_SECTION_HEADER *valid_sections,
                                       size_t num_valid_sections,
                                       size_t *total_shellcode_size);
int is_section_included(PIMAGE_SECTION_HEADER section);
```

---

### 3. Add Comprehensive Unit Testing
**Impact**: Ensures correctness, enables refactoring confidence
**Effort**: 4-6 hours
**Files**: `tests/` directory with multiple test files

**Testing Framework Options**:
- Unity (lightweight, popular)
- Custom minimal framework
- Check (full-featured)

**Test Structure**:
```
tests/
├── CMakeLists.txt
├── test_main.c               # Test runner
├── test_pe_parser.c          # PE validation tests
├── test_section_filter.c     # Section filtering logic
├── test_hash.c               # MD5/SHA256 correctness
├── test_entropy.c            # Entropy calculation
├── test_overlap_detection.c  # Overlap handling
├── test_utils.c              # Helper function tests
└── fixtures/                 # Test PE files
    ├── valid_x86.exe
    ├── valid_x64.exe
    ├── malformed_headers.exe
    ├── overlapping_sections.exe
    └── packed_upx.exe
```

**Example Test**:
```c
void test_pe_validation_valid_x86(void) {
    PE_Context ctx;
    int result = initialize_pe_context("fixtures/valid_x86.exe", &ctx);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(IMAGE_FILE_MACHINE_I386, ctx.machine);
    cleanup_pe_context(&ctx);
}

void test_pe_validation_invalid_dos_signature(void) {
    FILE *f = fopen("fixtures/invalid_dos.bin", "rb");
    unsigned char *buffer = NULL;
    long file_size = 0;
    int result = validate_pe_structure(f, &buffer, &file_size);
    TEST_ASSERT_NOT_EQUAL(0, result);
}
```

---

## P1: High Priority - Major Improvements

### 4. Unified Error Handling with goto cleanup
**Impact**: Eliminates 50+ scattered free() calls, prevents memory leaks
**Effort**: 2-3 hours
**Files**: All modules after refactoring

**Pattern**:
```c
int extract_shellcode(const char *input_path, const char *output_path) {
    PE_Context ctx = {0};
    PIMAGE_SECTION_HEADER *valid_sections = NULL;
    unsigned char *output_buffer = NULL;
    int result = 1;  // Assume failure

    if (initialize_pe_context(input_path, &ctx) != 0) {
        goto cleanup;
    }

    if (find_executable_sections(&ctx, &valid_sections, &num_valid_sections) != 0) {
        goto cleanup;
    }

    output_buffer = malloc(total_size);
    if (!output_buffer) {
        goto cleanup;
    }

    // ... main logic ...

    result = 0;  // Success

cleanup:
    if (output_buffer) free(output_buffer);
    if (valid_sections) free(valid_sections);
    cleanup_pe_context(&ctx);
    free_section_filters();
    return result;
}
```

---

### 5. Eliminate Double File Read
**Impact**: Reduces I/O operations by 50% for file loading
**Effort**: 1 hour
**Files**: `pe_parser.c`

**Current Issue**: File is read in `validate_pe_structure`, closed, then reopened and read again in `initialize_pe_context`.

**Fix**: Read once, validate from buffer:
```c
int initialize_pe_context(const char *input_path, PE_Context *ctx) {
    memset(ctx, 0, sizeof(PE_Context));

    FILE *f = fopen(input_path, "rb");
    if (!f) return ERR_FILE_OPEN;

    // Get file size
    fseek(f, 0, SEEK_END);
    ctx->file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Validate size
    if (ctx->file_size > MAX_FILE_SIZE) {
        fclose(f);
        return ERR_FILE_TOO_LARGE;
    }

    // Single allocation and read
    ctx->buffer = malloc(ctx->file_size);
    if (!ctx->buffer) {
        fclose(f);
        return ERR_MEMORY;
    }

    if (fread(ctx->buffer, 1, ctx->file_size, f) != ctx->file_size) {
        free(ctx->buffer);
        fclose(f);
        return ERR_FILE_READ;
    }
    fclose(f);

    // Validate PE structure from buffer
    return validate_pe_from_buffer(ctx);
}
```

---

### 6. Add Error Code Enum
**Impact**: Improves error handling clarity and debugging
**Effort**: 1 hour
**Files**: `utils.h`, all modules

**Implementation**:
```c
typedef enum {
    EXTRACT_SUCCESS = 0,
    ERR_FILE_OPEN,
    ERR_FILE_READ,
    ERR_FILE_WRITE,
    ERR_FILE_TOO_LARGE,
    ERR_MEMORY_ALLOCATION,
    ERR_INVALID_DOS_SIGNATURE,
    ERR_INVALID_PE_SIGNATURE,
    ERR_UNSUPPORTED_ARCHITECTURE,
    ERR_INVALID_SECTION_TABLE,
    ERR_NO_EXECUTABLE_SECTIONS,
    ERR_INTEGER_OVERFLOW,
    ERR_SECTION_OVERLAP,
    ERR_INVALID_ARGUMENTS
} ExtractError;

const char* error_string(ExtractError err);
```

---

### 7. Implement Structured Logging System
**Impact**: Better debugging, cleaner code, flexible output control
**Effort**: 2 hours
**Files**: `utils.c/.h`

**Implementation**:
```c
typedef enum {
    LOG_DEBUG,   // Only with -v
    LOG_INFO,    // Normal informational
    LOG_WARN,    // Warnings
    LOG_ERROR    // Errors
} LogLevel;

void log_init(int verbose_mode);
void log_message(LogLevel level, const char *fmt, ...);
void log_section(const char *name, const char *fmt, ...);
void log_progress(const char *operation, int percent);

// Usage:
log_message(LOG_DEBUG, "Processing section '%s' at offset 0x%X", name, offset);
log_message(LOG_ERROR, "Failed to allocate %zu bytes", size);
log_progress("Extracting", 75);
```

---

### 8. CI/CD Pipeline with GitHub Actions
**Impact**: Automated testing, multi-platform validation
**Effort**: 2 hours
**Files**: `.github/workflows/ci.yml`

**Implementation**:
```yaml
name: CI

on:
  push:
    branches: [ main, develop ]
  pull_request:
    branches: [ main ]

jobs:
  build-and-test:
    strategy:
      matrix:
        os: [ubuntu-latest, macos-latest, windows-latest]
        compiler: [gcc, clang]
        exclude:
          - os: windows-latest
            compiler: clang

    runs-on: ${{ matrix.os }}

    steps:
      - uses: actions/checkout@v3

      - name: Install dependencies (Linux)
        if: runner.os == 'Linux'
        run: |
          sudo apt-get update
          sudo apt-get install -y build-essential cmake valgrind

      - name: Build
        run: |
          mkdir build && cd build
          cmake -DCMAKE_C_COMPILER=${{ matrix.compiler }} ..
          cmake --build .

      - name: Run tests
        run: |
          cd build
          ctest --output-on-failure

      - name: Memory leak check (Linux only)
        if: runner.os == 'Linux'
        run: |
          valgrind --leak-check=full --error-exitcode=1 \
            ./build/extract_shellcode --help

  static-analysis:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3

      - name: Install clang-tidy
        run: sudo apt-get install -y clang-tidy

      - name: Run static analysis
        run: |
          clang-tidy extract_shellcode.c -- -I.
```

---

## P2: Medium Priority - Important Enhancements

### 9. Memory-Mapped File I/O for Large Files
**Impact**: Reduces memory usage and improves performance for files >50MB
**Effort**: 3-4 hours
**Files**: `pe_parser.c`

**Implementation**:
```c
int initialize_pe_context_mmap(const char *input_path, PE_Context *ctx) {
#ifdef _WIN32
    HANDLE hFile = CreateFile(input_path, GENERIC_READ, FILE_SHARE_READ,
                              NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return ERR_FILE_OPEN;

    LARGE_INTEGER file_size;
    GetFileSizeEx(hFile, &file_size);
    ctx->file_size = file_size.QuadPart;

    HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    ctx->buffer = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    ctx->is_mapped = 1;
    CloseHandle(hMap);
    CloseHandle(hFile);
#else
    int fd = open(input_path, O_RDONLY);
    if (fd < 0) return ERR_FILE_OPEN;

    struct stat st;
    fstat(fd, &st);
    ctx->file_size = st.st_size;

    ctx->buffer = mmap(NULL, ctx->file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    ctx->is_mapped = 1;
    close(fd);
#endif

    return validate_pe_from_buffer(ctx);
}
```

---

### 10. Optimize Entropy Calculation
**Impact**: Faster entropy analysis for large sections
**Effort**: 1 hour
**Files**: `entropy.c`

**Optimization**:
```c
// Pre-compute log2 table at startup
static double log2_table[256 * 256];  // For all possible frequency counts
static int log2_table_initialized = 0;

void init_log2_table(void) {
    for (int i = 1; i < 256 * 256; i++) {
        log2_table[i] = log2(i);
    }
    log2_table_initialized = 1;
}

double calculate_entropy_fast(unsigned char *data, size_t len) {
    if (!log2_table_initialized) init_log2_table();

    uint32_t frequency[256] = {0};

    // Single pass frequency count
    for (size_t i = 0; i < len; i++) {
        frequency[data[i]]++;
    }

    double entropy = 0.0;
    double len_d = (double)len;

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            double p = frequency[i] / len_d;
            entropy -= p * (log2_table[frequency[i]] - log2_table[(int)len]);
        }
    }

    return entropy;
}
```

---

### 11. Cache Section Name Comparisons
**Impact**: Faster section filtering when multiple files processed
**Effort**: 2 hours
**Files**: `section_analyzer.c`

**Implementation**:
```c
typedef struct {
    char name[IMAGE_SIZEOF_SHORT_NAME + 1];
    uint32_t hash;
} SectionFilter;

static SectionFilter *include_filters = NULL;
static SectionFilter *exclude_filters = NULL;

static uint32_t hash_section_name(const char *name) {
    uint32_t hash = 5381;
    for (int i = 0; i < IMAGE_SIZEOF_SHORT_NAME && name[i]; i++) {
        hash = ((hash << 5) + hash) + name[i];
    }
    return hash;
}

int is_section_included_fast(PIMAGE_SECTION_HEADER section) {
    char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
    memcpy(section_name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
    section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';

    uint32_t hash = hash_section_name(section_name);

    // Check include list with hash comparison first
    if (include_filters && include_count > 0) {
        for (size_t i = 0; i < include_count; i++) {
            if (include_filters[i].hash == hash &&
                strcmp(section_name, include_filters[i].name) == 0) {
                return 1;
            }
        }
        return 0;
    }

    // Similar for exclude list
    // ...
}
```

---

### 12. Add Fuzzing Harness
**Impact**: Discovers edge cases and vulnerabilities
**Effort**: 2 hours
**Files**: `fuzz/fuzz_target.c`

**Implementation**:
```c
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // Write fuzzer input to temporary file
    char tmpfile[] = "/tmp/fuzz_pe_XXXXXX";
    int fd = mkstemp(tmpfile);
    if (fd < 0) return 0;

    write(fd, Data, Size);
    close(fd);

    // Try to extract shellcode
    PE_Context ctx;
    initialize_pe_context(tmpfile, &ctx);
    cleanup_pe_context(&ctx);

    // Cleanup
    unlink(tmpfile);
    return 0;
}
```

**Build with AFL++**:
```bash
afl-clang-fast extract_shellcode.c -o extract_shellcode_fuzz
afl-fuzz -i corpus/ -o findings/ -- ./extract_shellcode_fuzz @@
```

---

### 13. Improve test_suite.sh
**Impact**: More thorough validation, catches regressions
**Effort**: 2 hours
**Files**: `test_suite.sh`

**Enhancements**:
- Checksum validation of outputs
- Performance benchmarking
- Memory leak detection with valgrind
- Edge case testing (empty files, huge files, malformed PEs)

---

### 14. Add Static Analysis Configuration
**Impact**: Automated code quality checks
**Effort**: 1 hour
**Files**: `.clang-tidy`, `.clang-format`

**`.clang-tidy`**:
```yaml
Checks: '-*,
  clang-analyzer-*,
  bugprone-*,
  performance-*,
  portability-*,
  readability-*,
  cert-*,
  -readability-magic-numbers,
  -cert-err33-c'
WarningsAsErrors: ''
HeaderFilterRegex: '.*'
```

**`.clang-format`**:
```yaml
BasedOnStyle: LLVM
IndentWidth: 4
ColumnLimit: 100
AllowShortFunctionsOnASingleLine: None
BreakBeforeBraces: Attach
```

---

## P3: Low Priority - Nice-to-Have Features

### 15. Configuration File Support
**Impact**: User convenience for repeated operations
**Effort**: 3 hours
**Files**: `config.c/.h`

**Format** (`.purl_diver.conf`):
```ini
[filters]
exclude_sections=.rsrc,.reloc
min_section_size=1024

[output]
format=binary
include_hash=true
include_entropy=true

[analysis]
analyze_imports=false
verbose=false
```

---

### 16. Add API Documentation with Doxygen
**Impact**: Better developer onboarding
**Effort**: 2 hours
**Files**: `Doxyfile`, comments in all headers

---

### 17. Plugin System for Output Formats
**Impact**: Extensibility
**Effort**: 4 hours
**Files**: `plugins.c/.h`

---

### 18. Progress Callbacks for Library Use
**Impact**: Enables library integration
**Effort**: 2 hours
**Files**: `extract_shellcode.h`

---

### 19. Add CONTRIBUTING.md
**Impact**: Community contributions
**Effort**: 1 hour
**Files**: `CONTRIBUTING.md`

---

### 20. Sanitizer Build Targets
**Impact**: Runtime error detection
**Effort**: 30 minutes
**Files**: `CMakeLists.txt` (already included in #1)

---

## Implementation Timeline

### Phase 1: Foundation (Week 1)
- P0.1: Add build system
- P0.2: Split into modules
- P0.3: Add unit testing
- P1.4: Unified error handling
- P1.5: Eliminate double file read

### Phase 2: Quality & Performance (Week 2)
- P1.6: Error code enum
- P1.7: Logging system
- P1.8: CI/CD pipeline
- P2.9: Memory-mapped I/O
- P2.10: Optimize entropy

### Phase 3: Robustness (Week 3)
- P2.11: Cache section comparisons
- P2.12: Fuzzing harness
- P2.13: Improve test suite
- P2.14: Static analysis

### Phase 4: Polish (Week 4)
- P3.15-20: Nice-to-have features as time permits

---

## Success Metrics

- **Code Quality**: Clean static analysis results, 80%+ test coverage
- **Performance**: 2x faster for large files (>100MB) with mmap
- **Maintainability**: Module count: 8, avg lines per module: <400
- **Reliability**: Zero memory leaks under valgrind, passes fuzzing for 24h

---

## Notes

This is a living document. Priorities may shift based on:
- Community feedback
- Discovered vulnerabilities
- Performance bottlenecks in production use
- Integration requirements
