#include "Onegin.h"


size_t count_fsize(FILE *f){
  size_t start = ftell(f);
  fseek(f, 0, SEEK_END);
  size_t size  = ftell(f);
  fseek(f, start, SEEK_SET);
  return size;
}

size_t format_buffer(char *buf)
{
  size_t count_lines = 0;
  char *from = buf, *to=buf;
  while (*buf != '\0'){
    if ((*buf == '\r') || (*buf == '\n')){
      *buf = '\0';
    }
    buf++;
  }
  //ща будет замена всех подряд идущих \0 на один \0
  //чтоб не выводить пустые строки

  while (from != buf){
    int flag = 0;
    while ((*from == '\0') && (from != buf)){
      from++;
      flag = 1;
    }
    if (flag){
      count_lines++;
      from--;
    }
    *to = *from;
    to++;
    from++;
  }
  return count_lines;
}

void build_strings_formatted_buf(char *buf, char **strings, size_t count_lines){
  char *start = buf;
  size_t cur_string = 0;

  while(cur_string < count_lines){
    strings[cur_string] = start;
    while (*start++ != '\0'){}
  }
}
