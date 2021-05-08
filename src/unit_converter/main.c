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
    input_str = calloc(SIZE_INPUT_STR, sizeof(char));
    fgets(input_str, SIZE_INPUT_STR, stdin);

    int first_factor = 1, second_factor = 2;
    int index = get_index_cat(input_str, arr_categors, counter_line);
    double factor_from = get_factor(input_str, index, first_factor, arr_categors);
    printf("factor_from = %.10lf\n", factor_from);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    double factor_in = get_factor(input_str, index, second_factor, arr_categors);
    printf("factor_in = %.10lf\n", factor_in);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    double value = get_value(input_str);
    printf("value = %lf\n", value);
    // сделано для проверки и для того чтобы main компилировался, позже удалим.
    return 0;
}