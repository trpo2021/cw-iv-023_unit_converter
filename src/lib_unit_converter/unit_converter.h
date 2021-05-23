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

category* database_create(FILE* file, int counter_line);
void free_database(category* arr_categors, int line_counter);
int line_counter(FILE* file);
double convert(char* input_str, category* arr_cat, int counter_cat);
char* build_str_fast(char* input_str, int argc, char** argv);
