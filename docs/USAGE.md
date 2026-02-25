# Usage Guide

`purl_diver` is a command-line tool designed for simplicity and efficiency. After [compiling the tool](BUILD.md), you can run it from your terminal.

## Installation (Optional)

You can install `purl_diver` globally to make it accessible from any terminal session without needing to specify the path to the executable.

```bash
sudo make install
```
This will copy the `purl_diver` binary to `/usr/local/bin`.

## Command-Line Syntax

The tool supports two main modes: single-file extraction and batch processing.

**Single-File Mode:**
```bash
# If installed globally
purl_diver [options] <input_pe_file> [output_file]

# If running from the project directory
./purl_diver [options] <input_pe_file> [output_file]
```
- `<input_pe_file>`: The single PE file (e.g., `.exe`, `.dll`) to process.
- `[output_file]`: Optional. The path for the output file. If omitted, non-binary formats print to `stdout`, while binary format requires an output path.

**Batch Processing Mode:**
```bash
purl_diver --batch <input_dir> [batch_options]
```
- `--batch <input_dir>`: Enables batch mode and specifies the directory containing PE files to process.
- `[batch_options]`: Additional options to control batch processing (see below).

On Windows, you would run the executable as follows:
```bash
purl_diver.exe [options] <input_pe_file> [output_file]
```

## Options

### General Options
- `-v, --verbose`: Enable verbose output, showing detailed processing information.
- `--hash`: Calculate and display the SHA256 and MD5 hashes of the extracted code. (short form: `-h`)
- `--entropy`: Calculate and display the entropy of the extracted code. (short form: `-e`)
- `--imports-exports`: Analyze and display the PE file's import and export tables. (short form: `-i`)
- `--help`: Display usage information and exit.
- `--version`: Display version information.

### Output and Filtering Options
- `-f, --format <type>`: Output format for single-file mode. Accepted values: `binary`, `c` (or `c-array`), `python`, `hex` (or `hex-dump`), `json`. Default: `binary`. Unknown values are rejected with a non-zero exit code.
- `--include <section>`: Only extract the named section (e.g., `.text`). May be specified multiple times.
- `--exclude <section>`: Exclude the named section from extraction. May be specified multiple times.
- `--min-size <bytes>`: Minimum section size in bytes to be considered for extraction. Must be a non-negative integer.

### Batch Processing Options
- `--batch <dir>`: Process all PE files in the specified directory.
- `--batch-output-dir <dir>`: Directory where batch output files will be saved. Defaults to the current directory.
- `--batch-pattern <pattern>`: Comma-separated file patterns to match (e.g., `"*.exe,*.dll"`). Default is `*.exe,*.dll,*.sys`.
- `--batch-recursive`: Process subdirectories recursively.
- `--batch-log <file>`: Log the summary of the batch processing to a specified file.
- `--batch-format <format>`: Output format for all files in the batch job (`binary`, `c`, `python`, `hex`, `json`). Defaults to `binary`.

## Examples

### Basic Usage

Suppose you have a PE file named `payload.exe` and you want to extract its executable code into a file named `shellcode.bin`.

You would run the following command:

```bash
purl_diver payload.exe shellcode.bin
```

If successful, the tool will print a confirmation message indicating the number of bytes extracted:
```
[+] Success: Extracted 8192 bytes from 3 sections to 'shellcode.bin'.
```

The resulting `shellcode.bin` file will contain the raw, concatenated code from the executable sections of `payload.exe`.

### Verbose Mode

To enable verbose output showing detailed processing information:

```bash
purl_diver -v payload.exe shellcode.bin
```

This will output information such as:
```
[INFO] Input file is an executable.
[INFO] Entry point RVA: 0x1000
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Success: Extracted 1024 bytes from 1 sections to 'shellcode.bin'.
```

### Help

To display usage information:

```bash
purl_diver --help
```

## Error and Warning Messages

The tool provides informative messages to `stdout` and `stderr` to help diagnose issues.

### Errors

Error messages start with `[-]` and indicate a fatal problem that prevented the extraction from completing. Common errors include:

- `[-] Error: Failed to open input file '<file>'.`
  - The specified input file could not be found or accessed.
- `[-] Error: Not a valid PE file (Invalid DOS signature).`
  - The input file does not appear to be a valid executable.
- `[-] Error: Invalid PE signature.`
  - The file has a valid DOS header but is missing the PE signature.
- `[-] Error: Unsupported architecture (Machine: 0x...).`
  - The PE file is for an architecture other than x86 or x64.
- `[-] Error: Memory allocation failed...`
  - The tool could not allocate enough memory to process the file.
- `[-] Error: File too large (max 500 MB).`
  - The input file exceeds the 500MB size limit to prevent resource exhaustion.

### Warnings

Warning messages start with `[!]` and indicate non-fatal issues. The extraction may still produce a result, but it might not be what you expect.

- `[!] Warning: No executable sections found.`
  - The tool could not find any sections marked as executable in the PE file. The output file will not be created.
- `[!] Warning: Skipping overlapping section '<name>'.`
  - The PE file contains at least two executable sections that occupy the same space in the file. To prevent data corruption, the tool processes the first section and skips the subsequent overlapping one(s).
- `[!] Warning: All executable sections were overlapping or empty.`
  - Executable sections were found, but none could be used to generate the output.

### Informational Messages

Informational messages start with `[INFO]` and provide additional analysis details in verbose mode.

- `[INFO] Input file is a DLL.`
  - The input file is identified as a Dynamic Link Library rather than an executable.
- `[INFO] Input file is an executable.`
  - The input file is identified as a standard executable.
- `[INFO] Entry point RVA: 0xXXXX`
  - Reports the Relative Virtual Address of the executable's entry point.
- `[INFO] Entry point is in section 'XXXX'`
  - Identifies which section contains the entry point of the executable.