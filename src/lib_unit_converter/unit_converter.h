#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_BUF 1024
#define SIZE_INPUT_STR 256
#define TOLL 1e-6

typedef struct unit {
    char* key;
    double value;
} unit;

typedef struct category {
    char* key;
    unit* units;
    int units_counter;
} category;

enum ERROR_CODE {
    CATEGORY_NOT_FOUND = -1,
    UNIT_NOT_FOUND = -2,
    VALUE_NOT_FOUND = -3,
    NO_OPENING_PARENTHESIS = -4,
    NO_CLOSING_PARENTHESIS = -5,
    NO_SEPARATING_COMMA = -6,
    EXPECTED_UNIT = -7,
    EXPECTED_UNSIGNED_DOUBLE = -8,
    UNEXPECTED_TOKEN = -9,
    ERROR_EXTRACT_NAME = -10,
    ERROR_MEMORY_ALLOCATIONS = -11,
    EXPECTED_CATEGORY_NAME = -12
};

category* database_create(FILE* file, int counter_line);
void free_database(category* arr_categors, int line_counter);
int line_counter(FILE* file);
double convert(char* input_str, category* arr_cat, int counter_cat);
char* build_str_fast(char* input_str, int argc, char** argv);
int correct_input_str(char* input_str, char** correct_str);
void print_errors(int code_error);
int help();
