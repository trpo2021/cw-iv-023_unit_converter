#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(speed_test, kms_in_ms_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, ms, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);

    double expect = 1000;
    double result = convert_unit_speed(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(speed_test, kms_in_ms_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, ms, 32.13)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);

    double expect = 32130.000000;
    double result = convert_unit_speed(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 3e-8);
}

CTEST(speed_test, kms_in_kmh_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, kmh, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);

    double expect = 3600;
    double result = convert_unit_speed(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 3e-8);
}

CTEST(speed_test, kms_in_kmh_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, kmh, 264.091)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);

    double expect = 950727.6;
    double result = convert_unit_speed(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 3e-8);
}

CTEST(speed_test, kms_in_dms_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, dms, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;

    double result = convert_unit_speed(factor_from, factor_in, value);
    free(ar_cat);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(speed_test, kms_in_dmh_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms, dms, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;

    double result = convert_unit_speed(factor_from, factor_in, value);
    free(ar_cat);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}
