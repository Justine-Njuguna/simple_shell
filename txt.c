#include "txt.h"
#include "commander.h"
#include "general_code.h"
#include "memories.h"

/**
 * prompt_me - Print the prompt
 * @information: Struct general info
 */

void prompt_me(general_t *information)
{
	if (information->mode == NON_INTERACTIVE)
		return;

	print("myShell$: ");
}

/**
 * get_prompt - Read lines in the prompt
 *
 * Return: Buffer read else NULL
 */

char *get_prompt()
{
	char *buffer;
	int resolution;
	size_t weight;

	buffer = NULL;

	resolution = getline(&buffer, &weight, stdin);

	if (resolution == EOF)
	{
		free_ptr((void *) buffer);
		return (NULL);
	}

	return (buffer);
}

/**
 * prompt_start - loop reading text.
 * @information: general struct info
 *
 * Return: Buffer read else NULL
 */

void prompt_start(general_t *information)
{
	char *buffer;
	char **args;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt_me(information);

		path = _get_env("PATH");
		check_is_current_path(path, information);

		information->environment = path;
		buffer = get_prompt();
		if (buffer == NULL)
		{
			print(information->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}

		information->n_commands++;
		if (buffer[0] != '\n')
		{
			args = word_split(buffer, " \t\n");

			information->arguments = args;
			information->buffer = buffer;
			pattern_analyze(information, args);
			get_analysis(args, information, buffer);

			free_double_ptr((void *) args);
		}

		free_ptr((void *) buffer);
		free_ptr((void *) path);
	}
}

/**
 * sigintHandler - Handler for SIGINT
 * @sig_num: unused params
 */

void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
