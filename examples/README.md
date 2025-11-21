# PE Shellcode Extractor - Examples

This directory contains examples and test cases for the PE Shellcode Extractor tool.

## Directory Structure

- `sample_payload.exe` - Example PE file for testing (symbolic link to available sample)
- `expected_output.bin` - Expected output file for basic extraction
- `test_cases.sh` - Automated test cases
- `README.md` - This file

## Example Usage

### Basic Extraction
```bash
./extract_shellcode sample_payload.exe output.bin
```

### Verbose Output
```bash
./extract_shellcode -v sample_payload.exe output.bin
```

### Different Output Formats
```bash
# C array format
./extract_shellcode --format c sample_payload.exe

# Python byte string format
./extract_shellcode --format python sample_payload.exe

# Hex dump format
./extract_shellcode --format hex sample_payload.exe

# JSON metadata format
./extract_shellcode --format json sample_payload.exe
```

### Advanced Features
```bash
# Include hash calculation
./extract_shellcode --hash sample_payload.exe output.bin

# Include entropy analysis
./extract_shellcode --entropy --format json sample_payload.exe

# Analyze imports
./extract_shellcode --imports sample_payload.exe output.bin

# Process specific sections only
./extract_shellcode --section .text sample_payload.exe output.bin

# Batch processing
./extract_shellcode --batch file1.exe file2.exe file3.exe

# Batch processing with output directory
./extract_shellcode --batch --output-dir extracted/ file1.exe file2.exe
```

### Dry-run Analysis
```bash
# Analyze without extracting
./extract_shellcode --dry-run sample_payload.exe
```

## Available Sample Files

For these examples, we use the available PE files in the main directory:
- `cutyourmeat.exe` - Main sample file used for testing
- `shadowfall.exe` - Alternative sample file (if available)

## Test Cases

The `test_cases.sh` script runs comprehensive tests to verify tool functionality.

## Security Considerations

> ⚠️ **Warning**: The sample files may contain executable code and should be handled in a secure environment.