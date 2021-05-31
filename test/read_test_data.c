#include "read_test_data.h"
#include "lib_unit_converter/unit_converter.h"

#define STR_LEN 256

int get_test_data(FILE* file, test_data* d)
{
    int i, counter = 0;

    char buf_str[STR_LEN];
    if (fgets(buf_str, STR_LEN, file) == NULL) {
        d->expect = -1;
        d->input = "Sped(km/s m/s, 1)";
        return 0;
    }

    while (buf_str[counter] != ')') {
        counter++;
    }

    d->input = calloc(counter + 1, sizeof(char));
    for (i = 0; i <= counter; i++) {
        d->input[i] = buf_str[i];
    }

    d->expect = atof(&buf_str[counter + 3]);
    return 0;
}
