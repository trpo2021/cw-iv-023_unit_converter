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