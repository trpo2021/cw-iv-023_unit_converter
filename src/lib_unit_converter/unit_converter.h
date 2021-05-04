#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _unit {
    char* key;
    double value;
} unit;

typedef struct _category {
    char* key;
    unit* units;
} category;

void get_word(int p1, int p2, category* arr_cat, char* buf);
unit* get_unit(char* buf, int i, int k);
category* get_category(FILE* file);