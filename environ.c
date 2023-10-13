#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */

char *_getenv(char *var)
{
	char *env, *envicp, *key, *value;
	int i;

	for (i = 0; environ[i]; i++)
	{
		envicp = _strdup(environ[i]);
		key = strtok(envicp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(envicp);
			return (env);
		}
		free(envicp), envicp = NULL;
	}
	return (NULL);
}

/**
 * pr_env - Print the environment variables to the standard output.
 * @cmd: The command and arguments.
 * @status: The status variable to set.
 */
void pr_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(cmd);
	(*status) = 0;
}
