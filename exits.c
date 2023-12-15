#include "our_builtins.h"
#include "general_code.h"

/**
 * bin_exits - Exit builtin
 * @information: Shell info
 * @args: args received
 */

void bin_exits(general_t *information, char **args)
{
	int stat_code, stats;

	stats = _TRUE;
	if (args[1] != NULL)
		stats = nums_control(information, args[1]);

	if (stats == _FALSE)
		return;

	stat_code = information->status_code;

	free_double_ptr((void **) args);
	free_ptr((void *) information->buffer);
	free_ptr((void *) information->environment);
	free_ptr((void *) information);

	exit(stat_code);
}

/**
 * nums_control - controls exit arg
 * @information: Shell info
 * @num: builtin arg
 *
 * Return: if arg is valid then _TRUE else _FALSE
 */

int nums_control(general_t *information, char *num)
{
	int _num;

	_num = check_is_atoi(num);

	if (_num < 0 || contains_letter(num))
	{
		information->status_code = 2;
		information->error_code = _CODE_ILLEGAL_NUMBER;
		err_xtra(information, num);
		return (_FALSE);
	}

	if (_num > 255)
		information->status_code = _num % 256;
	else
		information->status_code = _num;

	return (_TRUE);
}
