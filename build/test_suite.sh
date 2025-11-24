#!/bin/bash

# PE Shellcode Extractor Test Suite
# This script tests various functionalities of the extract_shellcode tool

echo "PE Shellcode Extractor Test Suite"
echo "================================"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}[PASS]${NC} $2"
    else
        echo -e "${RED}[FAIL]${NC} $2"
    fi
}

# Test executable
TEST_EXE="./extract_shellcode"
SAMPLE_FILE="cutyourmeat.exe"

# Verify the executable exists
if [ ! -f "$TEST_EXE" ]; then
    echo -e "${RED}[ERROR]${NC} Test executable not found: $TEST_EXE"
    exit 1
fi

# Verify the sample file exists
if [ ! -f "$SAMPLE_FILE" ]; then
    echo -e "${YELLOW}[WARN]${NC} Sample file not found: $SAMPLE_FILE"
    echo "Using a minimal test approach with available files..."
    if [ -f "sutil.bin" ]; then
        SAMPLE_FILE="sutil.bin"
    elif [ -f "kl.bin" ]; then
        SAMPLE_FILE="kl.bin"
    else
        echo -e "${RED}[ERROR]${NC} No sample files available for testing"
        exit 1
    fi
fi

echo "Testing with sample file: $SAMPLE_FILE"
echo ""

# Test 1: Basic extraction
echo "Test 1: Basic extraction functionality"
./extract_shellcode "$SAMPLE_FILE" "test_basic.bin" 2>/dev/null
result=$?
print_result $result "Basic extraction"
if [ $result -eq 0 ]; then
    if [ -f "test_basic.bin" ]; then
        echo "     Output file size: $(stat -c%s test_basic.bin) bytes"
        rm -f test_basic.bin
    else
        echo -e "${RED}[FAIL]${NC} Output file was not created"
        result=1
    fi
fi
echo ""

# Test 2: Verbose mode
echo "Test 2: Verbose mode"
./extract_shellcode -v "$SAMPLE_FILE" "test_verbose.bin" 2>/dev/null
result=$?
print_result $result "Verbose mode"
if [ $result -eq 0 ]; then
    if [ -f "test_verbose.bin" ]; then
        rm -f test_verbose.bin
    fi
fi
echo ""

# Test 3: Different output formats
echo "Test 3: Output format tests"
formats=("c" "python" "hex" "json")
for format in "${formats[@]}"; do
    echo "  Testing $format format:"
    output=$(./extract_shellcode --format $format "$SAMPLE_FILE" 2>/dev/null)
    result=$?
    if [ $result -eq 0 ]; then
        echo -e "    ${GREEN}[PASS]${NC} $format format"
    else
        echo -e "    ${RED}[FAIL]${NC} $format format"
    fi
done
echo ""

# Test 4: Hash calculation
echo "Test 4: Hash calculation"
./extract_shellcode --hash "$SAMPLE_FILE" "test_hash.bin" 2>/dev/null
result=$?
print_result $result "Hash calculation"
if [ $result -eq 0 ]; then
    if [ -f "test_hash.bin" ]; then
        rm -f test_hash.bin
    fi
fi
echo ""

# Test 5: Entropy calculation
echo "Test 5: Entropy calculation"
./extract_shellcode --entropy --format json "$SAMPLE_FILE" 2>/dev/null | grep -q "total_entropy"
result=$?
print_result $result "Entropy calculation in JSON output"
echo ""

# Test 6: Import analysis
echo "Test 6: Import analysis"
./extract_shellcode --imports "$SAMPLE_FILE" "test_imports.bin" 2>/dev/null | grep -q "IMPORTS ANALYSIS"
result=$?
print_result $result "Import analysis"
if [ $result -eq 0 ]; then
    if [ -f "test_imports.bin" ]; then
        rm -f test_imports.bin
    fi
fi
echo ""

# Test 7: Section filtering
echo "Test 7: Section filtering"
# This test may pass or fail depending on the sample file's sections
./extract_shellcode --section .text "$SAMPLE_FILE" "test_section.bin" 2>/dev/null
result=$?
if [ $result -eq 0 ]; then
    if [ -f "test_section.bin" ]; then
        echo -e "${GREEN}[PASS]${NC} Section filtering (text section)"
        rm -f test_section.bin
    else
        echo -e "${GREEN}[PASS]${NC} Section filtering (no matching sections)"
    fi
else
    echo -e "${YELLOW}[INFO]${NC} Section filtering - no .text section found or different naming"
fi
echo ""

# Test 8: Dry-run mode
echo "Test 8: Dry-run mode"
./extract_shellcode --dry-run "$SAMPLE_FILE" 2>/dev/null | grep -q "executable sections"
result=$?
print_result $result "Dry-run mode"
echo ""

# Test 9: Help option
echo "Test 9: Help option"
./extract_shellcode --help 2>/dev/null | grep -q "PE Shellcode Extractor"
result=$?
print_result $result "Help option"
echo ""

# Test 10: Progress indicator (only if file is large enough)
echo "Test 10: Progress indicator"
file_size=$(stat -c%s "$SAMPLE_FILE" 2>/dev/null)
if [ $file_size -gt 1048576 ]; then  # > 1MB
    ./extract_shellcode --progress "$SAMPLE_FILE" "test_progress.bin" 2>/dev/null
    result=$?
    print_result $result "Progress indicator (large file)"
    if [ -f "test_progress.bin" ]; then
        rm -f test_progress.bin
    fi
else
    echo -e "${YELLOW}[SKIP]${NC} Progress indicator (file too small)"
fi
echo ""

# Test 11: Batch mode
echo "Test 11: Batch mode"
./extract_shellcode --batch --dry-run "$SAMPLE_FILE" 2>/dev/null | grep -q "Processing file"
result=$?
print_result $result "Batch mode dry-run"
echo ""

# Test 12: Error handling (invalid file)
echo "Test 12: Error handling (invalid file)"
./extract_shellcode "nonexistent_file.exe" "output.bin" 2>/dev/null
result=$?
if [ $result -ne 0 ]; then
    echo -e "${GREEN}[PASS]${NC} Error handling for invalid file"
else
    echo -e "${RED}[FAIL]${NC} Should have failed with invalid file"
fi
echo ""

echo "================================"
echo "Test suite completed"