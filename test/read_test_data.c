#include "lib_unit_converter/unit_converter.h"
#include "read_test_data.h"

#define STR_LEN 32

void get_test_data(FILE *file, test_data *d)
{
    int i, counter = 0;

    char buf_str[STR_LEN];
    fgets(buf_str, STR_LEN, file);

    while (buf_str[counter] != ')') {
        counter++;
    }

    d->input = calloc(counter + 1, sizeof(char));
    for (i = 0; i <= counter; i++){
        d->input[i] = buf_str[i];
    }

    d->expect = atof(&buf_str[counter + 3]); 
}