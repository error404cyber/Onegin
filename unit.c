#include "unit.h"
#include "Onegin.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int run_all_test(){
    assert(test_compare() == OK);
    assert(test_format_buffer() == OK);
    assert(test_count_fsize() == OK);
    assert(test_build_strings_formatted_buf() == OK);
    return 0;
}

Error test_compare(){
    char *a = strdup("abscde");
    char *b = strdup("abcde");
    if (compare(&a,&b) != 16){
        printf("Not right\n");
        return NOT_OK;
    }
    return OK;
}
  
  
Error test_fsize(){
    FILE *input = fopen("Onegin.txt", "rb");
    size_t fsize = count_fsize(input);
    if (fsize!=5){
        printf("Not right\n");
        return NOT_OK;
    }
    FILE *input = fclose(input);
    return OK;
}

Error test_format_buffer(){
    FILE *input = fopen("Onegin.txt", "rb");

    size_t fsize = count_fsize(input);
    char* text = (char*)calloc(fsize, sizeof(char));
    fread(text, sizeof(char), fsize, input);
    if (format_buffer(text)!=3) {
        printf("Not right\n");
        return NOT_OK;
    }
    free(text);
    FILE *input = fclose(input);
    return OK;
}

Error test_build_strings_formatted_buf(){
    FILE *input = fopen("Onegin.txt", "rb");

    size_t fsize = count_fsize(input);
    char* text = (char*)calloc(fsize, sizeof(char));
    fread(text, sizeof(char), fsize, input);
    format_buffer(text);
    if ((text[0] != '1') || (text[2] != '2') || (text[4] != '5')) {
        printf("Not right\n");
        return NOT_OK;
    }
    free(text);
    FILE *input = fclose(input);
    return OK;
}
