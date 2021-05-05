#include "unit_converter.h"

double get_value(char input_str[])
{
    int i = 0;
    while (isdigit(input_str[i]) == 0) {
        i++;
    }
    double value = atof(&input_str[i]);
    return value;
}

int get_index_cat(char* input_str, category** arr_cat, int counter_cat)
{
    int i = 0;
    char str_tmp[6];
    while (input_str[i] != '(' && isalpha(input_str[i]) != 0) {
        str_tmp[i] = input_str[i];
        i++;
    }
    for (i = 0; i < counter_cat; i++) {
        if (strcmp(str_tmp, arr_cat[i]->key) == 0) {
            return i;
        }
    }
    return -1;
}