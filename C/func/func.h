#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h> /* memset */

void mem_move(void *dest, void *src, int size);
int atoi(const char *str);

char *str_cpy(char *dest, const char *src);
char upper_case(char ch);
int is_upper_case(char ch);