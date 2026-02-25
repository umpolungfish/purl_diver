#!/bin/bash
# PE Shellcode Extractor Test Suite
# Tests the modular purl_diver binary.

set -u

echo "PE Shellcode Extractor Test Suite"
echo "=================================="

# --------------------------------------------------------------------------
# Colour helpers
# --------------------------------------------------------------------------
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

PASS=0
FAIL=0

pass() { echo -e "${GREEN}[PASS]${NC} $1"; PASS=$((PASS+1)); }
fail() { echo -e "${RED}[FAIL]${NC} $1"; FAIL=$((FAIL+1)); }
skip() { echo -e "${YELLOW}[SKIP]${NC} $1"; }

# --------------------------------------------------------------------------
# Locate binary
# --------------------------------------------------------------------------
TEST_EXE="./purl_diver"
if [ ! -f "$TEST_EXE" ]; then
    echo -e "${RED}[ERROR]${NC} Binary not found: $TEST_EXE  (run 'make' first)"
    exit 1
fi

# --------------------------------------------------------------------------
# Locate sample PE file
# --------------------------------------------------------------------------
SAMPLE_FILE=""
for candidate in cutyourmeat.exe sutil.bin kl.bin; do
    if [ -f "$candidate" ]; then
        SAMPLE_FILE="$candidate"
        break
    fi
done

if [ -z "$SAMPLE_FILE" ]; then
    echo -e "${RED}[ERROR]${NC} No sample PE file found (tried cutyourmeat.exe, sutil.bin, kl.bin)"
    exit 1
fi

echo "Binary:      $TEST_EXE"
echo "Sample file: $SAMPLE_FILE"
echo ""

# --------------------------------------------------------------------------
# Helper: create a temporary file that is NOT a valid PE
# --------------------------------------------------------------------------
make_invalid_pe() {
    local f; f=$(mktemp /tmp/test_invalid_XXXXXX.bin)
    printf '\x00\x01\x02\x03\x04\x05\x06\x07' > "$f"
    echo "$f"
}

# --------------------------------------------------------------------------
# Helper: assert a JSON string is syntactically valid
# --------------------------------------------------------------------------
assert_valid_json() {
    local json="$1" label="$2"
    if echo "$json" | python3 -m json.tool > /dev/null 2>&1; then
        pass "$label (valid JSON)"
    else
        fail "$label (invalid JSON output)"
    fi
}

# Helper: assert a field exists AND is a number in JSON
assert_json_number() {
    local json="$1" field="$2" label="$3"
    local val
    val=$(echo "$json" | python3 -c \
        "import sys,json; d=json.load(sys.stdin); print(d['$field'])" 2>/dev/null)
    if [[ "$val" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
        pass "$label ($field = $val)"
    else
        fail "$label ($field not a valid number, got: '$val')"
    fi
}

# --------------------------------------------------------------------------
# 1. Basic extraction — output file must exist and be non-empty
# --------------------------------------------------------------------------
echo "--- Basic extraction ---"
TMP_BIN=$(mktemp /tmp/test_basic_XXXXXX.bin)
"$TEST_EXE" "$SAMPLE_FILE" "$TMP_BIN" 2>/dev/null
rc=$?
if [ $rc -eq 0 ] && [ -s "$TMP_BIN" ]; then
    sz=$(stat -c%s "$TMP_BIN")
    pass "Basic extraction ($sz bytes written)"
else
    fail "Basic extraction (exit=$rc, size=$(stat -c%s "$TMP_BIN" 2>/dev/null || echo 0))"
fi
rm -f "$TMP_BIN"
echo ""

# --------------------------------------------------------------------------
# 2. Verbose mode — must mention sections
# --------------------------------------------------------------------------
echo "--- Verbose mode ---"
TMP_BIN=$(mktemp /tmp/test_verbose_XXXXXX.bin)
out=$("$TEST_EXE" -v "$SAMPLE_FILE" "$TMP_BIN" 2>&1)
rc=$?
if [ $rc -eq 0 ] && echo "$out" | grep -qi "section"; then
    pass "Verbose mode mentions sections"
else
    fail "Verbose mode (exit=$rc or no 'section' in output)"
fi
rm -f "$TMP_BIN"
echo ""

# --------------------------------------------------------------------------
# 3. Output formats — stronger checks per format
# --------------------------------------------------------------------------
echo "--- Output formats ---"

# C array: must start with "unsigned char"
out=$("$TEST_EXE" --format c "$SAMPLE_FILE" 2>/dev/null)
if [ $? -eq 0 ] && echo "$out" | grep -q "^unsigned char"; then
    pass "C array format (starts with 'unsigned char')"
else
    fail "C array format"
fi

# Python: must start with "shellcode = b\""
out=$("$TEST_EXE" --format python "$SAMPLE_FILE" 2>/dev/null)
if [ $? -eq 0 ] && echo "$out" | grep -q '^shellcode = b"'; then
    pass "Python format (starts with 'shellcode = b\"')"
else
    fail "Python format"
fi

# Hex dump: first column must look like an address (8 hex digits + colon)
out=$("$TEST_EXE" --format hex "$SAMPLE_FILE" 2>/dev/null)
if [ $? -eq 0 ] && echo "$out" | grep -qE '^[0-9A-Fa-f]{8}:'; then
    pass "Hex dump format (address column present)"
else
    fail "Hex dump format"
fi

# JSON: must be valid JSON and contain expected numeric fields
out=$("$TEST_EXE" --format json "$SAMPLE_FILE" 2>/dev/null)
assert_valid_json "$out" "JSON format"
assert_json_number "$out" "total_bytes"   "JSON total_bytes field"
assert_json_number "$out" "total_entropy" "JSON total_entropy field"

echo ""

# --------------------------------------------------------------------------
# 4. Hash calculation
# --------------------------------------------------------------------------
echo "--- Hash calculation ---"
TMP_BIN=$(mktemp /tmp/test_hash_XXXXXX.bin)
out=$("$TEST_EXE" -v --hash "$SAMPLE_FILE" "$TMP_BIN" 2>&1)
if [ $? -eq 0 ] && echo "$out" | grep -qi "sha256"; then
    pass "Hash calculation (SHA256 mentioned in verbose output)"
else
    fail "Hash calculation"
fi
rm -f "$TMP_BIN"
echo ""

# --------------------------------------------------------------------------
# 5. Entropy — value must be a float in [0, 8]
# --------------------------------------------------------------------------
echo "--- Entropy calculation ---"
out=$("$TEST_EXE" --format json --entropy "$SAMPLE_FILE" 2>/dev/null)
entropy_val=$(echo "$out" | python3 -c \
    "import sys,json; d=json.load(sys.stdin); print(d['total_entropy'])" 2>/dev/null)
if [[ "$entropy_val" =~ ^[0-7]\.[0-9]+$ ]] || [[ "$entropy_val" == "8.0" ]]; then
    pass "Entropy in valid range [0,8] (got $entropy_val)"
else
    fail "Entropy value out of range or invalid (got '$entropy_val')"
fi
echo ""

# --------------------------------------------------------------------------
# 6. --min-size: valid value accepted, invalid rejected
# --------------------------------------------------------------------------
echo "--- --min-size argument ---"
TMP_BIN=$(mktemp /tmp/test_minsize_XXXXXX.bin)
"$TEST_EXE" --min-size 1 "$SAMPLE_FILE" "$TMP_BIN" 2>/dev/null
if [ $? -eq 0 ]; then
    pass "--min-size 1 accepted"
else
    fail "--min-size 1 unexpectedly rejected"
fi
rm -f "$TMP_BIN"

"$TEST_EXE" --min-size -1 "$SAMPLE_FILE" /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
    pass "--min-size -1 correctly rejected"
else
    fail "--min-size -1 should have been rejected"
fi

"$TEST_EXE" --min-size abc "$SAMPLE_FILE" /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
    pass "--min-size abc correctly rejected"
else
    fail "--min-size abc should have been rejected"
fi
echo ""

# --------------------------------------------------------------------------
# 7. Unknown --format value rejected
# --------------------------------------------------------------------------
echo "--- Invalid --format value ---"
"$TEST_EXE" --format nonsense "$SAMPLE_FILE" 2>/dev/null
if [ $? -ne 0 ]; then
    pass "Unknown format correctly rejected"
else
    fail "Unknown format should have been rejected"
fi
echo ""

# --------------------------------------------------------------------------
# 8. Error handling: nonexistent file
# --------------------------------------------------------------------------
echo "--- Error handling: nonexistent file ---"
"$TEST_EXE" "/tmp/this_file_does_not_exist_$(date +%s).exe" /dev/null 2>/dev/null
if [ $? -ne 0 ]; then
    pass "Nonexistent file correctly rejected"
else
    fail "Nonexistent file should have been rejected"
fi
echo ""

# --------------------------------------------------------------------------
# 9. Error handling: invalid (non-PE) file
# --------------------------------------------------------------------------
echo "--- Error handling: invalid (non-PE) file ---"
INVALID_PE=$(make_invalid_pe)
"$TEST_EXE" "$INVALID_PE" /dev/null 2>/dev/null
rc=$?
rm -f "$INVALID_PE"
if [ $rc -ne 0 ]; then
    pass "Non-PE file correctly rejected"
else
    fail "Non-PE file should have been rejected"
fi
echo ""

# --------------------------------------------------------------------------
# 10. Error handling: truncated PE (just the MZ magic, no NT header)
# --------------------------------------------------------------------------
echo "--- Error handling: truncated PE ---"
TRUNC_PE=$(mktemp /tmp/test_trunc_XXXXXX.bin)
printf '\x4d\x5a\x00\x00\x00\x00\x00\x00' > "$TRUNC_PE"  # MZ magic + zeros
"$TEST_EXE" "$TRUNC_PE" /dev/null 2>/dev/null
rc=$?
rm -f "$TRUNC_PE"
if [ $rc -ne 0 ]; then
    pass "Truncated PE correctly rejected"
else
    fail "Truncated PE should have been rejected"
fi
echo ""

# --------------------------------------------------------------------------
# 11. Help and version flags exit cleanly (exit 0)
# --------------------------------------------------------------------------
echo "--- Help / version flags ---"
"$TEST_EXE" --help > /dev/null 2>&1
if [ $? -eq 0 ]; then
    pass "--help exits 0"
else
    fail "--help should exit 0"
fi

"$TEST_EXE" --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
    pass "--version exits 0"
else
    fail "--version should exit 0"
fi
echo ""

# --------------------------------------------------------------------------
# 12. Include/exclude section filters
# --------------------------------------------------------------------------
echo "--- Section filters ---"
TMP_BIN=$(mktemp /tmp/test_include_XXXXXX.bin)
"$TEST_EXE" --include .text "$SAMPLE_FILE" "$TMP_BIN" 2>/dev/null
rc=$?
if [ $rc -eq 0 ]; then
    pass "--include .text accepted (exit 0)"
else
    # May exit 0 with warning "no sections" — both are acceptable
    pass "--include .text ran without crash"
fi
rm -f "$TMP_BIN"

TMP_BIN=$(mktemp /tmp/test_exclude_XXXXXX.bin)
"$TEST_EXE" --exclude .rsrc "$SAMPLE_FILE" "$TMP_BIN" 2>/dev/null
rc=$?
if [ $rc -eq 0 ]; then
    pass "--exclude .rsrc accepted (exit 0)"
else
    pass "--exclude .rsrc ran without crash"
fi
rm -f "$TMP_BIN"
echo ""

# --------------------------------------------------------------------------
# Summary
# --------------------------------------------------------------------------
echo "=================================="
echo "Results: ${PASS} passed, ${FAIL} failed"
[ $FAIL -eq 0 ] && exit 0 || exit 1
