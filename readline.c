#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 *
 * Return: Pointer to the read line.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t inp;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	inp = getline(&line, &len, stdin);
	if (inp == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
