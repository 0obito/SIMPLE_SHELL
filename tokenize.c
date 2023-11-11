#include "main.h"

/**
 * tokenize - a function that tokenize a line
 *
 * @line: the line to tokenize
 *
 * Return: array of strings tokenized
 */

char **tokenize(char *line)
{
	char *str1 = NULL, *str2 = NULL, *dup = NULL;
	int count = 0, j = 0;
	char **token = NULL;

	if (line == NULL)
		return (NULL);
	dup = _strdup(line);

	str1 = strtok(dup, " \t\n");
	if (str1 == NULL)
	{
		free(dup), dup = NULL;
		return (NULL);
	}
	while (str1 != NULL)
	{
		count++;
		str1 = strtok(NULL, " \t\n");
	}
	count++;
	free(dup), dup = NULL;

	token = malloc(sizeof(char *) * count);
	if (token == NULL)
		return (NULL);
	str2 = strtok(line, " \t\n");
	if (str2 == NULL)
		return (NULL);

	while (str2 != NULL)
	{
		token[j] = _strdup(str2);
		str2 = strtok(NULL, " \t\n");
		j++;
	}
	token[j] = NULL;
	return (token);
}
