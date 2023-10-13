#include "shell.h"

/**
 * freearray - Free memory allocated for an array of strings.
 * @ary: The array of strings to free.
 */

void freearray(char **ary)
{
	int i;

	if (!ary)
		return;

	for (i = 0; ary[i]; i++)
	{
		free(ary[i]);
		ary[i] = NULL;
	}

	free(ary), ary = NULL;
}
