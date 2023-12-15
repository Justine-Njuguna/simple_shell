#include "txt.h"

/**
 * print_error - Print a message to STDERR
 * @message: Message to print
 *
 * Return: Bytes printed
 */

int print_error(char *message)
{
	return (print_to_fdesc(message, STDERR));
}
