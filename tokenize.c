#include "main.h"

/**
 * tokenize - a function that tokenize a line
 *
 * @line: the line to tokenize
 * @delimiter: the delimiters to separate tokens by
 *
 * Return: array of strings tokenized
 */

char **tokenize(char *line, char *delimiter)
{
	char *str1 = NULL, *str2 = NULL, *dup = NULL;
	int count = 0, j = 0;
	char **token = NULL;

	if (line == NULL)
		return (NULL);
	dup = _strdup(line);

	str1 = strtok(dup, delimiter);
	if (str1 == NULL)
	{
		free_line(dup);
		return (NULL);
	}
	while (str1 != NULL)
	{
		count++;
		str1 = strtok(NULL, delimiter);
	}
	count++;
	free_line(dup);

	token = malloc(sizeof(char *) * count);
	if (token == NULL)
		return (NULL);
	str2 = strtok(line, delimiter);
	if (str2 == NULL)
	{
		free(token);
		return (NULL);
	}
	while (str2 != NULL)
	{
		token[j] = _strdup(str2);
		str2 = strtok(NULL, delimiter);
		j++;
	}
	token[j] = NULL;
	return (token);
}
