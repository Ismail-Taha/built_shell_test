#include "shell.h"

/**
 * pr_error - Print an error message to standard error.
 * @name: The program name.
 * @cmd: The command causing the error.
 * @indx: The index of the command in the input.
 */

void pr_error(char *name, char *cmd, int indx)
{
    char *index, mesg[] = ": not found\n";
    
    index = int_asc(indx);
    
    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mesg, _strlen(mesg));
    
    free(index);
    
}
