#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_BUF 1024


typedef struct _unit {
    char* key;
    double value;
} unit;

typedef struct _category {
    char* key;
    unit* units;
} category;

void* get_word(int i, category* arr_categors, char* buf);
unit* get_unit(char* buf, int i, int k);
category* get_category(FILE* file);
int line_counter(FILE* file);