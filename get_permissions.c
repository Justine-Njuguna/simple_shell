#include "commander.h"
#include "general_code.h"

/**
 * check_is_executable - check if a fname has permissions
 * @fname: Filename to check
 *
 * Return: On success, PERMISSIONS else NON_PERMISSIONS
 */

int check_is_executable(char *fname)
{
	struct stat status;

	if (stat(fname, &status) == 0)
	{
		if (status.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * check_is_file - Check if is a file or binary
 * @commands: File to check
 *
 * Return: If is a file with the correct permissions, PERMISSIONS
 * If is a file but not have permissions or doesn't exists, NON_PERMISSIONS
 * If is not a file, NON_FILE
 **/

int check_is_file(char *commands)
{
	int x, weight;

	weight = _strlen(commands);
	for (x = 0; x < weight; x++)
		if (commands[x] == '/')
			return (check_is_executable(commands));

	return (NON_FILE);
}
