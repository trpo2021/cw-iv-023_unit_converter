#include "unit_converter.h"

void get_word(int p1, int p2, category* arr_cat, char* buf)
{
    arr_cat->key = malloc(sizeof(char) * (p2 - p1));
    for (; p1 < p2; p1++) {
        arr_cat->key[p1] = buf[p1];
    }
}

unit* get_unit(char* buf, int i, int k)
{
    unit* uniti = malloc(sizeof(unit) * k);
    if (uniti == NULL) {
        return NULL;
    }
    int j, p = 0, t;
    while (p < k) {
        j = i;
        while (isalpha(buf[i]) != 0) {
            i++;
        }
        uniti[p].key = malloc(sizeof(char) * (i - j));
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
    category* arr_cat = malloc(sizeof(category));
    if (arr_cat == NULL) {
        return NULL;
    }
    char buf[1024];
    fgets(buf, 1024, file);
    int i = 0, p1 = 0, p2 = 0, k = 1;
    while (buf[i] != ' ') {
        i++;
        p2++;
    }
    get_word(p1, p2, arr_cat, buf);

    while (buf[i] != '(') {
        i++;
    }
    i++;
    p1 = i;
    for (; buf[i] != ')'; i++) {
        if (buf[i] == ',') {
            k++;
        }
    }
    arr_cat->units = get_unit(buf, p1, k);
    return arr_cat;
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
        printf("Файл пустой!\n");
    } else if (pre != '\n') {
        counter++;
    }
    rewind(file);
    return counter;
}