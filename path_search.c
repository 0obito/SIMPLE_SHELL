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
	struct stat sait;
	char *path, *full_path, **dirs;

	for (j = 0; first_cmd[j]; j++)
	{
		if (first_cmd[j] == '/')
		{
			if (stat(first_cmd, &sait) == 0)
				return (_strdup(first_cmd));
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
		if (full_path)
		{
			_strcp(full_path, dirs[i]);
			_strcat(full_path, "/");
			_strcat(full_path, first_cmd);
			if (stat(full_path, &sait) == 0)
			{
				freeall(path, dirs);
				return (full_path);
			}
			free_line(full_path);
		}
		i++;
	}
	freeall(path, dirs);
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

/**
 * freeall - a function that frees all
 *
 * @ptr: first material
 * @doubleptr: second material
 */
void freeall(char *ptr, char **doubleptr)
{
	free_line(ptr);
	free_ressources(doubleptr);
}
