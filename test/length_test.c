#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"
#include "read_test_data.h"

CTEST(length_test, all)
{
    FILE* file_categories = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* arr_cat = database_create(file_categories, 1);
    fclose(file_categories);

    FILE *file_test = fopen("test/files_for_tests/lenght_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, converting(data.input, arr_cat, 1), 1.6e-02);
    }
}