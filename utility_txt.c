#include "txt.h"

/**
 * _strlen - Returns the length of a string
 * @message: String to calc length
 *
 * Return: Length of the string.
 */

int _strlen(char *message)
{
	int x;

	for (x = 0; message[x] != '\0'; x++)
		;

	return (x);
}

/**
 * _strcat - Concats two strings
 * @destination: Str concat
 * @source: String source
 *
 * Return: A str concat
 */
char *_strcat(char *destination, char *source)
{
	int l_dest, x;

	l_dest = _strlen(destination);

	for (x = 0; source[x] != '\0'; x++, l_dest++)
		destination[l_dest] = source[x];

	destination[l_dest] = '\0';

	return (destination);
}

/**
 * _strcpy - Copy a string to another
 *
 * @destination: Destination copy
 * @source: Source for copy
 *
 * Return: Return the value of dest
 */

char *_strcpy(char *destination, char *source)
{
	int x;

	for (x = 0; source[x] != '\0'; x++)
		destination[x] = source[x];

	destination[x] = '\0';

	return (destination);
}

/**
 * _strdup - Ptr to a newly allocated space in memory
 * @string: Str to copy
 *
 * Return: Copied string.
 */

char *_strdup(char *string)
{
	int weight, x;
	char *destination;

	if (string == NULL)
		return (NULL);

	weight = _strlen(string) + 1;
	destination = malloc(weight * sizeof(char));
	if (destination == NULL)
		return (NULL);

	for (x = 0; x < weight; x++)
		*(destination + x) = *(string + x);

	/* (destination + x) = 0; */

	return (destination);
}

/**
 * _strcmp - Compare two strings
 * @string1: string 1
 * @string2: string 2
 *
 * Return: Integer
 */

int _strcmp(char *string1, char *string2)
{
	int x;

	for (x = 0; string1[x] != '\0'; x++)
	{
		if (string1[x] != string2[x])
			return (string1[x] - string2[x]);
	}

	return (0);
}
