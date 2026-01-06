#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
* @env: environment variables
* @programme: name of the shell
*
* Return: void
*/
void fork_execv_wait(char **args, char **env, char *programme)
{
	pid_t pid;

	if (args[0] == NULL)
		return;

	pid = fork();

	if (pid == 0)
	{
		execve(args[0], args, env);

		fprintf(stderr, "%s: 1: %s: not found\n", programme, args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}
