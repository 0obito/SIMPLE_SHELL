#include "main.h"

/**
 * _strlen - calculates length of a string
 *
 * @string: the string to calculate its length
 *
 * Return: length
 */
int _strlen(char *string)
{
	int length;

	length = 0;
	while (string[length])
	{
		length++;
	}

	return (length);
}
