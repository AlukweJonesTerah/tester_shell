#ifndef SHELL_HEADER_FILE
#define SHELL_HEADER_FILE

#include <stdio.h> /* for printf*/
#include <unistd.h> /* provide system calls functions */
#include <stdlib.h> /* provide a std library functions*/
#include <string.h> /* provide strtok function for tokenization */
#include <stddef.h>
#include <limits.h>
#include <stdarg.h>
#include <errno.h> /* provide errno and perror to be displayed*/
#include <sys/types.h> /* provide data type process-id */
#include <sys/wait.h> /* provide wait function used by pratent process*/
#include <sys/stat.h> /* provide use of stat function */
#include <signal.h> /* provide signal management */
#include <fcntl.h> /* provide open files*/
#define BUFFER_SIZE 1024
#define MAX_INPUT 255
#define MAX_ALIASES 32
#define READ_SIZE 1024

struct Alias {
    char *name;
    char *value;
};

struct Alias aliases[MAX_ALIASES];
int num_aliases = 0;

char *last_command = NULL;


void custom_printf(const char *format, ...);
struct Alias *find_alias(const char *name);
void custom_printf2(const char *format);
struct Alias *find_alias(const char *name);
void handle_alias(char *args[]);
void handle_env(void);
void handle_setenv(char *args[]);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void handle_unsetenv(char *args[]);
int main(int argc, char *argv[]);
int execute_command(char *command);
int commands_separator(char *input, char *commands[], int max_commands);
void custom_strcpy(char *dest, const char *src);
void execute_logical_commands(char *commands[], int num_commands, const char *logical_operator);
int split_input(char *input, char *argv[], int max_args);
void execute_interactive_mode();
void execute_file_mode(const char *filename);
int is_executable(const char *file);
void custom_prompt();
int find_command(const char *command, const char *path, char *full_path);
void handle_cd(char *args[]);
void custom_strcat(char *dest, const char *src);

#endif /* SHELL_HEADER_FILE */