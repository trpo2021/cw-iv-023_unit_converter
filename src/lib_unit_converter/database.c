#include "unit_converter.h"

static void* get_word(int i, category* arr_categors, char* database_buf)
{
    if (i == 0) {
        return NULL;
    }
    arr_categors->name = calloc(i, sizeof(char));
    if (arr_categors->name == NULL) {
        return NULL;
    }
    for (int j = 0; j < i; j++) {
        arr_categors->name[j] = database_buf[j];
    }
    return arr_categors->name;
}

static unit* get_unit(char* database_buf, int i, int k)
{
    if (k == 0) {
        return NULL;
    }
    unit* units = calloc(k, sizeof(unit));
    if (units == NULL) {
        return NULL;
    }
    int j, p = 0, t;
    while (p < k) {
        while (isalpha(database_buf[i]) == 0) {
            i++;
        }
        j = i;
        while (isalpha(database_buf[i]) != 0 || database_buf[i] == '/') {
            i++;
        }
        units[p].name = calloc(i - j, sizeof(char));
        for (t = 0; j < i; j++, t++) {
            units[p].name[t] = database_buf[j];
        }
        while (isdigit(database_buf[i]) == 0) {
            i++;
        }
        units[p].factor = atof(&database_buf[i]);
        p++;
    }
    return units;
}

static int get_category(FILE* database, category* arr_categors)
{
    char database_buf[SIZE_BUF] = {0};
    fgets(database_buf, SIZE_BUF, database);
    int i = 0, tmp_i, k = 1;
    while (isalpha(database_buf[i]) != 0) {
        i++;
    }
    arr_categors->name = get_word(i, arr_categors, database_buf);
    if (arr_categors->name == NULL) {
        return -1;
    }

    while (database_buf[i] != '(') {
        i++;
    }
    i++;
    tmp_i = i;
    for (; database_buf[i] != ')'; i++) {
        if (database_buf[i] == ',') {
            k++;
        }
    }
    arr_categors->units_counter = k;
    arr_categors->units = get_unit(database_buf, tmp_i, k);
    if (arr_categors->units == NULL) {
        return -1;
    }
    return 0;
}

category* database_create(FILE* database, int counter_line)
{
    category* arr_categors = (category*)calloc(counter_line, sizeof(category));
    for (int i = 0; i < counter_line; i++) {
        if (get_category(database, &(arr_categors[i])) == -1) {
            printf("EROR: Category format №%d is not correct\n", (i + 1));
        }
    }
    return arr_categors;
}

int line_counter(FILE* database)
{
    int counter = 0;
    char ch, pre = EOF;
    while ((ch = fgetc(database)) != EOF) {
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
    rewind(database);
    return counter;
}

void free_database(category* arr_categors, int line_counter)
{
    for (int i = 0; i < line_counter; i++) {
        free(arr_categors[i].units);
    }
    free(arr_categors);
}