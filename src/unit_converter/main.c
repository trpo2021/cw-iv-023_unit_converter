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
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            help();
            while ((getchar()) != '\n')
                ;
        }
        if (strcmp(argv[1], "-g") == 0) {
            start_graphic(arr_categors, counter_line);
            free_database(arr_categors, counter_line);
            return 0;
        }
        }
        if (argc == 6) {
        if ((strcmp(argv[1], "--fast") == 0) || (strcmp(argv[1], "-f") == 0)) {
            build_str_fast(input_str, argc, argv);
        }
    } else {
        printf("You want: ");
        fgets(input_str, SIZE_INPUT_STR, stdin);
    }
    char* correct_str = NULL;
    int code_error = correct_input_str(input_str, &correct_str);
    if (code_error < 0) {
        print_errors(code_error);
        free_database(arr_categors, counter_line);
        return 1;
    }
    double converted_value
            = converting(correct_str, arr_categors, counter_line);
    if (converted_value < 0) {
        print_errors(converted_value);
        free_database(arr_categors, counter_line);
        return 1;
    }
    printf("Converted value = %lf\n", converted_value);
    free_database(arr_categors, counter_line);
    return 0;
}
