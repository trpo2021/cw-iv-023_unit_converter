#include "lib_unit_converter/unit_converter.h"

double time_convert(double factor_from, double factor_in, double value)
{
    return value * (factor_from / factor_in);
}
