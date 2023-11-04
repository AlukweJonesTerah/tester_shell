#include "shell.h"
/**
 * is_executable - Checks if a file is executable
 * @file: Path to the file
 * Return: 1 if executable, 0 otherwise
 */
int is_executable(const char *file)
{
    return (access(file, X_OK) == 0);
}