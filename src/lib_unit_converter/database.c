#include "unit_converter.h"

void* get_word(int i, category* arr_categors, char* buf)
{
    if (i == 0) {
        return NULL;
    }
    arr_categors->key = calloc(i, sizeof(char));
    if (arr_categors->key == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        arr_categors->key[j] = buf[j];
    }
    return arr_categors->key;
}

unit* get_unit(char* buf, int i, int k)
{
    if (k == 0) {
        return NULL;
    }
    unit* uniti = calloc(k, sizeof(unit));
    if (uniti == NULL) {
        return NULL;
    }
    int j, p = 0, t;
    while (p < k) {
        j = i;
        while (isalpha(buf[i]) != 0) {
            i++;
        }
        uniti[p].key = calloc(i - j, sizeof(char));
        for (t = 0; j < i; j++, t++) {
            uniti[p].key[t] = buf[j];
        }
        while (isdigit(buf[i]) == 0) {
            i++;
        }
        uniti[p].value = atof(&buf[i]);
        while (isalpha(buf[i]) == 0) {
            i++;
        }
        p++;
    }
    return uniti;
}

category* get_category(FILE* file)
{
    category* arr_categors = calloc(1, sizeof(category));
    if (arr_categors == NULL) {
        return NULL;
    }
    char* buf = calloc(SIZE_BUF, sizeof(char));
    fgets(buf, SIZE_BUF, file);
    int i = 0, tmp_i, k = 1;
    while (isalpha(buf[i]) != 0) {
        i++;
    }
    arr_categors->key = get_word(i, arr_categors, buf);
    if (arr_categors->key == NULL) {
        return NULL;
    }

    while (buf[i] != '(') {
        i++;
    }
    i++;
    tmp_i = i;
    for (; buf[i] != ')'; i++) {
        if (buf[i] == ',') {
            k++;
        }
    }
    arr_categors->units_counter = k;
    arr_categors->units = get_unit(buf, tmp_i, k);
    if (arr_categors->units == NULL) {
        return NULL;
    }
    free(buf);
    return arr_categors;
}

category** database_create(FILE* file, int counter_line)
{
    category** arr_categors = calloc(counter_line, sizeof(category));
    for (int i = 0; i < counter_line; i++) {
        arr_categors[i] = get_category(file);
        if (arr_categors[i] == NULL) {
            printf("EROR: Category format №%d is not correct\n", (i + 1));
        }
    }
    return arr_categors;
}

int line_counter(FILE* file)
{
    int counter = 0;
    char ch, pre = EOF;
    while ((ch = fgetc(file)) != EOF) {
        pre = ch;
        if (ch == '\n') {
            counter++;
        }
    }
    if (pre == EOF) {
        return 0;
    } else if (pre != '\n') {
        counter++;
    }
    rewind(file);
    return counter;
}