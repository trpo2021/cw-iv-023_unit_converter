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
        while (isalpha(str[i]) != 0) {
            i++;
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
        if (strcmp(str_tmp, arr_cat[index].units[i].key) == 0) {
            double unit_factor = arr_cat[index].units[i].value;
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
        tolower_str(arr_cat[i].key);
        if (strcmp(str_tmp, arr_cat[i].key) == 0) {
            return i;
        }
    }
    return CATEGORY_NOT_FOUND;
}

double converting(char* in_str, category* arr_cat, int counter_cat)
{
    int first_factor = 1, second_factor = 2;
    double factor_from, factor_in, value;
    int index = get_index_cat(in_str, arr_cat, counter_cat);
    if (index == CATEGORY_NOT_FOUND) {
        return CATEGORY_NOT_FOUND;
    } else if (index == ERROR_EXTRACT_NAME) {
        return ERROR_EXTRACT_NAME;
    }
    factor_from = get_factor(in_str, index, first_factor, arr_cat);
    factor_in = get_factor(in_str, index, second_factor, arr_cat);
    if (factor_from == UNIT_NOT_FOUND || factor_in == UNIT_NOT_FOUND) {
        return UNIT_NOT_FOUND;
    } else if (
            factor_from == ERROR_EXTRACT_NAME
            || factor_in == ERROR_EXTRACT_NAME) {
        return ERROR_EXTRACT_NAME;
    }
    value = get_value(in_str);

    return calculating(index, factor_from, factor_in, value, arr_cat);
}

double calculating(
        int index,
        double factor_from,
        double factor_in,
        double value,
        category* arr_cat)
{
    if (strcmp(arr_cat[index].key, "speed") == 0) {
        return value * (1 / factor_from) * factor_in;
    } else {
        return value * (factor_from / factor_in);
    }
}

char* build_str_fast(char* input_str, int argc, char** argv)
{
    int i = 2;
    int sum_of_symbols = 0;
    while (i < argc) {
        strcat(input_str, argv[i]);
        sum_of_symbols += strlen(argv[i]);
        if ((i == 3) || (i == 4)) {
            input_str[sum_of_symbols] = ' ';
            sum_of_symbols++;
        }
        if (i == 2) {
            input_str[sum_of_symbols] = '(';
            sum_of_symbols++;
        }
        if (i == 5) {
            input_str[sum_of_symbols] = ')';
            sum_of_symbols++;
        }
        i++;
    }
    input_str[sum_of_symbols] = '\n';
    return input_str;
}

#define MAX_SIZE_OF_FILE 1000
int help()
{
    char button;
    FILE* page = fopen("help/greeting.txt", "r");
    if (page == NULL) {
        printf("Can`t open file\n");
    }
    fseek(page, sizeof(char), SEEK_END);
    int size_of_file = MAX_SIZE_OF_FILE;
    char* page_str = calloc(size_of_file, sizeof(char));
    rewind(page);
    fread(page_str, sizeof(char), size_of_file, page);
    fprintf(stdout, "%s", page_str);
    while (1) {
        scanf("%c", &button);
        switch (button) {
        case 0x31:
            page = fopen("help/page_1.txt", "r");
            if (page == NULL) {
                printf("Can`t open file\n");
            }
            while ((getchar()) != '\n')
                ;
            memset(page_str, 0, size_of_file);
            fread(page_str, sizeof(char), size_of_file, page);
            fprintf(stdout, "%s", page_str);
            break;

        case 0x32:
            page = fopen("help/page_2.txt", "r");
            if (page == NULL) {
                printf("Can`t open file\n");
            }
            while ((getchar()) != '\n')
                ;
            memset(page_str, 0, 256);
            fread(page_str, sizeof(char), size_of_file, page);
            fprintf(stdout, "%s", page_str);
            break;

        case 0x71:
            fclose(page);
            free(page_str);
            return 0;
            break;

        case 0x51:
            free(page_str);
            fclose(page);
            return 0;
            break;

        default:
            printf("Неизвестная страница!\n");
        }
    }
    free(page_str);
    fclose(page);
    return 0;
}
