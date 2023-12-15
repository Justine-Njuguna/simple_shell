#include "errhandlers.h"

/**
 * msg_selector - Select the message that matches the error code
 * @information: Shell info
 *
 * Return: Err message
 */

char *msg_selector(general_t information)
{
	int x, x_options;
	error_t msgs[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	x_options = sizeof(msgs) / sizeof(msgs[0]);
	for (x = 0; x < x_options; x++)
		if (information.error_code == msgs[x].code)
			return (msgs[x].message);

	return ("");
}

/**
 * error - Prints the err
 * @information: Shell info
 */
void error(general_t *information)
{
	char *msg;
	char *num;
	char *auxiliary;
	int weight_num, weight_msg;

	num = NULL;
	msg = msg_selector(*information);
	num = check_to_string(information->n_commands);

	weight_num = _strlen(num);
	weight_msg = _strlen(information->argv[0]);

	auxiliary = malloc(weight_msg + weight_num + 3);

	auxiliary = _strcpy(auxiliary, information->argv[0]);
	auxiliary = _strcat(auxiliary, ": ");
	auxiliary = _strcat(auxiliary, num);

	msg = join_words(auxiliary, information->command, msg, ": ");
	print_error(msg);

	free(msg);
	free(num);
	free(auxiliary);
}

/**
 * err_xtra - extra error info
 * @information: Shell info
 * @xtra: Extra info
 */

void err_xtra(general_t *information, char *xtra)
{
	char *msg, *num, *auxiliary, *auxiliary2;
	int weight_num, weight_msg, weight_xtra;

	num = NULL;
	msg = msg_selector(*information);
	num = check_to_string(information->n_commands);

	weight_num = _strlen(num);
	weight_msg = _strlen(information->argv[0]);
	weight_xtra = _strlen(xtra);

	auxiliary = malloc(weight_msg + weight_num + 3);
	auxiliary = _strcpy(auxiliary, information->argv[0]);
	auxiliary = _strcat(auxiliary, ": ");
	auxiliary = _strcat(auxiliary, xtra);


	auxiliary2 = malloc(_strlen(msg) + weight_xtra + 3);
	auxiliary2 = _strcpy(auxiliary2, msg);
	auxiliary = _strcat(auxiliary, ": ");
	auxiliary2 = _strcat(auxiliary2, xtra);

	msg = join_words(auxiliary, information->command, auxiliary2, ": ");
	print_error(msg);

	free(msg);
	free(num);
	free(auxiliary);
	free(auxiliary2);
}
