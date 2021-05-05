#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_BUF 1024
#define SIZE_INPUT_STR 256

typedef struct _unit {
    char* key;
    double value;
} unit;

typedef struct _category {
    char* key;
    unit* units;
} category;

int get_index_cat(char* input_str, category** arr_cat, int counter_cat);
void* get_word(int i, category* arr_categors, char* buf);
unit* get_unit(char* buf, int i, int k);
category* get_category(FILE* file);
int line_counter(FILE* file);