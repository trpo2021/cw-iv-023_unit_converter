#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_BUF 1024
#define SIZE_INPUT_STR 256

typedef struct _unit {
    double value;
    char* key;
} unit;

typedef struct _category {
    unit* units;
    int units_counter;
    char* key;
} category;

category** database_create(FILE* file, int counter_line);
double get_value(char input_str[]);
double get_factor(char* input_str, int index, int number, category** arr_cat);
int get_index_cat(char* input_str, category** arr_cat, int counter_cat);
void* get_word(int i, category* arr_categors, char* buf);
unit* get_unit(char* buf, int i, int k);
category* get_category(FILE* file);
int line_counter(FILE* file);