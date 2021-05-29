#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(build_str_fast, right_input)
{
    char input_str[50] = {0};
    char* argv[]
            = {"bin/unit_converter", "--fast", "Speed", "km/s", "m/s,", "10"};
    int argc = 6;
    char expect[] = {"Speed(km/s m/s, 10)\n"};
    char* result = calloc(40, sizeof(char));
    result = build_str_fast(input_str, argc, argv);
    ASSERT_STR(expect, result);
}

CTEST(build_str_fast, incorrect_input)
{
    char input_str[50] = {0};
    char* argv[] = {"bin/unit_converter", "-fast", "Sped", "kms", "m/s", "10"};
    int argc = 6;
    char expect[] = {"Sped(kms m/s 10)\n"};
    char* result = calloc(40, sizeof(char));
    result = build_str_fast(input_str, argc, argv);
    ASSERT_STR(expect, result);
}

CTEST(build_and_check, correct_input)
{
    char input_str[50] = {0};
    char* argv[]
            = {"bin/unit_converter", "--fast", "Speed", "km/s", "m/s,", "10"};
    int argc = 6;
    char* result_str = calloc(40, sizeof(char));
    result_str = build_str_fast(input_str, argc, argv);
    int expect = 0;
    char* correct_str = NULL;
    int result = correct_input_str(result_str, &correct_str);
    ASSERT_EQUAL(result, expect);
}

CTEST(build_and_check, incorrect_input)
{
    char input_str[50] = {0};
    char* argv[]
            = {"bin/unit_converter", "--fast", "Speed", "km/s", "m/s", "10"};
    int argc = 6;
    char* result_str = calloc(40, sizeof(char));
    result_str = build_str_fast(input_str, argc, argv);
    int expect = -6;
    char* correct_str = NULL;
    int result = correct_input_str(result_str, &correct_str);
    ASSERT_EQUAL(expect, result);
}
