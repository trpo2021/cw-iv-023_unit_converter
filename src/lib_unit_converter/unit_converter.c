#include "unit_converter.h"

static double get_value(char input_str[])
{
    int i = 0;
    while (isdigit(input_str[i]) == 0) {
        i++;
    }
    double value = atof(&input_str[i]);
    return value;
}

static double get_factor(char* input_str, int index, int number, category* arr_cat)
{
    int i = 0;
    if (number == 1) {
        while (input_str[i] != '(') {
            i++;
        }
        i++;
    }
    if (number == 2) {
        while (input_str[i] != ',') {
            i++;
        }
        i += 2;
    }
    int j = i;
    while (isalpha(input_str[i]) != 0) {
        i++;
    }
    char* str_tmp = calloc(i - j, sizeof(char));
    for (int t = 0; j < i; t++, j++) {
        str_tmp[t] = input_str[j];
    }
    for (i = 0; i < arr_cat[index].units_counter; i++) {
        if (strcmp(str_tmp, arr_cat[index].units[i].key) == 0) {
            break;
        }
    }
    double unit_factor = arr_cat[index].units[i].value;
    return unit_factor;
}

static void tolower_str(char* str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        str[i] = tolower(str[i]);
    }
}

static int get_index_cat(char* input_str, category* arr_cat, int counter_cat)
{
    int i = 0;
    char str_tmp[6];
    while (input_str[i] != '(' && isalpha(input_str[i]) != 0) {
        str_tmp[i] = input_str[i];
        i++;
    }
    tolower_str(str_tmp);
    for (i = 0; i < counter_cat; i++) {
        tolower_str(arr_cat[i].key);
        if (strcmp(str_tmp, arr_cat[i].key) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(char* input_str, category* arr_cat, int counter_cat)
{
    int first_factor = 1, second_factor = 2;
    double factor_from, factor_in, value;
    int index = get_index_cat(input_str, arr_cat, counter_cat);
    factor_from = get_factor(input_str, index, first_factor, arr_cat);
    factor_in = get_factor(input_str, index, second_factor, arr_cat);
    value = get_value(input_str);

    if (strcmp(arr_cat[index].key, "speed") == 0) {
        return value * (1 / factor_from) * factor_in;
    } else {
        return value * (factor_from / factor_in);
    }
    return -1;
}