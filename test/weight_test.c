#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(convert_weight, g_in_kg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(g, kg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.01;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, g_in_mkg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(g, mkg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1e+7;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, g_in_mg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(g, mg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, g_in_q)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(g, q, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.0001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, g_in_t)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(g, t, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, kg_in_mkg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(kg, mkg, 1)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, kg_in_mg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(kg, mg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, kg_in_g)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(kg, g, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, kg_in_q)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(kg, q, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.1;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, kg_in_t)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(kg, t, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.01;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mkg_in_mg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mkg, mg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.01;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mkg_in_g)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mkg, g, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mkg_in_kg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mkg, kg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mkg_in_q)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mkg, q, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.0000000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mkg_in_t)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mkg, t, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00000000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mg_in_mkg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mg, mkg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mg_in_g)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mg, g, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.01;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mg_in_kg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mg, kg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mg_in_q)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mg, q, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.0000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, mg_in_t)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(mg, t, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 0.00000001;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, q_in_mkg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(q, mkg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, q_in_mg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(q, mg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, q_in_g)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(q, g, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, q_in_kg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(q, kg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, q_in_t)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(q, t, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 1;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, t_in_mkg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(t, mkg, 0.0001)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 100000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, t_in_mg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(t, mg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, t_in_g)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(t, g, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, t_in_kg)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(t, kg, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 10000;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}

CTEST(convert_weight, t_in_q)
{
    FILE* file = fopen("test/files_for_tests/data_weight_test.txt", "r");
    category** ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Weight(t, q, 10)";
    double factor_from = get_factor(input_str, 0, 1, ar_cat);
    double factor_in = get_factor(input_str, 0, 2, ar_cat);
    double value = get_value(input_str);
    double expect = 100;
    double result = convert_unit(factor_from, factor_in, value);
    ASSERT_DBL_NEAR_TOL(expect, result, TOLL);
}
