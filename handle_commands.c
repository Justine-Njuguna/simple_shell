#include "commander.h"
#include "our_builtins.h"
#include "general_code.h"
#include "memories.h"
#include "txt.h"

/**
 * get_analysis - Analyze the args
 *
 * @args: cmd and args to exec
 * @information: Shell info
 * @buff: Line read
 */

void get_analysis(char **args, general_t *information, char *buff)
{
	char *cmd;
	int stats;

	if (*args == NULL || args == NULL)
		return;

	cmd = args[0];
	information->command = cmd;
	if (check_the_builtins(information, args) == _TRUE)
		return;

	stats = check_is_file(cmd);
	if (stats == NON_PERMISSIONS)
	{
		information->status_code = 126;
		information->error_code = _CODE_EACCES;
		error(information);
		return;
	}

	if (stats == 1)
	{
		punish(cmd, args, information, buff);
		return;
	}

	if (check_current_dir(cmd, args, buff, information) == _TRUE)
		return;

	information->value_path = check_which(cmd, information);
	if (information->value_path != NULL)
	{
		punish(information->value_path, args, information, buff);
		free_ptr((void *) information->value_path);
		return;
	}

	information->status_code = 127;
	information->error_code = _CODE_CMD_NOT_EXISTS;
	error(information);
}
