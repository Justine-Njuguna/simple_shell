#include "general_code.h"
#include "txt.h"
#include "commander.h"

/**
 * replacement - replaces info at a certain index
 * @information: Info to be replaced
 * @idx: Position
 * @str: The string containing the info.
 *
 * Return: Pointer to the replacement string..
 */

char *replacement(general_t *information, int *idx, char *str)
{
	char *temp;
	char syllable;

	(void) idx;

	syllable = *str;
	if (syllable != '?' && syllable != '$')
	{
		temp = replace_environment(information, str);
		return (temp);
	}

	temp = (syllable == '$') ? check_to_string(information->pid) :
		check_to_string(information->status_code);

	return (temp);
}

/**
 * replace_environment - Replaces the env
 * @information: the info
 * @env: Replaced environment
 *
 * Return: replaced env
 */

char *replace_environment(general_t *information, char *env)
{
	char *envi;

	(void) information;

	envi = _get_env(env);
	if (envi != NULL)
		return (envi);

	return (NULL);
}
