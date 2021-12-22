
/**
 * дается файл со строками
 * нужно упорядочить строки в лексикографическом порядке
 * то есть по алфавиту 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Onegin.h"
#include "unit.h"


int main(){
//считывание файла
FILE *input = fopen("Onegin.txt", "rb");

size_t fsize = count_fsize(input);
//создание буфера
char* text = (char*)calloc(fsize, sizeof(char));
  fread(text, sizeof(char), fsize, input);

  size_t count_lines = format_buffer(text);


  char ** strings = (char**)calloc(count_lines, sizeof(char*));
  build_strings_formatted_buf(text, strings, count_lines);

//сортировка массива строк
  qsort(strings, count_lines, sizeof(char**), compare);

//вывод отсортированного буфера
//for(size_t i = 0; i<count_lines; ++i){
//  printf("%s\n", strings[i]);
//}
  run_all_test();

  return 0;
}
