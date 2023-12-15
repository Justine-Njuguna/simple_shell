#include "general_code.h"
#include "txt.h"
#include <unistd.h>

/**
 * _putchar_to_fdesc - Print a char to a specific fd
 * @c: Char to  print
 * @fd: Place to print the char
 *
 * Return: On success 1, else -1 and errno set
 */

int _putchar_to_fdesc(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * print_to_fdesc - Print a string
 * @message: string to print
 * @fd: Fd to print
 *
 * Return: On success, bytes printed else -1
 */

int print_to_fdesc(char *message, int fd)
{
	int weight;

	weight = _strlen(message);

	return (write(fd, message, weight));
}
