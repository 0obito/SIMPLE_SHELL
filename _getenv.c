#include "main.h"

/**
 * _getenv - a function that gets an environment variable
 * @name: the variable
 *
 * Return: the environment
 */

char *_getenv(char *name)
{
	char *p, *str1, *str2, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		p = _strdup(environ[i]);
		str1 = strtok(p, "=");
		if (_strcmp(str1, name) == 0)
		{
			str2 = strtok(NULL, "\n");
			env = _strdup(str2);
			free(p), p = NULL;
			return (env);
		}
		free(p), p = NULL;
	}
	return (NULL);
}

int main ()
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}
