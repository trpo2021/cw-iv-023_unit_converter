#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(get_index_cat, correct_input_length)
{
    char input_str[] = "Length(cm, m, 10)";
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category** arr_categors = database_create(file, 3);
    fclose(file);
    int exp = 1;
    int real = get_index_cat(input_str, arr_categors, 3);
    ASSERT_EQUAL(exp, real);
}

CTEST(get_index_cat, correct_input_speed)
{
    char input_str[] = "Speed(kms, ms, 10)";
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category** arr_categors = database_create(file, 3);
    fclose(file);
    int exp = 2;
    int real = get_index_cat(input_str, arr_categors, 3);
    ASSERT_EQUAL(exp, real);
}

CTEST(get_index_cat, correct_input_weight)
{
    char input_str[] = "Weight(mgk, mg, 10)";
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category** arr_categors = database_create(file, 3);
    fclose(file);
    int exp = 0;
    int real = get_index_cat(input_str, arr_categors, 3);
    ASSERT_EQUAL(exp, real);
}

CTEST(get_index_cat, wrong_input)
{
    char input_str[] = "Legth(cm, m, 10)";
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category** arr_categors = database_create(file, 3);
    fclose(file);
    int exp = -1;
    int real = get_index_cat(input_str, arr_categors, 3);
    ASSERT_EQUAL(exp, real);
}

CTEST(get_index_cat, register_check)
{
    char input_str[] = "leNGth(cm, m, 10)";
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category** arr_categors = database_create(file, 3);
    fclose(file);
    int exp = 1;
    int real = get_index_cat(input_str, arr_categors, 3);
    ASSERT_EQUAL(exp, real);
}