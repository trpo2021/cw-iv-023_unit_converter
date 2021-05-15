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

CTEST(database_create, check_words)
{
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category* real = database_create(file, 3);
    fclose(file);
    char expect_word_1[] = "Weight";
    char expect_word_2[] = "Length";
    char expect_word_3[] = "Speed";
    ASSERT_NOT_NULL(real);
    ASSERT_STR(expect_word_1, real[0].key);
    ASSERT_STR(expect_word_2, real[1].key);
    ASSERT_STR(expect_word_3, real[2].key);
}

CTEST(database_create, check_unit_first)
{
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category* real = database_create(file, 3);
    fclose(file);
    char expect_key_1[] = "mkg";
    char expect_key_2[] = "mg";
    double expect_value_1 = 0.000000001;
    double expect_value_2 = 0.000001;

    ASSERT_NOT_NULL(real);
    ASSERT_STR(expect_key_1, real[0].units[0].key);
    ASSERT_STR(expect_key_2, real[0].units[1].key);
    ASSERT_DBL_NEAR_TOL(expect_value_1, real[0].units[0].value, 0);
    ASSERT_DBL_NEAR_TOL(expect_value_2, real[0].units[1].value, 0);
}

CTEST(database_create, check_unit_last)
{
    FILE* file = fopen("test/files_for_tests/data_test.txt", "r");
    category* real = database_create(file, 3);
    fclose(file);
    char expect_key_1[] = "kms";
    char expect_key_2[] = "ms";
    double expect_value_1 = 0.001;
    double expect_value_2 = 1;

    ASSERT_NOT_NULL(real);
    ASSERT_STR(expect_key_1, real[2].units[0].key);
    ASSERT_STR(expect_key_2, real[2].units[1].key);
    ASSERT_DBL_NEAR_TOL(expect_value_1, real[2].units[0].value, 0);
    ASSERT_DBL_NEAR_TOL(expect_value_2, real[2].units[1].value, 0);
}