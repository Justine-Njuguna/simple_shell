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
		{"env", bin_env_1},
		{"setenv", bin_setenv},
		{"unsetenv", bin_unsetenv}
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

/**
 * bin_setenv - Set env var
 * @information: Shell info
 * @args: Cmd args
 */

void bin_setenv(general_t *information, char **args)
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		information->status_code = 2;
		information->error_code = _CODE_WRONG_ARGUMENTS;
		dprintf(STDERR_FILENO, "Usage: %s VARIABLE VALUE\n", args[0]);
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		information->status_code = 2;
		information->error_code = _CODE_SETENV_FAILURE;
		perror("Error");
	}
}

/**
 * bin_unsetenv - Unset env var
 * @information: Shell info
 * @args: cmd args
 */

void bin_unsetenv(general_t *information, char **args)
{
	if (args[1] == NULL || args[2] != NULL)
	{
		information->status_code = 2;
		information->error_code = _CODE_WRONG_ARGUMENTS;
		dprintf(STDERR_FILENO, "Usage: %s VARIABLE\n", args[0]);
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		information->status_code = 2;
		information->error_code = _CODE_UNSETENV_FAILURE;
		perror("Error");
	}
}
