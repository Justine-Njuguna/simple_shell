#include "our_builtins.h"

/**
 * builtin_files - Checks and executes the builtin commands.
 *
 * @information: Info about the shell.
 * @args: Commands and args.
 *
 * Return: command if is a builtin TRUE | FALSE
 */

int builtin_files(general_t *information, char **args)
{
	int status;

	status = check_the_builtins(information, args);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}

/**
 * check_the_builtin - Check if the command is a builtin or not.
 * @information: Info about the shell.
 * @args: Arguments of the comms.
 *
 * Return: If is a builtin, _TRUE else _FALSE.
 */

int check_the_builtins(general_t *information, char **args)
{
	int x, weight;
	builtin_t builtins[] = {
		{"exit", bin_exits},
		{"env", bin_env_1}
	};

	weight = sizeof(builtins) / sizeof(builtins[0]);
	for (x = 0; x < weight; x++)
	{
		if (_strcmp(information->command, builtins[x].command) == 0)
		{
			builtins[x].func(information, args);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
