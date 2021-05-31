#include "unit_converter.h"

static void tolower_str(char* str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        str[i] = tolower(str[i]);
    }
}

static char* get_name(char* str, int i)
{
    int j;
    char* name = NULL;
    if (isalpha(str[i]) != 0) {
        j = i;
        while (isalpha(str[i]) != 0 || str[i] == '/') {
            i++;
        }
        if (str[i] == '^' && isdigit(str[i + 1]) != 0) {
            i += 2;
        }
        name = calloc(i - j, sizeof(char));
        if (name == NULL) {
            return NULL;
        }
        for (int index = 0; j < i; j++, index++) {
            name[index] = str[j];
        }
        return name;
    }
    return NULL;
}

static double get_value(char in_str[])
{
    int i = 0;
    while (isdigit(in_str[i]) == 0) {
        i++;
    }
    double value = atof(&in_str[i]);
    return value;
}

static double get_factor(char* in_str, int index, int number, category* arr_cat)
{
    int i = 0;
    if (number == 1) {
        while (in_str[i] != '(') {
            i++;
        }
        i++;
    }
    if (number == 2) {
        while (in_str[i] != ' ') {
            i++;
        }
        i++;
    }
    char* str_tmp = get_name(in_str, i);
    if (str_tmp == NULL) {
        return ERROR_EXTRACT_NAME;
    }
    tolower_str(str_tmp);
    for (i = 0; i < arr_cat[index].units_counter; i++) {
        tolower_str(arr_cat[index].units[i].name);
        if (strcmp(str_tmp, arr_cat[index].units[i].name) == 0) {
            double unit_factor = arr_cat[index].units[i].factor;
            return unit_factor;
            break;
        }
    }
    return UNIT_NOT_FOUND;
}

static int get_index_cat(char* in_str, category* arr_cat, int counter_cat)
{
    int i = 0;
    char* str_tmp = get_name(in_str, i);
    if (str_tmp == NULL) {
        return ERROR_EXTRACT_NAME;
    }
    tolower_str(str_tmp);
    for (i = 0; i < counter_cat; i++) {
        tolower_str(arr_cat[i].name);
        if (strcmp(str_tmp, arr_cat[i].name) == 0) {
            return i;
        }
    }
    return CATEGORY_NOT_FOUND;
}

double convert(char* in_str, category* arr_cat, int counter_cat)
{
    int first_factor = 1, second_factor = 2;
    double factor_from, factor_in, value;
    int index = get_index_cat(in_str, arr_cat, counter_cat);
    if (index < 0) {
        return index;
    }
    factor_from = get_factor(in_str, index, first_factor, arr_cat);
    factor_in = get_factor(in_str, index, second_factor, arr_cat);
    if (factor_from < 0) {
        return factor_from;
    } else if (factor_in < 0) {
        return factor_in;
    } else if (factor_from == factor_in) {
        return IDENTICAL_UNITS;
    }
    value = get_value(in_str);

    return calculat(index, factor_from, factor_in, value, arr_cat);
}

double calculat(
        int index,
        double factor_from,
        double factor_in,
        double value,
        category* arr_cat)
{
    if (strcmp(arr_cat[index].name, "speed") == 0) {
        return value * (1 / factor_from) * factor_in;
    } else {
        return value * (factor_from / factor_in);
    }
}
