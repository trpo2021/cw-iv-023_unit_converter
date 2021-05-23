#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(time_test, s_in_ms)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(s ms, 1)";
    double expect = 1000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, ms_in_s)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ms s, 1)";
    double expect = 0.001;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, ns_in_s)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ns s, 36000)";
    double expect = 3.6e-5;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, h_in_ns)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(h ns, 1)";
    double expect = 3.6e+12;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, w_in_mks)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(w mks, 1)";
    double expect = 6.048e+11;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, mks_in_w)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(mks w, 6048)";
    double expect = 1e-8;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, m_in_ns)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(m ns, 1)";
    double expect = 6e+10;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, ns_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ns m, 6)";
    double expect = 1e-10;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, d_in_w)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(d w, 7)";
    double expect = 1;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, w_in_d)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(w d, 1)";
    double expect = 7;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, ms_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(ms m, 6)";
    double expect = 1e-4;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}

CTEST(time_test, m_in_ms)
{
    FILE* file = fopen("test/files_for_tests/data_time_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Time(m ms, 1)";
    double expect = 60000;
    ASSERT_DBL_NEAR_TOL(expect, convert(input_str, ar_cat, 1), TOLL);
}
