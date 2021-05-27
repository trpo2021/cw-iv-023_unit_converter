#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(length_test, km_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(km m, 1)";
    double expect = 1000;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_km)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m km, 1)";
    double expect = 0.001;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_dm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m dm, 1)";
    double expect = 10;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, dm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(dm m, 1)";
    double expect = 0.1;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, cm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(cm m, 1)";
    double expect = 0.01;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_cm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m cm, 1)";
    double expect = 100;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, mm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(mm m, 1)";
    double expect = 0.001;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_mm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m mm, 1)";
    double expect = 1000;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, mkm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(mkm m, 1)";
    double expect = 0.000001;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_mkm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m mkm, 1)";
    double expect = 1000000;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, nm_in_m)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(nm m, 1)";
    double expect = 0.000000001;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}

CTEST(length_test, m_in_nm)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(m nm, 1)";
    double expect = 1000000000;
    ASSERT_DBL_NEAR_TOL(expect, converting(input_str, ar_cat, 1), TOLL);
}
