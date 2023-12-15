#include "commander.h"
#include "general_code.h"
#include "txt.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
 * _get_env - Gets an env var
 * @name: Env var to get
 *
 * Return: On success, val of @name else NULL
 */

char *_get_env(const char *name)
{
	char **env;
	char *auxiliary, *tokens, *val;
	int weight;

	weight = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		auxiliary = _strdup(*env);

		tokens = strtok(auxiliary, "=");
		if (tokens == NULL)
		{
			free(auxiliary);
			return (NULL);
		}

		if (_strlen(tokens) != weight)
		{
			free(auxiliary);
			continue;
		}

		if (_strcmp((char *) name, auxiliary) == 0)
		{
			tokens = strtok(NULL, "=");
			val = _strdup(tokens);

			free(auxiliary);
			return (val);
		}

		free(auxiliary);
	}

	return (NULL);
}

/**
 * check_which - Find the needed dir.
 * @fname: cmd received
 * @information: Shell info
 *
 * Return: ptr str with path else NULL
 */

char *check_which(char *fname, general_t *information)
{
	char *path, *temp_path, *tokens;
	char *swish;
	int weight;

	(void) information;

	path = _get_env("PATH");
	if (path == NULL)
		return (NULL);

	tokens = strtok(path, ":");

	weight = _strlen(fname) + 2;
	swish = malloc(weight * sizeof(char));
	swish = _strcpy(swish, "/");
	swish = _strcat(swish, fname);

	while (tokens != NULL)
	{
		temp_path = malloc(_strlen(tokens) + weight);
		temp_path = _strcpy(temp_path, tokens);
		temp_path = _strcat(temp_path, swish);

		if (check_is_executable(temp_path) == PERMISSIONS)
		{
			free(swish);
			free(path);
			return (temp_path);
		}
		tokens = strtok(NULL, ":");

		free(temp_path);
	}

	free(path);
	free(swish);

	return (NULL);
}

/**
 * check_is_current_path - checks the order of the path
 *
 * @path: path to check
 * @information: Shell info
 *
 * Return: void.
 */

void check_is_current_path(char *path, general_t *information)
{
	information->check_is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		information->check_is_current_path = _TRUE;
}

/**
 * check_get_full_env - Get all envs
 */

void check_get_full_env(void)
{
	char **temp;
	int x;

	for (x = 0, temp = environ; temp[x] != NULL; x++)
	{
		print(temp[x]);
		_putchar('\n');
	}
}
