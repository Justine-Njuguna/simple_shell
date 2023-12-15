#include "our_builtins.h"

/**
 * bin_env_1 - Implements the env builtin
 * @information: Shell info
 * @args: Commands
 *
 * Return: void
 */

void bin_env_1(general_t *information, char **args)
{
	(void) information;
	(void) args;

	check_get_full_env();
}
