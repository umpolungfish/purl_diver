# PE Shellcode Extractor - Troubleshooting Guide

This guide helps users identify and resolve common issues when using the PE Shellcode Extractor tool.

## Table of Contents
1. [Common Issues](#common-issues)
2. [File-Related Problems](#file-related-problems)
3. [Format-Specific Issues](#format-specific-issues)
4. [Analysis Feature Problems](#analysis-feature-problems)
5. [Performance Issues](#performance-issues)
6. [Compilation and Installation](#compilation-and-installation)
7. [System Compatibility](#system-compatibility)
8. [Advanced Debugging](#advanced-debugging)

## Common Issues

### "No executable sections found"
**Symptoms:** Tool reports no executable sections even though the input appears to be a valid executable.

**Possible Causes:**
- File is packed or obfuscated (high entropy sections)
- PE headers are corrupted or intentionally malformed
- File is not actually a PE file despite extension
- All executable sections are too small and filtered out by minimum size

**Solutions:**
- Use `--verbose` flag to see detailed processing information
- Run entropy analysis to check if sections are packed: `./extract_shellcode --entropy --format json input.exe`
- Verify the file is a genuine PE: `file input.exe` or check for MZ header
- Temporarily disable section size filters with `--min-size 0`

### "Not a valid PE file" Error
**Symptoms:** Error message "Not a valid PE file (Invalid DOS signature)"

**Possible Causes:**
- File is not actually a PE format file
- File is corrupted
- File is a different executable format (ELF, Mach-O, etc.)

**Solutions:**
- Verify the file format using tools like `file` command
- Check if the file is actually a PE by examining hex dump for 'MZ' at offset 0x00
- Ensure the file wasn't truncated during download/copy

### "Section extends beyond file bounds"
**Symptoms:** Error message during processing.

**Possible Causes:**
- PE file with malformed section headers
- File corruption
- Intentionally crafted malicious PE to exploit parsers

**Solutions:**
- The tool should handle this safely with error message
- This indicates a malformed PE that shouldn't be processed further
- Report suspicious files if they're part of an investigation

## File-Related Problems

### Large File Processing Issues
**Symptoms:** Tool fails on large PE files or takes excessive time.

**Solutions:**
- Verify the 500MB file size limit isn't being exceeded inappropriately
- Use `--progress` flag to monitor progress on large files
- Ensure sufficient RAM is available (tool uses 2-pass algorithm)
- Consider using SSD storage for better I/O performance

### File Permission Issues
**Symptoms:** "Failed to open input file" errors.

**Solutions:**
- Check file permissions: `ls -la input.exe`
- Ensure the file is not locked by another process
- Verify you have read permissions on the file and directory
- On Windows, check if antivirus is locking the file

### Output Directory Issues
**Symptoms:** Cannot write output files when using `--batch` with `--output-dir`.

**Solutions:**
- Verify the output directory exists and has write permissions
- Check if there's sufficient disk space
- Ensure directory path doesn't contain invalid characters
- On Windows, avoid paths longer than 260 characters

## Format-Specific Issues

### JSON Output Problems
**Symptoms:** Invalid JSON or missing data in JSON output.

**Solutions:**
- Use a JSON validator to check output format
- Verify the tool version supports JSON output (`--help` to check)
- Ensure valid input files that have extractable sections
- Check for any error messages before JSON output

### C/Python/Hex Format Issues
**Symptoms:** Invalid syntax when trying to use output in respective languages.

**Solutions:**
- Verify that output is directed to stdout when using format options (no output file needed)
- For C arrays, ensure proper syntax when including in C code
- For Python, ensure proper import of the shellcode variable
- Check that output formats are properly escaped

### Binary Output Problems
**Symptoms:** Output binary file has unexpected size or content.

**Solutions:**
- Compare file sizes with verbose output: `ls -la output.bin` vs. tool output
- Use hex editor to verify content matches expectations
- Check if overlapping sections were skipped (tool warns about this)
- Verify the PE contained executable sections before extraction

## Analysis Feature Problems

### Import Analysis Issues
**Symptoms:** 
- No imports shown when binary should have them
- Errors during import analysis
- Unexpected import names

**Solutions:**
- Use `--verbose` to see import table processing details
- Verify the PE has a valid import table (check with other tools like PEview)
- Some executables have imports resolved dynamically and might not show in standard IAT
- Some malware uses custom import resolution techniques

### Entropy Analysis Problems
**Symptoms:** 
- Unexpected entropy values
- High entropy warnings for normal files

**Solutions:**
- Entropy values range from 0.0 to 8.0
- Values above 7.0 typically indicate packed/encrypted content
- Compressed executables naturally have high entropy
- Some legitimate files may have high entropy (e.g., files with embedded resources)

### Hash Calculation Issues
**Symptoms:** 
- Consistent hash values instead of content-dependent values
- Incorrect hash length or format

**Solutions:**
- Verify hash functionality with `--hash --format json` for reliable output
- Check that the same input consistently produces the same hash
- Verify the hash algorithm is working by testing with known inputs

## Performance Issues

### Slow Processing
**Symptoms:** Tool takes significantly longer than expected.

**Possible Causes:**
- Very large PE files
- Files with many sections
- Storage with slow I/O performance
- System memory pressure

**Solutions:**
- Use SSD storage for input/output files if possible
- Close other applications to free up system resources
- Process files one at a time instead of batch mode for troubleshooting
- Monitor system resources during operation

### High Memory Usage
**Symptoms:** System becomes unresponsive during extraction, high RAM usage.

**Solutions:**
- The tool uses a 2-pass algorithm to precisely calculate memory needs
- Memory usage is roughly equal to the size of executable sections
- Process large files one at a time to avoid memory accumulation
- Monitor memory usage: `top` or `htop` during operation

### Tool Crashes
**Symptoms:** Segmentation fault or other crash during operation.

**Solutions:**
- Run with minimal options first to isolate the problem
- Use `--dry-run` to analyze without extraction
- Update to the latest version of the tool
- Report crash with specific file and command for debugging

## Compilation and Installation

### Build Issues
**Symptoms:** Compilation errors when building from source.

**Common Issues and Solutions:**
- `error: 'stdint.h' file not found` - Install build essentials: `sudo apt-get install build-essential` (Ubuntu) or Xcode tools (macOS)
- `implicit declaration of function` - Include appropriate headers
- `undefined reference` - Link with math library: `gcc -lm`

### Platform-Specific Build Issues
**Linux:**
- Ensure gcc is installed: `sudo apt-get install gcc`
- Install development headers if needed

### Math Library Linking Issues
**Symptoms:** `undefined reference to 'log'` error during compilation.

**Common Error Message:**
```
/usr/bin/ld: /tmp/ccQc4OT9.o: in function 'calculate_entropy.part.0':
extract_shellcode.c:(.text+0xa49): undefined reference to 'log'
collect2: error: ld returned 1 exit status
```

**Solutions:**
- Include the math library during compilation with `-lm` flag
- Correct compilation commands:
  - Linux: `gcc extract_shellcode.c -o extract_shellcode -O2 -Wall -lm`
  - macOS: `clang extract_shellcode.c -o extract_shellcode -O2 -Wall -lm`
  - MinGW: `gcc extract_shellcode.c -o extract_shellcode.exe -O2 -Wall -lm`
- The math library is required for entropy calculations

**macOS:**
- Install Xcode Command Line Tools: `xcode-select --install`
- Use clang or install gcc via Homebrew

**Windows:**
- Use MSVC with Visual Studio Build Tools, or MinGW-w64
- Ensure environment variables are set correctly

## System Compatibility

### Cross-Platform Issues
**Symptoms:** Different behavior on different operating systems.

**Solutions:**
- The tool is designed to be cross-platform compatible
- File paths may need adjustment for different OS (forward vs. backward slashes)
- Some command-line options may interact differently with different shells
- Verify file encoding when sharing results between systems

### Architecture Compatibility
**Symptoms:** Issues with 32-bit vs 64-bit PE files.

**Solutions:**
- The tool supports both x86 (32-bit) and x64 (64-bit) PE files
- Use `--verbose` to see detected architecture
- Results should be consistent regardless of PE architecture

## Advanced Debugging

### Verbose Mode Usage
**When to use:** 
- First time using the tool with a new file
- When encountering unexpected results
- For detailed analysis of PE structure

**Commands:**
- `./extract_shellcode -v input.exe output.bin` - Basic verbose output
- `./extract_shellcode -v --format json input.exe` - Verbose with JSON metadata

### File Analysis Strategy
1. Start with `--dry-run` to understand the file structure
2. Use `--format json` to get comprehensive metadata
3. Apply filters (`--section`, `--min-size`) based on initial analysis
4. Perform full extraction once analysis is understood

### Troubleshooting Packed/Obfuscated Files
**Symptoms:** High entropy, few or no recognizable sections, imports that don't match expectations.

**Approach:**
- Use entropy analysis to confirm packing: `--entropy --format json`
- Consider that extraction may yield limited useful results from heavily packed files
- Focus on unpacking or dynamic analysis instead of static extraction for packed files
- Use other tools (like unpackers) before applying this tool

### Diagnostic Commands
```
# Basic analysis
./extract_shellcode --dry-run input.exe

# Detailed analysis with all features
./extract_shellcode --verbose --entropy --imports --format json input.exe

# Section-specific extraction
./extract_shellcode --section .text input.exe output.bin

# Size-based filtering
./extract_shellcode --min-size 1024 input.exe output.bin
```

## When to Report Issues

Report issues when:
- Tool crashes with standard inputs
- Clear bugs in functionality
- Security vulnerabilities are discovered
- Documentation doesn't match behavior

Do NOT report when:
- Working with intentionally malformed/corrupted files
- Encountering packed executables that don't extract meaningfully
- File is not actually a PE format
- Issue is related to system configuration outside the tool