#include "main.h"

/**
 * _strdup - a function that duplicate a string of char
 *
 * @str: a string to duplicate
 *
 * Return: a string of char
 */

char *_strdup(char *str)
{
	int i = 0, j;
	char *ptr = NULL;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	str = str - i;
	for (j = 0; j <= i; j++)
		ptr[j] = str[j];
	return (ptr);
}
