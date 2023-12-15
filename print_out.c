#include "general_code.h"
#include "txt.h"

/**
 * _putchar - Print a character to STDOUT
 *
 * @a: Character to print
 *
 * Return: On success 1
 * On error -1
 **/
int _putchar(char a)
{
	return (write(STDOUT, &a, 1));
}

/**
 * print - Print a message to STDOUT
 * @message: Message to print
 *
 * Return: On success, bytes printed, else -1
 */

int print(char *message)
{
	return (print_to_fdesc(message, STDOUT));
}
