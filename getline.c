#include "shell.h"
/**
 * _getline - Custom implementation of getline
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the size of the allocated buffer
 * @stream: File stream to read from (usually stdin)
 * Return: Number of characters read (including the newline)
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[READ_SIZE];
    static size_t buffer_pos = 0;
    static ssize_t bytes_read = 0;
    ssize_t total_chars_read = 0;
    ssize_t chars_read = 0;

    if (lineptr == NULL || n == NULL)
        return -1;

    if (*lineptr == NULL || *n == 0)
    {
        *n = READ_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
            return -1;
    }

    while (1)
    {
        if (buffer_pos >= (size_t)bytes_read) /* Cast bytes_read to size_t */
        {
            bytes_read = read(fileno(stream), buffer, READ_SIZE);
            buffer_pos = 0;
        }

        if (bytes_read <= 0)
            break;

        if (buffer[buffer_pos] == '\n')
        {
            buffer_pos++;
            (*lineptr)[total_chars_read] = '\0';
            return total_chars_read + 1;
        }

        (*lineptr)[total_chars_read] = buffer[buffer_pos];
        buffer_pos++;
        total_chars_read++;
        chars_read++;

        if ((size_t)(total_chars_read + 1) >= *n) /* Cast total_chars_read and *n to size_t */
        {
            char *new_lineptr = (char *)realloc(*lineptr, *n + READ_SIZE);
            if (new_lineptr == NULL)
                return -1;
            *lineptr = new_lineptr;
            *n += READ_SIZE;
        }
    }

    if (total_chars_read == 0)
        return -1;

    (*lineptr)[total_chars_read] = '\0';
    return total_chars_read;
}