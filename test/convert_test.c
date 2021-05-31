#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"
#include "read_test_data.h"

CTEST(convert_test, lenght)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/lenght_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), TOLL);
    }
    fclose(file_test);
}

CTEST(convert_test, speed)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/speed_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), TOLL);
    }
    fclose(file_test);
}

CTEST(convert_test, time)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/time_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), TOLL);
    }
}

CTEST(convert_test, volume)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/volume_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), TOLL);
    }
    fclose(file_test);
}

CTEST(convert_test, weight)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/weight_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), 1e-6);
    }
    fclose(file_test);
}

CTEST(convert_test, datarate)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/Datarate_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), 0);
    }
    fclose(file_test);
}

CTEST(convert_test, datasize)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/Datasize_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), 1e-6);
    }
    fclose(file_test);
}

CTEST(convert_test, frequency)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 9);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/frequency_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(
                data.expect, convert(data.input, arr_cat, 9), 1e-06);
    }
    fclose(file_test);
}

CTEST(convert_test, area)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 8);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/area_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 8), 1e-6);
    }
    fclose(file_test);
}

CTEST(convert_test, pressure)
{
    FILE* file_categories = fopen("src/unit_converter/database.txt", "r");
    category* arr_cat = database_create(file_categories, 10);
    fclose(file_categories);

    FILE* file_test = fopen("test/files_for_tests/pressure_test.txt", "r");
    test_data data;

    while (!feof(file_test)) {
        get_test_data(file_test, &data);
        ASSERT_DBL_NEAR_TOL(data.expect, convert(data.input, arr_cat, 10), 1e-05);
    }
    fclose(file_test);
}
