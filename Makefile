# Makefile for purl_diver PE Shellcode Extractor
# Cross-platform build system

# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lm

# Target executables
TARGET = extract_shellcode
TARGET_MODULAR = purl_diver
DEMO_TARGET = extract_shellcode_demo

# Source files
SRC = extract_shellcode.c
MODULE_SRC = src/error_codes.c src/pe_parser.c src/hash_algorithms.c src/entropy.c \
             src/section_analyzer.c src/output_formats.c src/import_export_analyzer.c \
             src/utils.c src/options.c
MODULAR_SRC = src/main.c $(MODULE_SRC)
DEMO_SRC = src/main_modular.c src/error_codes.c src/pe_parser.c
ALL_SRC = $(SRC)

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    PLATFORM = linux
endif
ifeq ($(UNAME_S),Darwin)
    PLATFORM = macos
endif
ifeq ($(OS),Windows_NT)
    PLATFORM = windows
    TARGET = extract_shellcode.exe
endif

# Build targets
.PHONY: all clean debug asan ubsan release install test help modular demo

all: $(TARGET_MODULAR)

legacy: $(TARGET)

modular: $(TARGET_MODULAR)

demo: $(DEMO_TARGET)

$(TARGET): $(ALL_SRC)
	@echo "[BUILD] Compiling $(TARGET) (monolithic - LEGACY) for $(PLATFORM)..."
	$(CC) $(CFLAGS) $(ALL_SRC) -o $@ $(LDFLAGS)
	@echo "[BUILD] Build successful!"

$(TARGET_MODULAR): $(MODULAR_SRC)
	@echo "[BUILD] Compiling $(TARGET_MODULAR) (full modular version) for $(PLATFORM)..."
	@echo "[BUILD] Modules: error_codes pe_parser hash_algorithms entropy section_analyzer"
	@echo "[BUILD]          output_formats import_export_analyzer utils options main"
	$(CC) $(CFLAGS) $(MODULAR_SRC) -o $@ $(LDFLAGS)
	@echo "[BUILD] ✓ Modular build successful!"
	@echo "[BUILD] Binary: $(TARGET_MODULAR)"

$(DEMO_TARGET): $(DEMO_SRC)
	@echo "[BUILD] Compiling $(DEMO_TARGET) (simple demo) for $(PLATFORM)..."
	$(CC) $(CFLAGS) $(DEMO_SRC) -o $@ $(LDFLAGS)
	@echo "[BUILD] Demo build successful!"

# Debug build with symbols
debug: CFLAGS += -g -DDEBUG -O0
debug: clean
	@echo "[BUILD] Building debug version..."
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(TARGET) $(LDFLAGS)
	@echo "[BUILD] Debug build complete!"

# Address Sanitizer build
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g -O1
asan: LDFLAGS += -fsanitize=address
asan: clean
	@echo "[BUILD] Building with AddressSanitizer..."
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(TARGET) $(LDFLAGS)
	@echo "[BUILD] ASan build complete!"

# Undefined Behavior Sanitizer build
ubsan: CFLAGS += -fsanitize=undefined -fno-omit-frame-pointer -g -O1
ubsan: LDFLAGS += -fsanitize=undefined
ubsan: clean
	@echo "[BUILD] Building with UndefinedBehaviorSanitizer..."
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(TARGET) $(LDFLAGS)
	@echo "[BUILD] UBSan build complete!"

# Release build with maximum optimization
release: CFLAGS += -O3 -DNDEBUG -flto
release: LDFLAGS += -flto
release: clean
	@echo "[BUILD] Building optimized release version..."
	$(CC) $(CFLAGS) $(ALL_SRC) -o $(TARGET) $(LDFLAGS)
	strip $(TARGET)
	@echo "[BUILD] Release build complete!"

# Install to system
install: release
	@echo "[INSTALL] Installing $(TARGET) to /usr/local/bin..."
	install -m 755 $(TARGET) /usr/local/bin/
	@echo "[INSTALL] Installation complete!"

# Run test suite
test: $(TARGET)
	@echo "[TEST] Running test suite..."
	@if [ -f test_suite.sh ]; then \
		bash test_suite.sh; \
	else \
		echo "[TEST] test_suite.sh not found!"; \
		exit 1; \
	fi

# Static analysis with clang-tidy (if available)
analyze:
	@echo "[ANALYZE] Running static analysis..."
	@if command -v clang-tidy >/dev/null 2>&1; then \
		clang-tidy $(SRC) -- $(CFLAGS); \
	else \
		echo "[ANALYZE] clang-tidy not found, skipping..."; \
	fi

# Format code with clang-format (if available)
format:
	@echo "[FORMAT] Formatting code..."
	@if command -v clang-format >/dev/null 2>&1; then \
		clang-format -i $(SRC); \
		echo "[FORMAT] Code formatted!"; \
	else \
		echo "[FORMAT] clang-format not found, skipping..."; \
	fi

# Clean build artifacts
clean:
	@echo "[CLEAN] Removing build artifacts..."
	rm -f $(TARGET) $(TARGET_MODULAR) $(DEMO_TARGET)
	rm -f extract_shellcode extract_shellcode.exe extract_shellcode_modular purl_diver
	rm -f *.o *.out *.bin *.dSYM
	rm -rf *.dSYM/ src/*.o include/*.gch
	@echo "[CLEAN] Clean complete!"

# Help message
help:
	@echo "purl_diver Build System - Modular Edition"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Build modular version (recommended)"
	@echo "  make modular      - Build full modular version (purl_diver)"
	@echo "  make legacy       - Build legacy monolithic version"
	@echo "  make demo         - Build simple demo version"
	@echo "  make debug        - Build with debug symbols"
	@echo "  make asan         - Build with AddressSanitizer"
	@echo "  make ubsan        - Build with UBSan"
	@echo "  make release      - Build optimized release"
	@echo "  make install      - Install to /usr/local/bin"
	@echo "  make test         - Run test suite"
	@echo "  make analyze      - Run static analysis"
	@echo "  make format       - Format source code"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help"
	@echo ""
	@echo "Platform: $(PLATFORM)"
	@echo "Compiler: $(CC)"
	@echo ""
	@echo "Modular architecture with 9 separate modules for improved maintainability"
