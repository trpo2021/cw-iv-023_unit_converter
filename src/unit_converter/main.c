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
    category** arr_categors = malloc(sizeof(category) * counter_line);
    for (int i = 0; i < counter_line; i++) {
        arr_categors[i] = get_category(file);
    }
    return 0;
}