#include "lib_unit_converter/unit_converter.h"

double convert_time(double factor_from, double factor_in, double value)
{
    return value * (factor_from / factor_in);
}
