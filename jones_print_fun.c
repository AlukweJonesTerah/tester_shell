#include "shell.h"

/**
 * custom_printf - Custom implementation of printf using write
 * @format: The format string
 */
void custom_printf(const char *format, ...) {
    va_list args;
    char buffer[BUFFER_SIZE];  /*Define MAX_OUTPUT as needed */
    int length = vsnprintf(buffer, sizeof(buffer), format, args);
    va_start(args, format);
    va_end(args);
    write(STDOUT_FILENO, buffer, length);
}
void custom_printf2(const char *format)
{
    write(STDOUT_FILENO, format, strlen(format));
}

/* void custom_printf2(const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vfprintf(stdout, format, args);
        va_end(args);
} */
