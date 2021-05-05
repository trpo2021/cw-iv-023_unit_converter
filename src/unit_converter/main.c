#include "lib_unit_converter/unit_converter.h"

int main()
{
    FILE* file;
    file = fopen("src/unit_converter/data.txt", "r");
    if (file == NULL) {
        printf("EROR cant open file\n");
        return 1;
    }
    int counter_line = line_counter(file);
    if (counter_line == 0) {
        printf("EROR file empty\n");
        return 1;
    }
    category** arr_categors = malloc(sizeof(category) * counter_line);
    for (int i = 0; i < counter_line; i++) {
        arr_categors[i] = get_category(file);
        if (arr_categors[i] == NULL) {
            printf("EROR: Category format №%d is not correct\n", (i + 1));
        }
    }
    fclose(file);
    return 0;
}