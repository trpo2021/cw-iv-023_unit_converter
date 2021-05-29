#include "unit_converter.h"

char* build_str_fast(char* input_str, int argc, char** argv)
{
    int i = 2;
    int sum_of_symbols = 0;
    while (i < argc) {
        strcat(input_str, argv[i]);
        sum_of_symbols += strlen(argv[i]);
        if ((i == 3) || (i == 4)) {
            input_str[sum_of_symbols] = ' ';
            sum_of_symbols++;
        }
        if (i == 2) {
            input_str[sum_of_symbols] = '(';
            sum_of_symbols++;
        }
        if (i == 5) {
            input_str[sum_of_symbols] = ')';
            sum_of_symbols++;
        }
        i++;
    }
    input_str[sum_of_symbols] = '\n';
    return input_str;
}

#define MAX_SIZE_OF_FILE 1000
int help()
{
    char button;
    FILE* page = fopen("help/greeting.txt", "r");
    if (page == NULL) {
        printf("Can`t open file\n");
    }
    fseek(page, sizeof(char), SEEK_END);
    int size_of_file = MAX_SIZE_OF_FILE;
    char* page_str = calloc(size_of_file, sizeof(char));
    rewind(page);
    fread(page_str, sizeof(char), size_of_file, page);
    fprintf(stdout, "%s", page_str);
    while (1) {
        scanf("%c", &button);
        switch (button) {
        case 0x31:
            page = fopen("help/page_1.txt", "r");
            if (page == NULL) {
                printf("Can`t open file\n");
            }
            while ((getchar()) != '\n')
                ;
            memset(page_str, 0, size_of_file);
            fread(page_str, sizeof(char), size_of_file, page);
            fprintf(stdout, "%s", page_str);
            break;

        case 0x32:
            page = fopen("help/page_2.txt", "r");
            if (page == NULL) {
                printf("Can`t open file\n");
            }
            while ((getchar()) != '\n')
                ;
            memset(page_str, 0, 256);
            fread(page_str, sizeof(char), size_of_file, page);
            fprintf(stdout, "%s", page_str);
            break;

        case 0x71:
            fclose(page);
            free(page_str);
            return 0;
            break;

        case 0x51:
            free(page_str);
            fclose(page);
            return 0;
            break;

        default:
            printf("Неизвестная страница!\n");
        }
    }
    free(page_str);
    fclose(page);
    return 0;
}
