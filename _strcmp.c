#include "main.h"

/**
 * _strcmp - a functon that compares 2 strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 0 if they are the same
 */

int _strcmp(char *str1, char *str2)
{
	int sub = 0;

	sub = (int)*str1 - (int)*str2;
	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		sub = (int)*str1 - (int)*str2;
	}
	return (sub);
}
