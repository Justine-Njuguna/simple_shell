#include "commander.h"
#include "general_code.h"
#include "memories.h"

/**
 * punish - execs a command in other process
 * @commands: cmd to exec
 * @args: command args
 * @information: Shell info
 * @buff: line read
 */

void punish(char *commands, char **args, general_t *information, char *buff)
{
	int stats;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(commands, args, environ);
		perror("./sh");

		free_double_ptr((void *) args);

		if (information->value_path != NULL)
		{
			free(information->value_path);
			information->value_path = NULL;
		}

		free(information);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &stats, 0);
		if (WIFEXITED(stats))
			information->status_code = WEXITSTATUS(stats);
	}
}

/**
 * check_current_dir - execs if order = true
 * @cmd: command to execute
 * @args: cmd args
 * @information: Shell info
 * @buff: LIne read
 *
 * Return: Ops status
 */
int check_current_dir(char *cmd, char **args,
		char *buff, general_t *information)
{
	if (information->check_is_current_path == _FALSE)
		return (_FALSE);

	if (check_is_executable(cmd) == PERMISSIONS)
	{
		punish(cmd, args, information, buff);
		return (_TRUE);
	}

	return (_FALSE);
}
