#include "shell.h"

/**
 * is_builtcmd - Check if a command is a built-in command.
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */

int is_builtcmd(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "setenv", "unsetenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handl_builtcmd - Handle built-in commands.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @status: The status variable to set.
 * @indx: The index of the command in the input.
 */

void handl_builtcmd(char **cmd, char **argv, int *status, int indx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shel(cmd, argv, status, indx);

	else if (_strcmp(cmd[0], "env") == 0)
		pr_env(cmd, status);
}

/**
 * exit_shel - Handle the "exit" built-in command.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @status: The status variable to set.
 * @indx: The index of the command in the input.
 */

void exit_shel(char **cmd, char **argv, int *status, int indx)
{
	int exit_status = (*status);

	if (cmd[1])
	{
		if (is_num_positive(cmd[1]))
		{
			exit_status = _atoi(cmd[1]);
		}
		else
		{
			exit_error(cmd, argv, indx);
			freearray(cmd);
			(*status) = 2;
			return;
		}
	}
	freearray(cmd);
	exit(exit_status);
}
