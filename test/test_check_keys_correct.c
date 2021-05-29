#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(check_keys_correct, correct_key)
{
    int exp = 3;
    char key[] = "--fast";
    int res = check_keys_correct(key);
    ASSERT_EQUAL(exp, res);
}

CTEST(check_keys_correct, incorrect_key)
{
    int exp = INCORRECT_KEY;
    char key[] = "--ft";
    int res = check_keys_correct(key);
    ASSERT_EQUAL(exp, res);
}
