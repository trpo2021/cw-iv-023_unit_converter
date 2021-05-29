#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"
#include "read_test_data.h"

CTEST(length_test, all)
{
    FILE* file_categories = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* arr_cat = database_create(file_categories, 1);
    fclose(file_categories);

    FILE *file_test = fopen("test/files_for_tests/lenght_test.txt", "r");
    test_data d;

    while (!feof(file_test)) {
        get_test_data(file_test, &d);
        ASSERT_DBL_NEAR_TOL(d.expect, converting(d.input, arr_cat, 1), 0.001);
    }
}