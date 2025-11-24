# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**purl_diver** is a cross-platform PE (Portable Executable) shellcode extraction tool designed for security research and malware analysis. It parses PE files, identifies executable sections, and extracts raw shellcode in multiple formats (binary, C array, Python, hex, JSON).

This is a **security analysis tool** - you can analyze code, document functionality, and answer questions, but you must not improve or enhance its capabilities without explicit authorization context.

## Refactoring Status

**⚠️ ACTIVE REFACTORING IN PROGRESS**

The project is undergoing modularization to improve maintainability. See `REFACTORING_STATUS.md` for detailed progress.

**Current State**:
- ✅ Build system complete (Makefile + CMake)
- ✅ Directory structure created (src/, include/, tests/)
- ✅ Error code system implemented
- 🔄 Module extraction in progress

**Coexistence**: Both old monolithic and new modular code exist during transition.

## Build Commands

### Compilation

**Recommended: Use Makefile or CMake**

**Makefile (Quick builds):**
```bash
make              # Default optimized build
make debug        # Debug build with symbols
make asan         # AddressSanitizer build
make ubsan        # UndefinedBehaviorSanitizer build
make release      # Optimized release build (stripped)
make test         # Run test suite
make clean        # Clean build artifacts
```

**CMake (Cross-platform):**
```bash
mkdir build && cd build
cmake ..                           # Default build
cmake -DENABLE_ASAN=ON ..         # With AddressSanitizer
cmake -DENABLE_UBSAN=ON ..        # With UBSan
cmake -DBUILD_TESTING=OFF ..      # Disable tests
cmake --build .                    # Build
ctest --output-on-failure          # Run tests
```

**Legacy (Manual compilation):**
```bash
# Linux/macOS
gcc extract_shellcode.c -o extract_shellcode -O2 -Wall -lm

# Windows (MSVC)
cl extract_shellcode.c /O2 /W4 /EHsc /Fe:extract_shellcode.exe
```

**Important:** The `-lm` flag links the math library (required for entropy calculations using `log2`).

### Testing

Run the test suite:
```bash
./test_suite.sh
```

The test suite requires a sample PE file. It looks for `cutyourmeat.exe` or falls back to available `.bin` files.

## Basic Usage

```bash
# Basic extraction (outputs raw binary)
./extract_shellcode input.exe output.bin

# Verbose mode with detailed output
./extract_shellcode -v input.exe output.bin

# Analyze without extracting
./extract_shellcode --dry-run input.exe

# Extract with hash and entropy analysis
./extract_shellcode --hash --entropy input.exe output.bin

# Different output formats
./extract_shellcode -f c input.exe output.c
./extract_shellcode -f python input.exe output.py
./extract_shellcode -f hex input.exe output.txt
./extract_shellcode -f json input.exe output.json

# Section filtering
./extract_shellcode --section .text input.exe output.bin
./extract_shellcode --exclude .rsrc input.exe output.bin

# Interactive mode (select sections manually)
./extract_shellcode --interactive input.exe output.bin

# Batch processing
./extract_shellcode --batch --output-dir ./extracted samples/*.exe
```

## Code Architecture

### High-Level Structure

The tool follows a **single-pass extraction pipeline** with security-focused design:

1. **Validation Phase**: PE structure validation with comprehensive bounds checking
2. **Analysis Phase**: Section identification, overlap detection, entropy calculation
3. **Extraction Phase**: Two-pass memory-safe extraction with precise allocation
4. **Output Phase**: Format-specific serialization (binary/C/Python/hex/JSON)

### Key Components

**PE Context Structure (`PE_Context` at line ~293)**
- Consolidates all PE-related state in a single context structure
- Reduces parameter passing and eliminates redundant calculations
- Contains: buffer, file_size, dos_header, nt_headers, section_table, machine type, entry point

**Core Functions:**
- `validate_pe_structure()`: Three-stage validation (DOS header, PE signature, architecture)
- `initialize_pe_context()`: Loads and validates PE file, initializes context
- `find_executable_sections()`: Identifies sections with `IMAGE_SCN_CNT_CODE` or `IMAGE_SCN_MEM_EXECUTE`
- `detect_overlaps_and_calculate_size()`: Prevents data corruption from malformed PE files
- `calculate_entropy()`: Shannon entropy for detecting packed/encrypted sections
- `compute_sha256_streaming()`: Memory-efficient streaming hash (no large allocations)

**Security Features:**
- 500MB file size limit (prevents resource exhaustion)
- Integer overflow protection in size calculations
- Two-pass extraction algorithm (calculate size first, then extract)
- Overlap detection (skips overlapping sections to prevent corruption)
- Comprehensive bounds checking on all buffer operations

### Cross-Platform PE Structure Definitions

Lines 28-223 define PE structures for non-Windows platforms. On Windows, `#include <windows.h>` provides these natively. On Linux/macOS, they're manually defined with `#pragma pack(push, 1)` for proper alignment.

### Output Formats

The tool supports 5 output formats controlled by `OutputFormat` enum:
- `OUTPUT_BINARY`: Raw binary shellcode (default)
- `OUTPUT_C_ARRAY`: C-style unsigned char array
- `OUTPUT_PYTHON`: Python byte string
- `OUTPUT_HEX_DUMP`: Human-readable hex dump with ASCII
- `OUTPUT_JSON`: Structured metadata with section details, entropy, hashes

### Command-Line Parsing

Lines ~1800-2100 implement argument parsing with support for:
- Section filtering (include/exclude)
- Multiple input files (batch mode)
- Analysis flags (hash, entropy, imports)
- Interactive section selection
- Progress indicators for large files

### Security Considerations

This tool is designed for **authorized security research only**:
- Always run in isolated VMs or sandboxes
- Never execute extracted shellcode
- Handle outputs as potentially malicious
- See `DOCS/SECURITY.md` for complete security policy

### Important Implementation Details

1. **Streaming Hash Functions**: MD5 and SHA-256 are implemented with chunked processing to avoid large memory allocations for padding (more efficient for large PE files).

2. **Section Name Parsing**: Section names in PE files are 8 bytes (not null-terminated). The code carefully handles this with proper truncation.

3. **32-bit vs 64-bit PE Files**: The tool detects architecture via `IMAGE_FILE_HEADER.Machine` field and handles both `IMAGE_OPTIONAL_HEADER` (32-bit) and `IMAGE_OPTIONAL_HEADER64` (64-bit).

4. **Entry Point Detection**: The tool identifies which section contains the entry point RVA for analysis purposes (see verbose output).

5. **Overlap Handling**: Malware often uses overlapping sections to evade analysis. The tool detects overlaps via `detect_overlaps_and_calculate_size()` and skips subsequent overlapping sections.

## Documentation

- `README.md`: Feature overview, usage examples, troubleshooting
- `CLAUDE.md`: This file - guidance for Claude Code
- `DOCS/BUILD.md`: Platform-specific build instructions
- `DOCS/USAGE.md`: Detailed command-line reference and examples
- `DOCS/SECURITY.md`: Threat model, safe usage practices, security features
- `DOCS/TROUBLESHOOTING.md`: Common errors and solutions
- `DOCS/OPTIMIZATIONS.md`: Comprehensive optimization roadmap (P0-P3 priorities)
- `REFACTORING_STATUS.md`: Current refactoring progress and metrics
- `src/README.md`: Source code module documentation
- `tests/README.md`: Test suite documentation

## Project Structure

**New Modular Structure (In Progress)**:
```
purl_diver_PUBLIC/
├── src/                      # Source modules
│   ├── error_codes.c         # ✅ Error code implementation
│   └── README.md             # Module documentation
├── include/                  # Public headers
│   ├── pe_types.h           # ✅ PE structure definitions
│   ├── error_codes.h        # ✅ Error code definitions
│   └── (more headers...)     # 🔄 To be extracted
├── tests/                    # Unit tests
│   ├── fixtures/            # Test PE files
│   └── README.md            # Test documentation
├── build/                    # CMake build directory
├── Makefile                  # ✅ Makefile build system
├── CMakeLists.txt           # ✅ CMake configuration
├── extract_shellcode.c       # Legacy monolithic source (2386 lines)
├── test_suite.sh            # Integration test harness
├── examples/                # Example usage
├── DOCS/                    # Documentation
│   ├── BUILD.md
│   ├── USAGE.md
│   ├── SECURITY.md
│   ├── TROUBLESHOOTING.md
│   ├── OPTIMIZATIONS.md     # ✅ Optimization roadmap
│   └── REFACTORING_STATUS.md # ✅ Refactoring progress
└── IMAGES/                  # Assets for README
```

**Legend**: ✅ Complete | 🔄 In Progress | ⏳ Planned

## Development Notes

### Working with Refactored Code

**Current State**: The project has both legacy monolithic code and new modular structure:

1. **Legacy Code**: `extract_shellcode.c` (2386 lines) - still the primary source
2. **New Modules**: `src/` and `include/` directories - foundation for modularization

**Build System**:
- `Makefile`: Use for quick iterative development
- `CMakeLists.txt`: Use for cross-platform builds and testing

**Adding Features**:
- For now, modify `extract_shellcode.c` directly
- Once modularization completes, follow new module structure

### Error Handling (New System)

Use structured error codes instead of magic numbers:

```c
#include "include/error_codes.h"

ExtractError result = some_operation();
if (!is_success(result)) {
    fprintf(stderr, "Error: %s\n", error_string(result));
    return result;
}
```

**Available Error Categories**:
- File I/O: `ERR_FILE_OPEN`, `ERR_FILE_READ`, `ERR_FILE_WRITE`
- Memory: `ERR_MEMORY_ALLOCATION`, `ERR_INTEGER_OVERFLOW`
- PE Format: `ERR_INVALID_DOS_SIGNATURE`, `ERR_INVALID_PE_SIGNATURE`
- Sections: `ERR_NO_EXECUTABLE_SECTIONS`, `ERR_SECTION_OVERLAP`

### Common Compilation Warnings (To Be Fixed)

The code has some warnings that will be addressed during refactoring:
- Implicit `strdup()` declaration (need `_GNU_SOURCE` or explicit declaration)
- Sign comparison warnings in size checks (`size_t` vs `long`)
- Unused parameter warnings in output functions

### Adding New Output Formats (Legacy)

To add a new format in current code:
1. Add enum value to `OutputFormat` (line ~250)
2. Implement `output_as_<format>()` function
3. Add case to format switch in main extraction logic (line ~2100+)
4. Update usage help text

### Modifying PE Parsing (Legacy)

The PE structure parsing is tightly coupled to the `PE_Context` structure. When adding new PE analysis:
1. Add fields to `PE_Context` if state needs to persist
2. Initialize in `initialize_pe_context()`
3. Clean up in `cleanup_pe_context()`
4. Maintain bounds checking on all buffer accesses

### Testing

**Run all tests**:
```bash
make test          # Using Makefile
ctest              # Using CMake
./test_suite.sh    # Legacy shell tests
```

**Memory leak checking**:
```bash
make asan          # Build with AddressSanitizer
./extract_shellcode --help

# Or with valgrind:
valgrind --leak-check=full ./extract_shellcode input.exe output.bin
```

### Refactoring Guidelines

When extracting modules from `extract_shellcode.c`:
1. **Preserve Functionality**: No behavior changes during refactoring
2. **Test After Each Module**: Ensure tests still pass
3. **Update Build Files**: Add new source files to Makefile/CMakeLists.txt
4. **Document**: Update src/README.md with module responsibilities
5. **Error Codes**: Use new `ExtractError` enum instead of int returns

See `DOCS/OPTIMIZATIONS.md` for complete refactoring roadmap.

## License

UNLICENSED (public domain equivalent)
