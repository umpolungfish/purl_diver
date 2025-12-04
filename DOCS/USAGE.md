# Usage Guide

`purl_diver` is a command-line tool designed for simplicity and efficiency. After [compiling the tool](BUILD.md), you can run it from your terminal.

## Installation (Optional)

You can install `purl_diver` globally to make it accessible from any terminal session without needing to specify the path to the executable.

```bash
sudo make install
```
This will copy the `purl_diver` binary to `/usr/local/bin`.

## Command-Line Syntax

The tool requires at least one argument: the path to the input PE file. The output path is optional.

```bash
# If installed globally
purl_diver [options] <input_pe_file> [output_bin_file]

# If running from the project directory
./purl_diver [options] <input_pe_file> [output_bin_file]
```

- `options`: Optional flags to modify the tool's behavior (see below).
- `<input_pe_file>`: The PE file (e.g., `.exe`, `.dll`) from which you want to extract code.
- `[output_bin_file]`: Optional. The path where the resulting shellcode will be written. If omitted, a default name (`<input_pe_file>.shellcode.bin`) will be used.

On Windows, you would run the executable as follows:
```bash
purl_diver.exe [options] <input_pe_file> [output_bin_file]
```

## Options

The following options are available:

- `-v, --verbose`: Enable verbose output mode, showing detailed processing information.
- `-s, --section <name>`: Include specific section by name (e.g., -s .text).
- `--exclude <name>`: Exclude specific section by name (e.g., --exclude .rsrc).
- `--min-size <bytes>`: Minimum section size to include (in bytes).
- `-f, --format <format>`: Output format: binary, c, python, hex, json (default: binary).
- `--hash`: Include SHA256 hash of extracted code in output.
- `--entropy`: Include entropy calculation of sections.
- `--imports`: Analyze import table (DLLs and functions imported).
- `--batch`: Enable batch processing mode for multiple files.
- `--interactive, -i`: Enable interactive section selection mode.
- `--progress`: Show progress indicator for large files.
- `--output-dir <dir>`: Directory for output files (for batch mode).
- `--dry-run`: Analyze only, don't extract.
- `--help`: Display usage information and exit.

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