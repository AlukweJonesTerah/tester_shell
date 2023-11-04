#include "shell.h"
/**
 * execute_file_mode - Handle the file mode of the shell
 * @filename: The name of the file to execute
 */
void execute_file_mode(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_INPUT];
    
    if (file == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        execute_command(line);
    }

    fclose(file);
}