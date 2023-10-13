#include "shell.h"

/**
 * _executer - Execute a command.
 * @cmd: The array of command and arguments.
 * @argv: The program's arguments.
 * @indx: The index of the command in the input.
 *
 * Return: The exit status of the executed command.
 */

int _executer(char **cmd, char **argv, int indx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _get_path(cmd[0]);
	if (!full_cmd)
	{
		pr_error(argv[0], cmd[0], indx);
		freearray(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freearray(cmd);
		}
	} else
	{
		waitpid(child, &status, 0);
		freearray(cmd);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
