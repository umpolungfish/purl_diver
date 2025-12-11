# Makefile for PE Shellcode Extractor - Modular Architecture

CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c99 -lm
DEBUG_FLAGS = -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer

# Include directories
INCLUDES = -I. -Iinclude

# Modular source files
MODULAR_SRC = src/main.c \
              src/error_codes.c \
              src/pe_parser.c \
              src/hash_algorithms.c \
              src/entropy.c \
              src/section_analyzer.c \
              src/output_formats.c \
              src/import_export_analyzer.c \
              src/utils.c \
              src/options.c \
              src/batch_processor.c

# Default target builds modular version
all: purl_diver

# Modular executable (recommended)
purl_diver: $(MODULAR_SRC) $(wildcard include/*.h)
	$(CC) $(MODULAR_SRC) -o purl_diver $(CFLAGS) $(INCLUDES)

# Alternative name for modular version
modular: purl_diver

# Legacy executable (monolithic version)
legacy: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode $(CFLAGS)

# Debug build for modular version
debug: $(MODULAR_SRC) $(wildcard include/*.h)
	$(CC) $(MODULAR_SRC) -o purl_diver $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -DDEBUG

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./purl_diver

# Additional security/analysis flags
security: $(MODULAR_SRC) $(wildcard include/*.h)
	$(CC) $(MODULAR_SRC) -o purl_diver $(CFLAGS) -fstack-protector-strong -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security $(INCLUDES)

# Demo build (simplified version)
demo: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode_demo -O2 -Wall

# Clean build artifacts
clean:
	rm -f extract_shellcode purl_diver extract_shellcode_demo tests/test_*

# Install (for system-wide use)
install: purl_diver
	sudo cp purl_diver /usr/local/bin/

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/purl_diver

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build modular version (purl_diver) [default]"
	@echo "  modular   - Build full modular version (purl_diver)"
	@echo "  legacy    - Build legacy monolithic version (extract_shellcode)"
	@echo "  demo      - Build simple demo version"
	@echo "  debug     - Build modular version with debug symbols"
	@echo "  test      - Run all tests"
	@echo "  valgrind  - Run with valgrind for memory checking"
	@echo "  security  - Build with security hardening flags"
	@echo "  clean     - Remove build artifacts"
	@echo "  install   - Install binary to system"
	@echo "  uninstall - Remove installed binary"
	@echo "  help      - Show this help message"

.PHONY: all debug test test_entropy valgrind clean install uninstall modular legacy demo help