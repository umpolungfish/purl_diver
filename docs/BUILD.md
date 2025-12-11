# Build Instructions

`PE Shellcode Extractor` is written in standard C and can be compiled with common C compilers such as MSVC, GCC (MinGW on Windows), and Clang.

## Prerequisites

- A C compiler (MSVC, GCC, or Clang).
- On Windows, you can use the Visual Studio Build Tools or MinGW-w64.
- On Linux, you can install the `build-essential` package (or equivalent).
- On macOS, you can install the Xcode Command Line Tools.

## Compilation Commands

Below are the recommended commands for compiling `extract_shellcode.c` on different platforms. The commands include optimization flags (`/O2` or `-O2`) and warning flags (`/W4` or `-Wall`) to ensure a robust and efficient build.

### Windows (with MSVC)

Open a Developer Command Prompt for Visual Studio and run the following command:

```bash
cl extract_shellcode.c /O2 /W4 /EHsc /Fe:extract_shellcode.exe
```

- `/O2`: Optimizes for speed.
- `/W4`: Enables level 4 warnings (high level of scrutiny).
- `/EHsc`: Specifies the exception-handling model.
- `/Fe:extract_shellcode.exe`: Sets the output executable name.

### Windows (with MinGW-w64)

Open a terminal where the `gcc` command is available (like the one provided by Git Bash or MSYS2) and run:

```bash
gcc extract_shellcode.c -o extract_shellcode.exe -O2 -Wall -lm
```

- `-o extract_shellcode.exe`: Sets the output executable name.
- `-O2`: Optimizes for speed.
- `-Wall`: Enables all standard warnings.
- `-lm`: Links the math library for entropy calculations.

### Linux (with GCC)

Open a terminal and run the following command:

```bash
gcc extract_shellcode.c -o extract_shellcode -O2 -Wall -lm
```

This will produce an executable file named `extract_shellcode`.

- `-lm`: Links the math library for entropy calculations.

### macOS (with Clang)

Open a terminal and run the following command:

```bash
clang extract_shellcode.c -o extract_shellcode -O2 -Wall -lm
```

This will produce an executable file named `extract_shellcode`.

- `-lm`: Links the math library for entropy calculations.

After successful compilation, you will have an executable ready to use. Refer to [USAGE.md](USAGE.md) for instructions on how to run it.
