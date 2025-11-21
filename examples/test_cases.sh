#!/bin/bash

# Test cases for PE Shellcode Extractor
# This script validates the tool functionality with various inputs and options

echo "PE Shellcode Extractor - Test Cases"
echo "=================================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print test results
print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}[PASS]${NC} $2"
    else
        echo -e "${RED}[FAIL]${NC} $2"
    fi
}

# Setup
TOOL="../extract_shellcode"
SAMPLE="../cutyourmeat.exe"

# Verify tool and sample exist
if [ ! -f "$TOOL" ]; then
    echo -e "${RED}[ERROR]${NC} Tool not found: $TOOL"
    exit 1
fi

if [ ! -f "$SAMPLE" ]; then
    echo -e "${YELLOW}[INFO]${NC} Primary sample not found, trying alternatives..."
    if [ -f "../sutil.bin" ]; then
        SAMPLE="../sutil.bin"
    elif [ -f "../kl.bin" ]; then
        SAMPLE="../kl.bin"
    else
        echo -e "${RED}[ERROR]${NC} No sample files available for testing"
        exit 1
    fi
fi

echo "Using sample: $SAMPLE"
echo ""

# Test 1: Basic extraction
echo "1. Basic Extraction Test"
"$TOOL" "$SAMPLE" "test_basic.bin" 2>/dev/null
result=$?
print_result $result "Basic extraction to binary file"
if [ -f "test_basic.bin" ] && [ $result -eq 0 ]; then
    size=$(stat -c%s "test_basic.bin")
    echo "   Extracted $size bytes"
    rm -f "test_basic.bin"
fi
echo ""

# Test 2: Verbose mode
echo "2. Verbose Mode Test"
"$TOOL" -v "$SAMPLE" "test_verbose.bin" 2>&1 | grep -q "Processing section"
result=$?
print_result $result "Verbose mode output"
if [ -f "test_verbose.bin" ]; then
    rm -f "test_verbose.bin"
fi
echo ""

# Test 3: Output formats
echo "3. Output Format Tests"
formats=("c" "python" "hex" "json")
for format in "${formats[@]}"; do
    echo "   Testing $format format..."
    output=$("$TOOL" --format "$format" "$SAMPLE" 2>/dev/null)
    result=$?
    if [ $result -eq 0 ]; then
        case "$format" in
            "c")
                echo "$output" | grep -q "unsigned char"
                ;;
            "python")
                echo "$output" | grep -q "shellcode = b\""
                ;;
            "hex")
                echo "$output" | head -n 3 | grep -q "00000000"
                ;;
            "json")
                echo "$output" | grep -q '"input_file"'
                ;;
        esac
        format_result=$?
        if [ $format_result -eq 0 ]; then
            print_result 0 "$format format output correct"
        else
            print_result 1 "$format format output incorrect"
        fi
    else
        print_result $result "$format format execution"
    fi
done
echo ""

# Test 4: Advanced features
echo "4. Advanced Features Test"
# Hash calculation
"$TOOL" --hash "$SAMPLE" "test_hash.bin" 2>&1 | grep -q "SHA256:"
hash_result=$?
print_result $hash_result "Hash calculation"

# Entropy calculation in JSON
"$TOOL" --entropy --format json "$SAMPLE" 2>/dev/null | grep -q "total_entropy"
entropy_result=$?
print_result $entropy_result "Entropy calculation"

if [ -f "test_hash.bin" ]; then
    rm -f "test_hash.bin"
fi
echo ""

# Test 5: Import analysis
echo "5. Import Analysis Test"
"$TOOL" --imports "$SAMPLE" "test_imports.bin" 2>&1 | grep -q "IMPORTS ANALYSIS"
imports_result=$?
print_result $imports_result "Import analysis"
if [ -f "test_imports.bin" ]; then
    rm -f "test_imports.bin"
fi
echo ""

# Test 6: Dry-run mode
echo "6. Dry-run Mode Test"
"$TOOL" --dry-run "$SAMPLE" 2>&1 | grep -q "executable sections"
dryrun_result=$?
print_result $dryrun_result "Dry-run mode"
echo ""

# Test 7: Section filtering (if .text exists)
echo "7. Section Filtering Test"
"$TOOL" --section .text "$SAMPLE" "test_section.bin" 2>/dev/null
section_result=$?
if [ $section_result -eq 0 ] && [ -f "test_section.bin" ]; then
    print_result 0 "Section filtering"
    rm -f "test_section.bin"
elif [ $section_result -eq 0 ]; then
    print_result 0 "Section filtering (no matching sections)"
else
    print_result $section_result "Section filtering"
fi
echo ""

# Test 8: Batch mode
echo "8. Batch Mode Test"
"$TOOL" --batch --dry-run "$SAMPLE" 2>&1 | grep -q "Processing file"
batch_result=$?
print_result $batch_result "Batch mode"
echo ""

# Test 9: Progress indication
echo "9. Progress Indicator Test"
"$TOOL" --progress "$SAMPLE" "test_progress.bin" 2>&1 | grep -q "Progress:"
progress_result=$?
print_result $progress_result "Progress indicator"
if [ -f "test_progress.bin" ]; then
    rm -f "test_progress.bin"
fi
echo ""

# Test 10: Error handling
echo "10. Error Handling Test"
"$TOOL" "nonexistent_file.exe" "output.bin" 2>&1 | grep -q "Failed to open"
error_result=$?
print_result $error_result "Error handling for invalid file"
echo ""

# Test 11: Help functionality
echo "11. Help Output Test"
"$TOOL" --help 2>/dev/null | grep -q "Usage:"
help_result=$?
print_result $help_result "Help output"
echo ""

# Cleanup
echo "=================================="
echo "All tests completed."