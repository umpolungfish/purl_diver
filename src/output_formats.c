/**
 * @file output_formats.c
 * @brief Implementation of output formatters for extracted shellcode
 */

#include "../include/output_formats.h"
#include "../include/entropy.h"
#include <stdio.h>
#include <string.h>

void output_as_c_array(unsigned char *data, size_t size, const char *filename) {
    printf("unsigned char %s[] = {", filename ? filename : "shellcode");
    for (size_t i = 0; i < size; i++) {
        if (i % 12 == 0) printf("\n  ");
        printf("0x%02X", data[i]);
        if (i < size - 1) printf(",");
    }
    printf("\n};\n");
}

void output_as_python(unsigned char *data, size_t size, const char *filename) {
    (void)filename;  // Unused parameter
    printf("shellcode = b\"");
    for (size_t i = 0; i < size; i++) {
        printf("\\x%02X", data[i]);
    }
    printf("\"\n");
}

void output_as_hex_dump(unsigned char *data, size_t size, const char *filename) {
    (void)filename;  // Unused parameter
    for (size_t i = 0; i < size; i += 16) {
        printf("%08zX: ", i);
        for (int j = 0; j < 16; j++) {
            if (i + j < size) {
                printf("%02X ", data[i + j]);
            } else {
                printf("   ");
            }
            if (j == 7) printf(" ");
        }
        printf(" |");
        for (int j = 0; j < 16; j++) {
            if (i + j < size) {
                unsigned char c = data[i + j];
                printf("%c", (c >= 32 && c <= 126) ? c : '.');
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

void output_as_json(unsigned char *data, size_t size, const char *input_path,
                    PIMAGE_SECTION_HEADER *valid_sections, size_t num_valid_sections,
                    DWORD entry_point_rva, WORD machine) {
    printf("{\n");
    printf("  \"input_file\": \"%s\",\n", input_path);
    printf("  \"architecture\": \"%s\",\n", (machine == IMAGE_FILE_MACHINE_I386) ? "x86" : "x64");
    printf("  \"entry_point_rva\": %u,\n", entry_point_rva);
    printf("  \"sections_extracted\": %zu,\n", num_valid_sections);
    printf("  \"total_bytes\": %zu,\n", size);
    printf("  \"total_entropy\": %.4f,\n", calculate_entropy(data, size));
    printf("  \"sections\": [\n");

    for (size_t i = 0; i < num_valid_sections; i++) {
        PIMAGE_SECTION_HEADER section = valid_sections[i];
        char section_name[IMAGE_SIZEOF_SHORT_NAME + 1];
        memcpy(section_name, section->Name, IMAGE_SIZEOF_SHORT_NAME);
        section_name[IMAGE_SIZEOF_SHORT_NAME] = '\0';

        // Properly escape the section name to ensure valid JSON
        printf("    {\n");
        printf("      \"name\": \"");
        for (int j = 0; j < IMAGE_SIZEOF_SHORT_NAME && section_name[j] != '\0'; j++) {
            if (section_name[j] == '\\' || section_name[j] == '"') {
                printf("\\%c", section_name[j]);
            } else if (section_name[j] == '\b') {
                printf("\\b");
            } else if (section_name[j] == '\f') {
                printf("\\f");
            } else if (section_name[j] == '\n') {
                printf("\\n");
            } else if (section_name[j] == '\r') {
                printf("\\r");
            } else if (section_name[j] == '\t') {
                printf("\\t");
            } else {
                printf("%c", section_name[j]);
            }
        }
        printf("\",\n");
        printf("      \"size\": %u,\n", section->SizeOfRawData);
        printf("      \"virtual_address\": %u,\n", section->VirtualAddress);
        printf("      \"raw_data_offset\": %u,\n", section->PointerToRawData);
        printf("      \"characteristics\": %u\n", section->Characteristics);

        if (i < num_valid_sections - 1) {
            printf("    },\n");
        } else {
            printf("    }\n");
        }
    }
    printf("  ]\n");
    printf("}\n");
}
