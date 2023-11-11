#include "main.h"

/**
 * free_line - frees the allocated memory
 *
 * @line: pointer
 *
 * Return: void
 */
void free_line(char *line)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
}
