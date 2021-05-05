#include "unit_converter.h"

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