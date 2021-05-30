#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(line_counter, no_empty_file)
{
    int expect = 3;
    FILE* file = fopen("test/files_for_tests/line_count_test.txt", "r");
    int real = line_counter(file);
    fclose(file);
    ASSERT_EQUAL(expect, real);
}

CTEST(line_counter, empty_file)
{
    int expect = 0;
    FILE* file = fopen("test/files_for_tests/empty_file.txt", "r");
    int real = line_counter(file);
    fclose(file);
    ASSERT_EQUAL(expect, real);
}

CTEST(database_create, check_category_name)
{
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category* real = database_create(file, 3);
    fclose(file);
    char expect_word_1[] = "Weight";
    char expect_word_2[] = "Length";
    char expect_word_3[] = "Speed";
    ASSERT_NOT_NULL(real);
    ASSERT_STR(expect_word_1, real[0].name);
    ASSERT_STR(expect_word_2, real[1].name);
    ASSERT_STR(expect_word_3, real[2].name);
}

CTEST(database_create, check_units)
{
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category* real = database_create(file, 3);
    fclose(file);
    char expect_name_1[] = "mkg";
    char expect_name_2[] = "mg";
    double expect_value_1 = 0.000000001;
    double expect_value_2 = 0.000001;

    ASSERT_NOT_NULL(real);
    ASSERT_STR(expect_name_1, real[0].units[0].name);
    ASSERT_STR(expect_name_2, real[0].units[1].name);
    ASSERT_DBL_NEAR_TOL(expect_value_1, real[0].units[0].factor, 0);
    ASSERT_DBL_NEAR_TOL(expect_value_2, real[0].units[1].factor, 0);
}

CTEST(database_create, database_fail)
{
    FILE* file = fopen("test/files_for_tests/database_fail.txt", "r");
    category* real = database_create(file, 1);
    fclose(file);
    ASSERT_NULL(real);
}