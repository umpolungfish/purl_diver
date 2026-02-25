# Makefile for PE Shellcode Extractor - Modular Architecture

CC      = gcc
CFLAGS  = -O2 -Wall -Wextra -Wshadow -Wstrict-prototypes -Wformat=2 -std=c99 -MMD -MP
LDFLAGS = -lm
DEBUG_FLAGS = -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer -DDEBUG

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

# Object and dependency files derived from sources
OBJS = $(MODULAR_SRC:.c=.o)
DEPS = $(OBJS:.o=.d)

# Default target builds modular version
all: purl_diver

# Per-file compilation rule with automatic dependency generation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Include auto-generated header dependencies (silently ignored on first build)
-include $(DEPS)

# Modular executable (recommended)
purl_diver: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Alternative name for modular version
modular: purl_diver

# Legacy executable (monolithic version)
legacy: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode -O2 -Wall $(LDFLAGS)

# Debug build: single-command to avoid mixing debug/release object files
debug: $(MODULAR_SRC) $(wildcard include/*.h)
	$(CC) $(MODULAR_SRC) -o purl_diver $(CFLAGS) $(DEBUG_FLAGS) $(LDFLAGS) $(INCLUDES)

# Test targets
test_entropy: tests/test_entropy.c
	$(CC) tests/test_entropy.c -o tests/test_entropy -O2 -Wall $(LDFLAGS)
	./tests/test_entropy

test_comprehensive: tests/test_comprehensive.c
	$(CC) tests/test_comprehensive.c -o tests/test_comprehensive -O2 -Wall $(LDFLAGS)
	./tests/test_comprehensive

test_hash: tests/test_hash.c src/hash_algorithms.c
	$(CC) tests/test_hash.c src/hash_algorithms.c -o tests/test_hash \
		-O2 -Wall -std=c99 $(INCLUDES) $(LDFLAGS)
	./tests/test_hash

test: test_entropy test_comprehensive test_hash

# Valgrind target for memory checking
valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./purl_diver

# Additional security/analysis flags
security: $(MODULAR_SRC) $(wildcard include/*.h)
	$(CC) $(MODULAR_SRC) -o purl_diver \
		$(CFLAGS) -fstack-protector-strong -D_FORTIFY_SOURCE=2 \
		$(INCLUDES) $(LDFLAGS)

# Demo build (simplified version)
demo: extract_shellcode.c
	$(CC) extract_shellcode.c -o extract_shellcode_demo -O2 -Wall $(LDFLAGS)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(DEPS) purl_diver extract_shellcode extract_shellcode_demo \
		tests/test_entropy tests/test_comprehensive tests/test_hash

# Install (for system-wide use)
install: purl_diver
	sudo cp purl_diver /usr/local/bin/
	sudo mkdir -p /usr/local/share/man/man1
	sudo cp docs/purl_diver.1 /usr/local/share/man/man1/
	sudo gzip -f /usr/local/share/man/man1/purl_diver.1

# Uninstall
uninstall:
	sudo rm -f /usr/local/bin/purl_diver
	sudo rm -f /usr/local/share/man/man1/purl_diver.1.gz

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build modular version (purl_diver) [default]"
	@echo "  modular   - Build full modular version (purl_diver)"
	@echo "  legacy    - Build legacy monolithic version (extract_shellcode)"
	@echo "  demo      - Build simple demo version"
	@echo "  debug     - Build modular version with debug symbols + sanitizers"
	@echo "  test      - Run all tests"
	@echo "  valgrind  - Run with valgrind for memory checking"
	@echo "  security  - Build with security hardening flags"
	@echo "  clean     - Remove build artifacts"
	@echo "  install   - Install binary to system"
	@echo "  uninstall - Remove installed binary"
	@echo "  help      - Show this help message"

.PHONY: all debug test test_entropy test_comprehensive test_hash valgrind clean \
        install uninstall modular legacy demo help security
