#include <stdio.h>

typedef struct test_data {
    char* input;
    double expect;
} test_data;

int get_test_data(FILE* file, test_data* d);
