#include "string.h"
  
 typedef enum Error { OK, NOT_OK } Error;

void run_all_tests();
Error test_compare();
Error test_format_buffer();
Error test_count_lines();
Error test_build_strings_formatted_buf();
