<div align="center">
  <h1>purl diver</h1>
  <p><b>PE SHELLCODE EXTRACTOR</b></p>
  
  <img src="./IMAGES/PURL.png" alt="purl_diver logo" width="400">
</div>

<div align="center">
  
  ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
  &nbsp;
  ![PE](https://img.shields.io/badge/PE-Analysis-%23FF6B6B.svg?style=for-the-badge)
  &nbsp;
  ![Cross-Platform](https://img.shields.io/badge/Cross--Platform-Windows%20%7C%20Linux%20%7C%20macOS-%230071C5.svg?style=for-the-badge)
  &nbsp;
  ![Security](https://img.shields.io/badge/Security-Hardened-%23000000.svg?style=for-the-badge)
  
</div>

<p align="center">
  <a href="#overview">Overview</a> •
  <a href="#features">Features</a> •
  <a href="#building-and-usage">Usage</a> •
  <a href="#output-formats">Formats</a> •
  <a href="#analysis-features">Analysis</a> •
  <a href="#security">Security</a> •
  <a href="#use-cases">Use Cases</a>
</p>

<hr>

<br>

## OVERVIEW

**purl_diver** is a cross-platform command-line tool for extracting shellcode from PE (Portable Executable) files.


---

**purl_diver**:

1. **PARSES** PE file structure with comprehensive validation
2. **IDENTIFIES** executable sections via `IMAGE_SCN_CNT_CODE` or `IMAGE_SCN_MEM_EXECUTE` flags
3. **EXTRACTS** raw code bytes with overlap detection and boundary checks
4. **OUTPUTS** clean shellcode in multiple formats (binary, C, Python, hex, JSON)

`purl_diver` tool prioritizes `security`, `robustness`, and `portability`, running seamlessly on Windows, Linux, and macOS.

### 🏗️ Modular Architecture (v2.0)

**purl_diver v2.0** features a completely refactored modular architecture with **9 independent modules** for improved maintainability, testability, and extensibility:

- ✅ **Zero compilation warnings** (clean build with -Werror)
- ✅ **100% functional parity** with monolithic version
- ✅ **43KB binary size** (optimized)
- ✅ **Professional-grade code organization**

See [MODULAR_ARCHITECTURE.md](MODULAR_ARCHITECTURE.md) for complete architecture documentation.

<br>

## BUILDING AND USAGE

### Installation (Optional)

For convenience, you can install `purl_diver` globally, allowing you to run it from any directory.

```bash
sudo make install
```
This will place the executable in `/usr/local/bin/`.

### 

- A C compiler (`gcc`, `clang`, or MSVC)
- **Windows:** Visual Studio Build Tools or MinGW-w64
- **Linux:** `build-essential` package
- **macOS:** Xcode Command Line Tools

### BUILDING

**RECOMMENDED: Makefile Build (Modular Architecture)**

```bash
# Build modular version (purl_diver)
make              # Default: modular build
make modular      # Explicit modular build
make clean        # Remove build artifacts

# Other targets
make legacy       # Build legacy monolithic version
make help         # Show all build targets
make debug        # Debug build with symbols
make asan         # Build with AddressSanitizer
make valgrind     # Build with Valgrind support
make security     # Build with security compilation flags
```

**MANUAL BUILD (Platform-Specific):**

**WINDOWS (MSVC):**

```bash
# Modular version (recommended)
cl src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c src/entropy.c src/section_analyzer.c src/output_formats.c src/import_export_analyzer.c src/utils.c src/options.c /Iinclude /O2 /W4 /EHsc /Fe:purl_diver.exe

# Legacy monolithic version
cl extract_shellcode.c /O2 /W4 /EHsc /Fe:extract_shellcode.exe
```

**WINDOWS (MinGW):**

```bash
# Modular version (recommended)
gcc -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c src/entropy.c src/section_analyzer.c src/output_formats.c src/import_export_analyzer.c src/utils.c src/options.c -o purl_diver.exe -O2 -Wall -lm

# Legacy monolithic version
gcc extract_shellcode.c -o extract_shellcode.exe -O2 -Wall -lm
```

**LINUX:**

```bash
# Modular version (recommended)
gcc -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c src/entropy.c src/section_analyzer.c src/output_formats.c src/import_export_analyzer.c src/utils.c src/options.c -o purl_diver -O2 -Wall -lm

# Legacy monolithic version
gcc extract_shellcode.c -o extract_shellcode -O2 -Wall -lm
```

**macOS:**

```bash
# Modular version (recommended)
clang -Iinclude src/main.c src/error_codes.c src/pe_parser.c src/hash_algorithms.c src/entropy.c src/section_analyzer.c src/output_formats.c src/import_export_analyzer.c src/utils.c src/options.c -o purl_diver -O2 -Wall -lm

# Legacy monolithic version
clang extract_shellcode.c -o extract_shellcode -O2 -Wall -lm
```

### BASIC USAGE

> **Note**: The modular build produces the `purl_diver` binary. Legacy builds produce `extract_shellcode`. Both are functionally identical.

**1. EXTRACT SHELLCODE FROM PE FILE**

```bash
# If installed globally
purl_diver payload.exe shellcode.bin

# If running from project directory
./purl_diver payload.exe shellcode.bin

# If no output filename is specified, a default is generated
purl_diver payload.exe
```

**2. ENABLE VERBOSE MODE FOR DETAILED OUTPUT**

```bash
purl_diver -v payload.exe shellcode.bin
```

**3. EXTRACT WITH HASH CALCULATION**

```bash
purl_diver -h payload.exe shellcode.bin
```

**5. CALCULATE ENTROPY**

```bash
purl_diver -e payload.exe shellcode.bin
```

**6. OUTPUT IN DIFFERENT FORMATS**

```bash
# Output as C array
purl_diver -f c payload.exe

# Output as Python byte string
purl_diver -f python payload.exe

# Output as hex dump
purl_diver -f hex payload.exe

# Output as JSON with metadata
purl_diver -f json payload.exe
```

Success output:
```
[+] Success: Extracted 8192 bytes from 3 sections to 'shellcode.bin'.
```

### ADVANCED USAGE EXAMPLES

**INCLUDE SPECIFIC SECTIONS:**

```bash
purl_diver --include .text payload.exe output.bin
```

**EXCLUDE SPECIFIC SECTIONS:**

```bash
purl_diver --exclude .rsrc payload.exe output.bin
```

**MINIMUM SECTION SIZE:**

```bash
purl_diver --min-size 1024 payload.exe output.bin
```

**ANALYZE IMPORT/EXPORT TABLES:**

```bash
purl_diver -i payload.exe output.bin
```

**COMBINE MULTIPLE OPTIONS:**

```bash
purl_diver -v --hash --entropy -i payload.exe output.bin
```

### INSPECTING OUTPUT

View extracted shellcode in hexadecimal:

```bash
xxd output.bin
# or
hexdump -C output.bin
```

<br>

## FEATURES

<table>
<tr>
<td width="50%">

### CAPABILITIES

- **Cross-platform compatibility** (Windows, Linux, macOS) with improved portability through custom my_strdup implementation
- **x86/x64 architecture support**
- **Intelligent section detection** via PE characteristics
- **Overlap detection & handling** for malformed files (with sections sorted before processing to prevent missed overlaps)
- **Memory-safe extraction** with two-pass validation and global cleanup function with atexit registration
- **Multiple output formats** (binary, C, Python, hex, JSON)
- **Comprehensive PE validation** (DOS, NT, section headers)

</td>
<td width="50%">

### Security & ANALYSIS

- **Integer overflow protection**
- **Enhanced parameter validation** with improved validation for --min-size parameter using strtoul with overflow protection
- **500MB file size limit** (prevents resource exhaustion)
- **Entry point detection**
- **Entropy analysis** (detect packed/encrypted code)
- **SHA256 hash calculation**
- **Import/Export table analysis**
- **Section boundary validation**

</td>
</tr>
</table>

<br>

## OPTIMIZED ARCHITECTURE

`purl_diver` features an optimized, maintainable codebase with enhanced security and performance:

### OPTIMIZATIONS IMPLEMENTED

| Optimization | Impact | Description |
|--------------|--------|-------------|
| **PE Context Structure** | Performance & Maintainability | Consolidates PE-related data into a single context structure, reducing parameter passing and eliminating redundant calculations |
| **Streaming Hash Functions** | Memory Efficiency | Implements chunked MD5 (RFC 1321) and SHA-256 (FIPS PUB 180-4) algorithms that process data without large memory allocations for padded messages |
| **Optimized Section Parsing** | Performance | Eliminates duplicate string operations in section name parsing with single-pass processing |
| **Memory Management** | Security | Enhanced bounds checking and proper resource cleanup throughout codebase |

### ARCHITECTURE BENEFITS

<table>
<tr>
<td><b>MAINTAINABILITY</b></td>
<td>Structured PE Context design reduces complexity</td>
</tr>
<tr>
<td><b>PERFORMANCE</b></td>
<td>Streaming algorithms reduce memory usage for large files</td>
</tr>
<tr>
<td><b>EXTENSIBILITY</b></td>
<td>Easy to add new formats & features</td>
</tr>
<tr>
<td><b>TESTABILITY</b></td>
<td>Individual component validation</td>
</tr>
<tr>
<td><b>SECURITY</b></td>
<td>Comprehensive bounds & overflow checks</td>
</tr>
</table>

<br>

## OUTPUT FORMATS

`purl_diver` supports multiple output formats for seamless integration:

### FORMAT (DEFAULT)

<details>
<summary><b>Click to expand binary format</b></summary>

Raw binary output - perfect for direct shellcode usage:

```bash
purl_diver payload.exe shellcode.bin
```

</details>

### ARRAY FORMAT

<details>
<summary><b>Click to expand C format</b></summary>

Embed shellcode directly in C source:

```bash
purl_diver -f c payload.exe output.c
```

**Output:**
```c
unsigned char shellcode[] = {
  0x4D, 0x5A, 0x90, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  // ... more bytes
};
unsigned int shellcode_len = 8192;
```

</details>

### FORMAT

<details>
<summary><b>Click to expand Python format</b></summary>

Generate Python-ready byte strings:

```bash
purl_diver -f python payload.exe output.py
```

**Output:**
```python
shellcode = b"\x4D\x5A\x90\x00\x03\x00\x00\x00\x04\x00\x00\x00\xFF\xFF\x00\x00"
shellcode += b"\xB8\x00\x00\x00\x00\x00\x00\x00\x40\x00\x00\x00\x00\x00\x00\x00"
# ... more bytes
```

</details>

### DUMP FORMAT

<details>
<summary><b>Click to expand hex dump format</b></summary>

Human-readable hex dump with ASCII representation:

```bash
purl_diver -f hex payload.exe output.txt
```

**Output:**
```
00000000: 4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00  |MZ..............|
00000010: B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00  |........@.......|
00000020: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  |................|
```

</details>

### FORMAT

<details>
<summary><b>Click to expand JSON format</b></summary>

Structured metadata with extraction details:

```bash
purl_diver -f json payload.exe output.json
```

**Output:**
```json
{
  "input_file": "payload.exe",
  "architecture": "x64",
  "file_type": "EXECUTABLE",
  "entry_point_rva": 4096,
  "entry_point_section": ".text",
  "sections_extracted": 2,
  "total_bytes": 8192,
  "total_entropy": 7.92,
  "sha256": "a3f5b8...",
  "sections": [
    {
      "name": ".text",
      "virtual_address": 4096,
      "virtual_size": 4096,
      "raw_data_offset": 1024,
      "raw_data_size": 4096,
      "characteristics": "IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ",
      "entropy": 7.85
    }
  ]
}
```

</details>

<br>

## ANALYSIS FEATURES

### ENTROPY ANALYSIS

Detect packed or encrypted code sections:

```bash
purl_diver -e payload.exe shellcode.bin
```

**Entropy interpretation:**
- **< 5.0** - Low entropy (plain text, uncompressed)
- **5.0 - 7.0** - Normal compiled code
- **> 7.0** - High entropy (packed/encrypted/compressed)

### HASH CALCULATION

Generate SHA256 hash of extracted code with improved memory efficiency:

```bash
purl_diver -h payload.exe shellcode.bin
```

**Output:**
```
[+] SHA256: a3f5b8c2d1e4f7a9b6c3d0e1f2a5b8c9d2e3f4a7b8c1d2e3f4a5b6c7d8e9f0a1
```

### IMPORT/EXPORT ANALYSIS

Analyze PE dependencies and exports:

```bash
purl_diver -i payload.exe shellcode.bin
```

**Output:**
```
[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: LoadLibraryA (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
  Imported DLL: USER32.dll
    - Function: MessageBoxA (Hint: 0)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[EXPORTS ANALYSIS - example.dll]
  Base Ordinal: 1
  Number of Functions: 2
  Number of Names: 2
    - Function: Function1
    - Function: Function2
[END EXPORTS ANALYSIS]
```


<br>

</details>

### SAFE USAGE PRACTICES

<table>
<tr>
<td><b>ISOLATION</b></td>
<td>Run only in VMs or sandboxed environments</td>
</tr>
<tr>
<td><b>NEVER EXECUTE</b></td>
<td>Do not execute extracted shellcode without analysis</td>
</tr>
<tr>
<td><b>STAY UPDATED</b></td>
<td>Keep tool updated for security patches</td>
</tr>
<tr>
<td><b>ANALYZE FIRST</b></td>
<td>Use <code>-v</code> and <code>-i</code> options to analyze PE before extraction</td>
</tr>
</table>

<br>

## COMMAND-LINE OPTIONS

### GENERAL OPTIONS

```
-v, --verbose          Enable verbose output mode
-h, --hash             Calculate and display SHA256 hash
-e, --entropy          Calculate and display entropy
-i, --imports-exports  Analyze import/export tables
-f, --format <type>    Output format (binary, c, python, hex, json)
--help                 Display usage information and exit
--version              Display version information
```

### FILTERING OPTIONS

```
--include <sections>   Only extract specified sections (comma-separated)
--exclude <sections>   Exclude specified sections (comma-separated)
--min-size <bytes>     Minimum section size to extract
```

<br>

### THE PIPELINE

---

<div align="center">
  <img src="./IMAGES/purl_diver_chart.png" alt="Extraction pipeline" width="600">
</div>


## TROUBLESHOOTING

### ERRORS AND WARNINGS

<details>
<summary><b>Click to expand troubleshooting guide</b></summary>

#### Failed to open input file"
- Verify file path is correct and file exists
- Ensure you have read permissions for the file

#### Not a valid PE file (Invalid DOS signature)"
- File is not a PE (Windows executable) file
- Check that you're using a Windows EXE or DLL

#### Invalid PE signature"
- File has valid DOS header but missing PE signature
- May indicate corrupted or malformed PE file

#### Unsupported architecture"
- Tool only supports x86 (32-bit) and x64 (64-bit) PE files
- Other architectures are not supported

#### No executable sections found"
- PE file contains no sections marked as executable
- May indicate packed executable or obfuscated code

#### Skipping overlapping section"
- PE file contains overlapping sections
- Often a sign of malformed or malicious file

</details>

### PERFORMANCE TIPS

Analyze large files with verbose mode to see detailed information:

```bash
purl_diver -v large_file.exe output.bin
```

Include hash and entropy analysis for comprehensive output:

```bash
purl_diver -v -h -e -i large_file.exe output.bin
```
<br>

## CONTRIBUTING

Contributions are welcome! When contributing:

- Follow secure coding practices
- Include comprehensive bounds checking
- Add appropriate error handling
- Test against various PE formats and edge cases
- Update documentation for new features

<br>

## LICENSE

This project is UNLICENSED

<br>

<div align="center">
  <hr>
  <p><i>mfin' deep divin'!</i></p>
  <p><b>purl_diver</b> - holy diver, you've been down too long in the darkweb seas!</p>
</div>
