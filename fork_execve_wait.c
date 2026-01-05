#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
* @env: array of strings representing the shell environment
* @programme: shell name for error messages
*
* Return: void
*/
void fork_execv_wait(char **args, char **env, char *programme)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", programme, args[0]);
		}
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
