#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
*
* Return: void
*/
void fork_execv_wait(char **args, char **env)
{
	pid_t pid;
	char *entire_path = _which(args[0], env);

	if (entire_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(entire_path, args, env) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
		free(entire_path);
	}
	else
	{
		perror("fork");
	}
}
