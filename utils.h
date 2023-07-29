#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* get_list_from_argv(char* list, int* list_len);
int get_split_len(char* list, const char* delim);
char* copy_char_array(char* list);

#endif