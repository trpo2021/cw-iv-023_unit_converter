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

CTEST(get_word, word_hello)
{
    char buf[] = "hello";
    int i = 5;
    char expect[] = "hello";
    category* real = malloc(sizeof(category));
    real->key = get_word(i, real, buf);
    ASSERT_STR(expect, real->key);
}

CTEST(get_word, no_word)
{
    char buf[] = "";
    int i = 0;
    category* real = malloc(sizeof(category));
    real->key = get_word(i, real, buf);
    ASSERT_NULL(real->key);
}

CTEST(get_unit, no_units)
{
    char buf[] = " ";
    int i = 0, k = 0;
    unit* real = get_unit(buf, i, k);
    ASSERT_NULL(real);
}

CTEST(get_unit, two_units)
{
    char buf[] = "(mkg - 0.000000001, mg - 0.000001)";
    int i = 1, k = 2;
    unit* real = NULL;
    real = get_unit(buf, i, k);
    unit expect[] = {{"mkg", 0.000000001}, {"mg", 0.000001}};
    ASSERT_STR(expect[0].key, real[0].key);
    ASSERT_STR(expect[1].key, real[1].key);
    ASSERT_DBL_NEAR_TOL(expect[0].value, real[0].value, 0);
    ASSERT_DBL_NEAR_TOL(expect[1].value, real[1].value, 0);
}