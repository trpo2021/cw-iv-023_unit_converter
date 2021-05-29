#include "unit_converter.h"

static int skip_space(char* input_str, int i)
{
    while (input_str[i] == ' ') {
        i++;
    }
    return i;
}

static int check_unit(char* input_str, int i, int* k)
{
    if (isalpha(input_str[i]) != 0) {
        while (isalpha(input_str[i]) != 0) {
            i++;
            (*k)++;
        }
    } else {
        return EXPECTED_UNIT;
    }
    return i;
}

static int check_value(char* input_str, int i, int* k)
{
    short check_point = 0;
    if (input_str[i] == '-') {
        return EXPECTED_UNSIGNED_DOUBLE;
    }
    if (input_str[i] == '0') {
        return INCORRECT_NUMBER_ENTRY;
    }
    if (isdigit(input_str[i]) != 0) {
        while ((isdigit(input_str[i]) != 0) || (input_str[i] == '.')) {
            if ((input_str[i] == '.') && (check_point == 1)) {
                return EXPECTED_UNSIGNED_DOUBLE;
            } else {
                check_point = 1;
            }
            i++;
            (*k)++;
        }
    } else {
        return VALUE_NOT_FOUND;
    }
    return i;
}

static int check_category(char* input_str, int i, int* k)
{
    int check_parenthesis = 0;
    for (; input_str[i] != '\n'; i++, (*k)++) {
        if (isalpha(input_str[i]) == 0) {
            i = skip_space(input_str, i);
            if (input_str[i] == '(') {
                if ((*k) == 0) {
                    return EXPECTED_CATEGORY_NAME;
                }
                (*k)++;
                i++;
                check_parenthesis = 1;
                break;
            } else if ((*k) == 0) {
                return EXPECTED_CATEGORY_NAME;
            } else {
                return NO_OPENING_PARENTHESIS;
            }
        }
    }
    if ((*k) == 0) {
        return EXPECTED_CATEGORY_NAME;
    } else if (check_parenthesis == 0) {
        return NO_OPENING_PARENTHESIS;
    }
    return i;
}

static int checking_str_errors(char* input_str)
{
    int k = 0, i = 0;
    i = skip_space(input_str, i);
    i = check_category(input_str, i, &k);
    if (i == EXPECTED_CATEGORY_NAME) {
        return EXPECTED_CATEGORY_NAME;
    } else if (i == NO_OPENING_PARENTHESIS) {
        return NO_OPENING_PARENTHESIS;
    }
    i = skip_space(input_str, i);
    i = check_unit(input_str, i, &k);
    if (i == EXPECTED_UNIT) {
        return EXPECTED_UNIT;
    }
    k++;
    i = skip_space(input_str, i);
    i = check_unit(input_str, i, &k);
    if (i == EXPECTED_UNIT) {
        return EXPECTED_UNIT;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != ',') {
        return NO_SEPARATING_COMMA;
    } else {
        k++;
        i++;
    }
    k++;
    i = skip_space(input_str, i);
    i = check_value(input_str, i, &k);
    if (i == VALUE_NOT_FOUND) {
        return VALUE_NOT_FOUND;
    } else if (i == EXPECTED_UNSIGNED_DOUBLE) {
        return EXPECTED_UNSIGNED_DOUBLE;
    } else if (i == INCORRECT_NUMBER_ENTRY) {
        return INCORRECT_NUMBER_ENTRY;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != ')') {
        return NO_CLOSING_PARENTHESIS;
    } else {
        k++;
        i++;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != '\n') {
        return UNEXPECTED_TOKEN;
    }
    return k;
}

static int word_copy(char* input_str, char* correct_str, int i, int* j)
{
    while (isalpha(input_str[i]) != 0) {
        correct_str[*j] = input_str[i];
        (*j)++;
        i++;
    }
    return i;
}

int correct_input_str(char* input_str, char** correct_str)
{
    int size_str = checking_str_errors(input_str);
    if (size_str < 0) {
        return size_str;
    }
    (*correct_str) = calloc(size_str, sizeof(char));
    if (correct_str == NULL) {
        return ERROR_MEMORY_ALLOCATIONS;
    }
    int i = 0, j = 0;
    i = skip_space(input_str, i);
    i = word_copy(input_str, (*correct_str), i, &j);
    i = skip_space(input_str, i);
    (*correct_str)[j] = '(';
    j++;
    while (isalpha(input_str[i]) == 0) {
        i++;
    }
    i = word_copy(input_str, (*correct_str), i, &j);
    (*correct_str)[j] = ' ';
    j++;
    i = skip_space(input_str, i);
    i = word_copy(input_str, (*correct_str), i, &j);
    (*correct_str)[j] = ',';
    j++;
    (*correct_str)[j] = ' ';
    j++;
    while (isdigit(input_str[i]) == 0) {
        i++;
    }
    while (isdigit(input_str[i]) != 0 || input_str[i] == '.') {
        (*correct_str)[j] = input_str[i];
        j++;
        i++;
    }
    (*correct_str)[j] = ')';
    return 0;
}

void print_errors(int code_error)
{
    switch (code_error) {
    case CATEGORY_NOT_FOUND:
        printf("ОШИБКА: категория не найдена.\n");
        break;
    case UNIT_NOT_FOUND:
        printf("ОШИБКА: единица измерения не найдена.\n");
        break;
    case VALUE_NOT_FOUND:
        printf("ОШИБКА: число для перевода не найдено.\n");
        break;
    case NO_OPENING_PARENTHESIS:
        printf("ОШИБКА: ожидалось '(' после названия категории или ошибка в "
               "названии категории.\n");
        break;
    case NO_CLOSING_PARENTHESIS:
        printf("ОШИБКА: ожидалось ')' в конце ввода или в числе есть лишние "
               "символы.\n");
        break;
    case NO_SEPARATING_COMMA:
        printf("ОШИБКА: ожидалась разделительная запятая ',' между числом и "
               "последней единицей измерения.\n");
        break;
    case EXPECTED_UNIT:
        printf("ОШИБКА: ожидалась единица измерения или разделительный пробел "
               "между двумя единицами измерения.\n");
        break;
    case EXPECTED_UNSIGNED_DOUBLE:
        printf("ОШИБКА: ожидалось '<unsigned double>' беззнаковое вещественное "
               "число.\n");
        break;
    case UNEXPECTED_TOKEN:
        printf("Ошибка: неожиданный символ после ')'.\n");
        break;
    case ERROR_EXTRACT_NAME:
        printf("ОШИБКА: не удалось извлечь название категории или название "
               "единицы измерения из ввода.\n");
        break;
    case ERROR_MEMORY_ALLOCATIONS:
        printf("ОШИБКА: не удалось выделить память.\n");
        break;
    case EXPECTED_CATEGORY_NAME:
        printf("ОШИБКА: ожидалось название категории.\n");
        break;
    case INCORRECT_NUMBER_ENTRY:
        printf("ОШИБКА: неправильный ввод числа.\n");
        break;
    case INCORRECT_NUM_OF_ARGC:
        printf("ОШИБКА: неправильно введены данные для перевода.\n");
        break;
    case INCORRECT_KEY:
        printf("ОШИБКА: такого ключа не найдено.\n");
        break;
    }
}
