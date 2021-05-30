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

CTEST(input_validation, check_uppercase_category)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "LENgTH(m cm, 10)\n";
    int expect = 1000;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}

CTEST(input_validation, not_found_category)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "Lngt(m cm, 10)\n";
    int expect = CATEGORY_NOT_FOUND;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}

CTEST(input_validation, not_found_unit)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "Length(g cm, 10)\n";
    int expect = UNIT_NOT_FOUND;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
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

CTEST(input_validation, letters_in_numbers)
{
    char input_str[] = "Length(g cm, 1cm0)\n";
    char* p = NULL;
    int expect = NO_CLOSING_PARENTHESIS;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, no_opening_parenthesis)
{
    char input_str[] = "Length g cm, 10)\n";
    char* p = NULL;
    int expect = NO_OPENING_PARENTHESIS;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, no_closing_parenthesis)
{
    char input_str[] = "Length(g cm, 10\n";
    char* p = NULL;
    int expect = NO_CLOSING_PARENTHESIS;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, unexpected_token)
{
    char input_str[] = "Length(g cm, 10) 12\n";
    char* p = NULL;
    int expect = UNEXPECTED_TOKEN;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, extra_point)
{
    char input_str[] = "Length(g cm, 10.12.24)\n";
    char* p = NULL;
    int expect = EXPECTED_UNSIGNED_DOUBLE;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, negative_value)
{
    char input_str[] = "Length(g cm, -10)\n";
    char* p = NULL;
    int expect = EXPECTED_UNSIGNED_DOUBLE;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, check_uppercase_units)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "length(M Cm, 10)\n";
    int expect = 1000;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}

CTEST(input_validation, incorrect_number_entry)
{
    char input_str[] = "Length(m cm, 04)\n";
    int expect = INCORRECT_NUMBER_ENTRY;
    char* p = NULL;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, check_slash)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "speed(km/s m/s, 10)\n";
    int expect = 10000;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}

CTEST(input_validation, check_second_slash)
{
    char input_str[] = "speed(km//s m/s, 10)\n";
    int expect = NO_SECOND_SLASH_EXPECTED;
    char* p = NULL;
    ASSERT_EQUAL(expect, correct_input_str(input_str, &p));
}

CTEST(input_validation, identical_units)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "speed(km/s km/s, 10)\n";
    int expect = IDENTICAL_UNITS;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}

CTEST(input_validation, check_double_value)
{
    FILE* file = fopen("src/unit_converter/database.txt", "r");
    category* ar_cat = database_create(file, 7);
    fclose(file);
    char input_str[] = "speed(km/h cm/h, 0.48)\n";
    int expect = 48000;
    ASSERT_EQUAL(expect, converting(input_str, ar_cat, 7));
}