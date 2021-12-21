#include "unit.h"
#include "Onegin.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int run_all_test(){
    assert(test_compare() == OK);
    assert(test_format_buffer() == OK);
    assert(test_count_lines() == OK);
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
    if (fsize!=7){
        printf("Not right\n");
        return NOT_OK;
    }
    return OK;
}
