#include "main.h"

/**
 * free_ressources - frees the allocated memory
 *
 * @cmd: double pointer
 *
 * Return: void
 */
void free_ressources(char **cmd)
{
	int i = 0;

	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
		{
			free(cmd[i]);
			cmd[i] = NULL;
		}

		free(cmd);
		cmd = NULL;
	}
}
