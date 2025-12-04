# CMake configuration for purl_diver PE Shellcode Extractor
cmake_minimum_required(VERSION 3.10)
project(purl_diver VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Build options
option(BUILD_TESTING "Build test suite" ON)
option(ENABLE_ASAN "Enable Address Sanitizer" OFF)
option(ENABLE_UBSAN "Enable Undefined Behavior Sanitizer" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)
option(STATIC_BUILD "Build static binary" OFF)

# Platform detection
if(WIN32)
    set(PLATFORM "Windows")
elseif(APPLE)
    set(PLATFORM "macOS")
elseif(UNIX)
    set(PLATFORM "Linux")
else()
    set(PLATFORM "Unknown")
endif()

message(STATUS "Building for platform: ${PLATFORM}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")

# Source files
set(SOURCES
    src/purl_diver.c          # Main monolithic file (temporary)
    src/error_codes.c            # Error code utilities
    src/pe_parser.c              # PE parsing and validation
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create executable
add_executable(purl_diver ${SOURCES})

# Compiler-specific flags
if(MSVC)
    # MSVC-specific flags
    target_compile_options(purl_diver PRIVATE
        /W4          # Warning level 4
        /WX-         # Don't treat warnings as errors (for now)
        /O2          # Optimize for speed
        /EHsc        # Exception handling model
    )
    if(STATIC_BUILD)
        set_property(TARGET purl_diver PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
else()
    # GCC/Clang flags
    target_compile_options(purl_diver PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Debug>:-O0 -g>
    )

    # Add _GNU_SOURCE for strdup on Linux
    if(UNIX AND NOT APPLE)
        target_compile_definitions(purl_diver PRIVATE _GNU_SOURCE)
    endif()

    if(STATIC_BUILD)
        target_link_options(purl_diver PRIVATE -static)
    endif()
endif()

# Platform-specific libraries
if(UNIX AND NOT APPLE)
    # Link math library on Linux
    target_link_libraries(purl_diver PRIVATE m)
elseif(APPLE)
    # Link math library on macOS
    target_link_libraries(purl_diver PRIVATE m)
endif()

# Address Sanitizer
if(ENABLE_ASAN)
    if(MSVC)
        target_compile_options(purl_diver PRIVATE /fsanitize=address)
    else()
        target_compile_options(purl_diver PRIVATE
            -fsanitize=address
            -fno-omit-frame-pointer
            -g
        )
        target_link_options(purl_diver PRIVATE -fsanitize=address)
    endif()
    message(STATUS "Address Sanitizer: ENABLED")
endif()

# Undefined Behavior Sanitizer
if(ENABLE_UBSAN)
    if(NOT MSVC)
        target_compile_options(purl_diver PRIVATE
            -fsanitize=undefined
            -fno-omit-frame-pointer
            -g
        )
        target_link_options(purl_diver PRIVATE -fsanitize=undefined)
        message(STATUS "Undefined Behavior Sanitizer: ENABLED")
    else()
        message(WARNING "UBSan not supported on MSVC")
    endif()
endif()

# Code coverage
if(ENABLE_COVERAGE)
    if(NOT MSVC)
        target_compile_options(purl_diver PRIVATE --coverage)
        target_link_options(purl_diver PRIVATE --coverage)
        message(STATUS "Code Coverage: ENABLED")
    else()
        message(WARNING "Coverage not supported on MSVC")
    endif()
endif()

# Installation
install(TARGETS purl_diver
    RUNTIME DESTINATION bin
    COMPONENT runtime
)

# Install documentation
install(FILES
    README.md
    UNLICENSE.md
    DOCS/BUILD.md
    DOCS/USAGE.md
    DOCS/SECURITY.md
    DOCS/TROUBLESHOOTING.md
    DOCS/OPTIMIZATIONS.md
    CLAUDE.md
    DESTINATION share/doc/purl_diver
    COMPONENT documentation
)

# Testing
if(BUILD_TESTING)
    enable_testing()

    # Basic functionality test
    add_test(
        NAME help_output
        COMMAND purl_diver --help
    )

    # Shell test suite integration
    find_program(BASH_PROGRAM bash)
    if(BASH_PROGRAM)
        add_test(
            NAME shell_test_suite
            COMMAND ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/test_suite.sh
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
        # Copy test suite to build directory
        configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/test_suite.sh
            ${CMAKE_CURRENT_BINARY_DIR}/test_suite.sh
            COPYONLY
        )
    endif()

    message(STATUS "Testing: ENABLED")
endif()

# Print configuration summary
message(STATUS "")
message(STATUS "========================================")
message(STATUS "purl_diver Configuration Summary")
message(STATUS "========================================")
message(STATUS "Version:           ${PROJECT_VERSION}")
message(STATUS "Platform:          ${PLATFORM}")
message(STATUS "Build Type:        ${CMAKE_BUILD_TYPE}")
message(STATUS "C Standard:        C${CMAKE_C_STANDARD}")
message(STATUS "C Compiler:        ${CMAKE_C_COMPILER}")
message(STATUS "Install Prefix:    ${CMAKE_INSTALL_PREFIX}")
message(STATUS "")
message(STATUS "Options:")
message(STATUS "  Testing:         ${BUILD_TESTING}")
message(STATUS "  Address Sanitizer: ${ENABLE_ASAN}")
message(STATUS "  UB Sanitizer:    ${ENABLE_UBSAN}")
message(STATUS "  Coverage:        ${ENABLE_COVERAGE}")
message(STATUS "  Static Build:    ${STATIC_BUILD}")
message(STATUS "========================================")
message(STATUS "")
