# Makefile for PE Shellcode Extractor

CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c99 -lm
DEBUG_FLAGS = -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer

# Include directories
INCLUDES = -I.

# Default target
all: extract_shellcode

# Main executable
extract_shellcode: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode $(CFLAGS)

# Debug build
debug: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode $(CFLAGS) $(DEBUG_FLAGS) -DDEBUG

# Test targets
test_entropy: tests/test_entropy.c
	$(CC) tests/test_entropy.c -o tests/test_entropy -lm -O2 -Wall
	./tests/test_entropy

test_comprehensive: tests/test_comprehensive.c
	$(CC) tests/test_comprehensive.c -o tests/test_comprehensive -lm -O2 -Wall
	./tests/test_comprehensive

test: test_entropy test_comprehensive

# Valgrind target for memory checking
valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./extract_shellcode

# Additional security/analysis flags
security: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode $(CFLAGS) -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security

# Clean build artifacts
clean:
	rm -f extract_shellcode tests/test_*

# Install (for system-wide use)
install: extract_shellcode
	sudo cp extract_shellcode /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/extract_shellcode

.PHONY: all debug test test_entropy valgrind clean install uninstall