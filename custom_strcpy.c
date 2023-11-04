#include "shell.h"
void custom_strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0');
}
