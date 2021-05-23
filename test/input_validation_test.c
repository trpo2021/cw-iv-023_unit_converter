#include "ctest.h"
#include "lib_unit_converter/unit_converter.h"

CTEST(input_validation, skip_space)
{
    char input_str[] = "  Length  ( m  cm,  10  )  \n";
    int expect = 0;
    char* p = NULL;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, no_space)
{
    char input_str[] = "Length(m cm,10)\n";
    int expect = 0;
    char* p = NULL;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, check_uppercase)
{
    char input_str[] = "LENgTH(m cm, 10)\n";
    int expect = 0;
    char* p = NULL;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, not_found_category)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Lngt(m cm, 10)\n";
    int expect = CATEGORY_NOT_FOUND;
    ASSERT_EQUAL(expect, convert(input_str, ar_cat, 1));
}

CTEST(input_validation, not_found_unit)
{
    FILE* file = fopen("test/files_for_tests/data_length_test.txt", "r");
    category* ar_cat = database_create(file, 1);
    fclose(file);
    char input_str[] = "Length(g cm, 10)\n";
    int expect = UNIT_NOT_FOUND;
    ASSERT_EQUAL(expect, convert(input_str, ar_cat, 1));
}

CTEST(input_validation, expected_first_unit)
{
    char input_str[] = "Length(1 cm, 10)\n";
    char* p = NULL;
    int expect = EXPECTED_UNIT;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, expected_second_unit)
{
    char input_str[] = "Length(m 2, 10)\n";
    char* p = NULL;
    int expect = EXPECTED_UNIT;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, expected_category)
{
    char input_str[] = "10Length(g cm, 10)\n";
    char* p = NULL;
    int expect = EXPECTED_CATEGORY_NAME;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, value_not_found)
{
    char input_str[] = "Length(g cm, cm)\n";
    char* p = NULL;
    int expect = VALUE_NOT_FOUND;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, no_separating_comma)
{
    char input_str[] = "Length(g cm 10)\n";
    char* p = NULL;
    int expect = NO_SEPARATING_COMMA;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, no_separating_space)
{
    char input_str[] = "Length(gcm 10)\n";
    char* p = NULL;
    int expect = EXPECTED_UNIT;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, incorrect_number_entry)
{
    char input_str[] = "Length(g cm, 1cm0)\n";
    char* p = NULL;
    int expect = NO_CLOSING_PARENTHESIS;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}