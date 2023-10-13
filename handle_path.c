#include "shell.h"

/**
 * _get_path - Get the full path to an executable command.
 * @cmd: The name of the command.
 *
 * Return: The full path to the command or NULL if not found.
 */

char *_get_path(char *cmd)
{
	char *path_env, *full, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full)
		{
			_strcpy(full, dir);
			_strcat(full, "/");
			_strcat(full, cmd);
			if (stat(full, &st) == 0)
			{
				free(path_env);
				return (full);
			}
			free(full), full = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
