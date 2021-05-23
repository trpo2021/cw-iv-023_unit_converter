#include "lib_unit_converter/unit_converter.h"

int main(int argc, char** argv)
{
    FILE* file;
    file = fopen("src/unit_converter/data.txt", "r");
    if (file == NULL) {
        printf("ERROR cant open file\n");
        return 1;
    }
    int counter_line = line_counter(file);
    if (counter_line == 0) {
        printf("EROR file empty\n");
        return 1;
    }
    category* arr_categors = database_create(file, counter_line);
    fclose(file);

    char input_str[SIZE_INPUT_STR] = {0};
    if ((strcmp(argv[1], "--fast") == 0) || (strcmp(argv[1], "-f") == 0)) {
        build_str_fast(input_str, argc, argv);
    } else {
        printf("You want:");
        fgets(input_str, SIZE_INPUT_STR, stdin);
    }
    printf("Converted value = %lf\n",
           convert(input_str, arr_categors, counter_line));
    free_database(arr_categors, counter_line);
    return 0;
}
