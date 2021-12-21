#include <stdio.h>

int compare(const void *first, const void* second);
size_t count_fsize(FILE *f);
size_t format_buffer(char *buf);
void build_strings_formatted_buf(char *buf, char **strings, size_t count_lines);
