#include "main.h"

/**
 * free_ressources - frees the allocated memory
 *
 * @command: double pointer
 *
 * Return: void
 */
void free_ressources(char **command)
{
	int i = 0;

	if (command != NULL)
	{
		for (i = 0; command[i] != NULL; i++)
		{
			free(command[i]);
			command[i] = NULL;
		}

		free(command);
		command = NULL;
	}
}
