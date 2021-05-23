#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(speed_test, kms_in_ms_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms ms, 1)";
    double expect = 1000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(speed_test, kms_in_ms_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms ms, 32.13)";
    double expect = 32130.000000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(speed_test, kms_in_kmh_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms kmh, 1)";
    double expect = 3600;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(speed_test, kms_in_kmh_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms kmh, 264.091)";
    double expect = 950727.6;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(speed_test, kms_in_dms_value_1)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms dms, 1)";
    double expect = 10000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(speed_test, kms_in_dmh_some_value)
{
    FILE* file = fopen("test/files_for_tests/data_speed_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Speed(kms dms, 1)";
    double expect = 10000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}
