#include "shell.h"

/**
 * main - simple shell main function.
 *
 * @con: count of args.
 * @argv: list of arguments.
 *
 * Return: always 0 succes.
*/
int main(int con, char **argv)
{
	char *line = NULL, **cmd = NULL;
	int status = 0, indx = 0;
	(void) con;

	while (1)
	{
		line = read_line();
		if (line == NULL)/* EOF ctr + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			fflush(stdout);
			return (status);
		}

		indx++;
		cmd = get_token(line);
		if (!cmd)
			continue;
		if (is_builtcmd(cmd[0]))
			handl_builtcmd(cmd, argv, &status, indx);
		else
		{
			status = _executer(cmd, argv, indx);
		}
	}
}
