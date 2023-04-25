#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * display_prompt - display a prompt
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * read_command - read a command from stdin
 *
 * Return: a string containing the command or NULL on EOF
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;

	if (getline(&command, &len, stdin) == -1)
	{
		free(command);
		command = NULL;
	}

	return (command);
}

/**
 * execute_command - execute a command
 * @command: the command to execute
 */
void execute_command(char *command)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) /* child process */
	{
		/* execute command */
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else /* parent process */
	{
		/* wait for child process to finish */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * main - simple UNIX command line interpreter
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *command = NULL;
	int ret = EXIT_SUCCESS;

	while (1)
	{
		display_prompt();
		command = read_command();

		if (command == NULL) /* EOF */
			break;

		/* remove trailing newline */
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) > 0)
		{
			execute_command(command);
		}

		free(command);
		command = NULL;
	}

	return (ret);
}
