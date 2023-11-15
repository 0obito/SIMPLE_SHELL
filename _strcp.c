#include "main.h"

/**
 * _strcp - copy characters into a string
 *
 * @dest: destination
 * @str: string to copy
 *
 * Return: nothing
 */
void _strcp(char *dest, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}
