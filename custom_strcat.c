#include "shell.h"
void custom_strcat(char *dest, const char *src) {
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
}