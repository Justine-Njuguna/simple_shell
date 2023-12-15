#include "commander.h"
#include "general_code.h"
#include "memories.h"
#include "txt.h"

/**
 * pattern_analyze - analyze patterns
 * @information: SHell info
 * @args: CLI args.
 *
 * Return: void.
 */

void pattern_analyze(general_t *information, char **args)
{
	int x;

	for (x = 0; args[x] != NULL; x++)
		args[x] = handle_patterns(information, args[x]);
}

/**
 * handle_patterns - takes up the patterns
 * @information: shell info
 * @str: input string
 *
 * Return: A string
 */

char *handle_patterns(general_t *information, char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] == '$' && str[x + 1] != '\0')
			str = val_replace(information, &x, str);
	}

	return (str);
}

/**
 * val_replace - replaces a val
 * @information: shell info
 * @idx: position for the information
 * @str: input string
 *
 * Return: replaced val
 */

char *val_replace(general_t *information, int *idx, char *str)
{
	int x, new_str, old_str;
	char *val;

	x = *idx;
	x++;

	val = replacement(information, idx, str + x);
	if (val == NULL)
	{
		str = _strcpy(str, "");
		return (str);
	}

	old_str = _strlen(str);
	new_str = _strlen(val) + 1;

	str = reallocate(str, old_str, new_str);
	str = _strcpy(str, val);

	free_ptr(val);
	*idx = x;
	return (str);
}
