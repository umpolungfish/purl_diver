# Build Instructions

`purl_diver` is written in C99 and builds with GCC, Clang, or MSVC on Windows, Linux, and macOS.

## Prerequisites

- A C compiler: GCC, Clang, or MSVC
- **Windows**: Visual Studio Build Tools or MinGW-w64
- **Linux**: `build-essential` package (`sudo apt install build-essential`)
- **macOS**: Xcode Command Line Tools (`xcode-select --install`)

---

## Recommended: Makefile Build

The Makefile is the primary build system. From the project root:

```bash
make              # Default optimized build → ./purl_diver
make clean        # Remove all build artifacts (objects, deps, binaries)
make install      # Install to /usr/local/bin + man page
make uninstall    # Remove installed files
make help         # List all available targets
```

### Additional Targets

```bash
make debug        # Debug build: -g -O0 -fsanitize=address,undefined
make security     # Hardened build: -fstack-protector-strong -D_FORTIFY_SOURCE=2
make valgrind     # Build with debug symbols and run under Valgrind
make legacy       # Build legacy monolithic version (extract_shellcode)
```

### Testing

```bash
make test         # Run all unit tests (entropy, comprehensive, hash)
make test_hash    # Run MD5 / SHA-256 vector tests only
```

The Makefile compiles each source file to a separate object file and uses `-MMD -MP` to track header dependencies automatically, so incremental rebuilds are correct.

---

## Manual Compilation

Use these commands if you cannot use `make` (e.g. on Windows with MSVC).

The `-lm` flag is required on all platforms to link the math library for entropy calculations.

### Windows (MSVC)

Open a **Developer Command Prompt** and run:

```bash
cl src\main.c src\error_codes.c src\pe_parser.c src\hash_algorithms.c ^
   src\entropy.c src\section_analyzer.c src\output_formats.c ^
   src\import_export_analyzer.c src\utils.c src\options.c src\batch_processor.c ^
   /Iinclude /O2 /W4 /EHsc /Fe:purl_diver.exe
```

### Windows (MinGW-w64)

```bash
gcc -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c \
    src/entropy.c src/section_analyzer.c src/output_formats.c \
    src/import_export_analyzer.c src/utils.c src/options.c src/batch_processor.c \
    -o purl_diver.exe -O2 -Wall -std=c99 -lm
```

### Linux (GCC)

```bash
gcc -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c \
    src/entropy.c src/section_analyzer.c src/output_formats.c \
    src/import_export_analyzer.c src/utils.c src/options.c src/batch_processor.c \
    -o purl_diver -O2 -Wall -std=c99 -lm
```

### macOS (Clang)

```bash
clang -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c \
      src/entropy.c src/section_analyzer.c src/output_formats.c \
      src/import_export_analyzer.c src/utils.c src/options.c src/batch_processor.c \
      -o purl_diver -O2 -Wall -std=c99 -lm
```

---

After a successful build, refer to [USAGE.md](USAGE.md) for how to run the tool.
