#include "main.h"

/**
 * path_search - a function that searches the PATH directories
 * to find a file that is similar to the called command
 *
 * @first_cmd: the called command to look for
 *
 * Return: full path to the command
 */
char *path_search(char *first_cmd)
{
	int j, i = 0;
	char *path, *full_path;
	char **dirs;

	if (first_cmd == NULL)
		return (NULL);
	for (j = 0; first_cmd[j]; j++)
	{
		if (first_cmd[j] == '/')
		{
			if (stat(first_cmd, &saint) == 0)
					return (first_cmd);
			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	dirs = tokenize(path, ":\n\t");
	while (dirs[i])
	{
		full_path = malloc(_strlen(dirs[i]) + _strlen(first_cmd) + 2);
		if (full_path == NULL)
		{
			free_line(path);
			free_ressources(dirs);
			return (NULL);
		}
		_strcp(full_path, dirs[i]);
		_strcat(full_path, "/");
		_strcat(full_path, first_cmd);

		if (stat(full_path, &saint) == 0)
		{
			free_line(path);
			free_ressources(dirs);
			return (full_path);
		}
		free_line(full_path);

		i++;
	}
	free_line(path);
	free_ressources(dirs);
	return (NULL);
}


/**
 * _strcat - a function that imitates strcat behavior
 *
 * @str1: string 1
 * @str2: string 2
 */
void _strcat(char *str1, char *str2)
{
	int i, len1 = _strlen(str1);

	i = 0;
	while (str2[i])
	{
		str1[len1 + i] = str2[i];
		i++;
	}

	str1[len1 + i] = '\0';
}
