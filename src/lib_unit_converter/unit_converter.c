#include "lib_unit_converter/unit_converter.h"

double convert_length(double factor_from, double factor_in, double value)
{
    return value * (factor_from / factor_in);
}

double convert_speed(double factor_from, double factor_in, double value)
{
    double converted_value;
    converted_value = value * (1 / factor_from) * factor_in;

    return converted_value;
}

double convert_weight(double factor_from, double factor_in, double value)
{
    return value * (factor_from / factor_in);
}