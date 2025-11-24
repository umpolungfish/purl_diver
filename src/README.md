# Source Code Structure

This directory contains the modularized source code for purl_diver.

## Current Status

**Phase 1 (Foundation) - In Progress**

### Completed:
- ✅ Build system (Makefile + CMake)
- ✅ Directory structure (src/, include/, tests/)
- ✅ Error code enum system (include/error_codes.h, src/error_codes.c)
- ✅ PE types abstraction (include/pe_types.h)

### In Progress:
- 🔄 Extracting modules from monolithic extract_shellcode.c

## Planned Module Structure

```
src/
├── main.c                    # Entry point, argument parsing
├── pe_parser.c               # PE structure parsing & validation
├── section_analyzer.c        # Section detection & filtering
├── hash_algorithms.c         # MD5/SHA256 implementations
├── entropy.c                 # Entropy calculation
├── import_export.c           # Import/export analysis
├── output_formats.c          # All output format handlers
├── utils.c                   # Helper functions
└── error_codes.c             # Error code utilities

include/
├── pe_types.h                # PE structure definitions
├── pe_parser.h               # PE parser interface
├── section_analyzer.h        # Section analysis interface
├── hash_algorithms.h         # Hash function interface
├── entropy.h                 # Entropy calculation interface
├── import_export.h           # Import/export analysis interface
├── output_formats.h          # Output format interface
├── utils.h                   # Utility functions interface
└── error_codes.h             # Error code definitions
```

## Migration Strategy

The original `extract_shellcode.c` (2386 lines) will be gradually refactored into modules:

1. **Phase 1**: Foundation (✅ Complete)
   - Build system setup
   - Error codes
   - Type definitions

2. **Phase 2**: Core modules
   - PE parser extraction
   - Section analyzer extraction
   - Utils extraction

3. **Phase 3**: Specialized modules
   - Hash algorithms
   - Entropy calculation
   - Import/export analysis
   - Output formats

4. **Phase 4**: Integration
   - Main entry point
   - Update build files
   - Update tests

## Building

The original monolithic file can still be built:
```bash
make
```

Once modularization is complete, CMake will handle multi-file builds automatically.
