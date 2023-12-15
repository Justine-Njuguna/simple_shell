#include "general_code.h"
#include "shell.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: arg vector
 *
 * Return: 0 on success else 1.
 */

int main(int argc, char **argv)
{
	general_t *information;
	int stat_code;

	information = malloc(sizeof(general_t));
	if (information == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	information->pid = getpid();
	information->status_code = 0;
	information->n_commands = 0;
	information->argc = argc;
	information->argv = argv;
	information->mode = isatty(STDIN) == INTERACTIVE;
	start(information);

	stat_code = information->status_code;

	free(information);

	return (stat_code);
}
