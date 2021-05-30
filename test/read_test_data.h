#include <stdio.h>

typedef struct test_data {
    char* input;
    double expect;
} test_data;

void get_test_data(FILE* file, test_data* d);