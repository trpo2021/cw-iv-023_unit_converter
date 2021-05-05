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
    category** arr_categors = database_create(file, counter_line);
    fclose(file);

    char* input_str = NULL;
    input_str = malloc(sizeof(char) * SIZE_INPUT_STR);
    fgets(input_str, SIZE_INPUT_STR, stdin);

    int index = get_index_cat(input_str, arr_categors, counter_line);
    double factor_from = get_factor(input_str, index, 1, arr_categors);
    printf("factor_from = %lf\n", factor_from);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    double factor_in = get_factor(input_str, index, 2, arr_categors);
    printf("factor_in = %lf\n", factor_in);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    double value = get_value(input_str);
    printf("value = %lf\n", value);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    return 0;
}