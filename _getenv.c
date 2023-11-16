#include "main.h"

/**
 * _getenv - a function that gets an environment variable
 *
 * @name: the variable
 *
 * Return: the environment
 */

char *_getenv(char *name)
{
	char *p, *str1, *str2, *inv;
	int i;

	for (i = 0; environ[i]; i++)
	{
		p = _strdup(environ[i]);
		str1 = strtok(p, "=");
		if (_strcmp(str1, name) == 0)
		{
			str2 = strtok(NULL, "\n");
			inv = _strdup(str2);
			free(p);
			return (inv);
		}
		free(p);
	}
	return (NULL);
}



/**
 * _getfullenv - a function that gets the full environment
 *
 * Return: the full environment
 */

void _getfullenv(void)
{
	char **fullenv;
	int i;

	if (environ == NULL)
		return;

	for (i = 0; environ[i]; i++)
		continue;

	fullenv = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		fullenv[i] = _strdup(environ[i]);
		write(STDOUT_FILENO, fullenv[i], _strlen(fullenv[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	while (i > 0)
	{
		free(fullenv[i - 1]), fullenv[i - 1] = NULL;
		i = i - 1;
	}
	free(fullenv), fullenv = NULL;
}
