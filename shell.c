#include "shell.h"
/**
 * main - Simple Shell 1.0+ with command separators,
 * 
 * logical operators, and aliases
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        /* File mode: Read and execute commands from the specified file */
        execute_file_mode(argv[1]);
    } else if (argc == 1) {
        /* Interactive mode: Read and execute commands from stdin */
        execute_interactive_mode();
    } else {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
