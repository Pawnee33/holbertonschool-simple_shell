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
	char *entire_path;

	entire_path = strdup(args[0]);
	if (entire_path == NULL)
	{
		perror("strdup");
		return;
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(entire_path, args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", programme, args[0]);
			free(entire_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
		free(entire_path);
	}
	else
	{
		perror("fork");
		free(entire_path);
	}
}
