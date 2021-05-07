#include <stdio.h>

double convert_length(double factor_from, double factor_in, double value)
{
    return value * (factor_from / factor_in);
}