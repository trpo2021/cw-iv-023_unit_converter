#include <stdio.h>

#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(length_test, km_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(km, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_km)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, km, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_dm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, dm, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, dm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(dm, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.1;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, cm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(cm, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.01;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_cm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, cm, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 100;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, mm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(mm, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_mm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, mm, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, mkm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(mkm, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_mkm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, mkm, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, nm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(nm, m, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.000000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(length_test, m_in_nm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m, nm, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 1.2e-07);
}
