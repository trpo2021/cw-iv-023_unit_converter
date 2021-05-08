#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(time_test, s_in_ms)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(s, ms, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, ms_in_s)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ms, s, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.001;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, ns_in_s)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ns, s, 36000)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 3.6e-5;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, h_in_ns)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(h, ns, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 3.6e+12;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, w_in_mks)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(w, mks, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 6.048e+11;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, mks_in_w)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(mks, w, 6048)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1e-8;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, m_in_ns)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(m, ns, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 6e+10;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, ns_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ns, m, 6)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1e-10;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, d_in_w)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(d, w, 7)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, w_in_d)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(w, d, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 7;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, ms_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ms, m, 6)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1e-4;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}

CTEST(time_test, m_in_ms)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(m, ms, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 60000;
    double result = convert_time(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, 0);
}
