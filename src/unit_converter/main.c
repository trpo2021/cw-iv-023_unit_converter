#include "lib_unit_converter/unit_converter.h"

int main(int argc, char** argv)
{
    FILE* database;
    database = fopen("src/unit_converter/data.txt", "r");
    if (database == NULL) {
        printf("ERROR cant open database\n");
        return 1;
    }
    int counter_line = line_counter(database);
    if (counter_line == 0) {
        printf("ERROR database empty\n");
        return 1;
    }
    category* arr_categors = database_create(database, counter_line);
    fclose(database);
    char input_str[SIZE_INPUT_STR] = {0};
    int value_of_check;
    if (argc > 1) {
        value_of_check = check_keys_correct(argv[1]);
    } else {
        value_of_check = 0;
    }
    if (value_of_check < 0) {
        print_errors(value_of_check);
        return 0;
    }
    if (argc == 2) {
        if (value_of_check == HELP) {
            help();
            while ((getchar()) != '\n')
                ;
        }
        if (value_of_check == GRAPHICS) {
            start_graphic(arr_categors, counter_line);
            free_database(arr_categors, counter_line);
            return 0;
        }
    }
    if (value_of_check == FAST_1 || value_of_check == FAST_2) {
        if (argc == 6) {
            build_str_fast(input_str, argc, argv);
        } else {
            print_errors(INCORRECT_NUM_OF_ARGC);
            return 0;
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
