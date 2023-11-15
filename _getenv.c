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
