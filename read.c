#include "main.h"

/**
 * read_input - reads from standard input
 *
 * Return: line pointer
 */
char *read_input(void)
{
	char *lineptr = NULL;
	size_t size = 0;
	ssize_t n;

	n = getline(&lineptr, &size, stdin);

	if (n == (ssize_t)-1)
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}

	return (lineptr);
}
