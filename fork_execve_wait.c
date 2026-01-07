#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
* @env: environment variables
* @programme: name of the shell
*
* Return: 0
*/
int fork_execv_wait(char **args, char **env, char *programme)
{
	pid_t pid;
	char *entire_path;
	int status;

	if (strchr(args[0], '/'))
	{
		entire_path = strdup(args[0]);
	}
	else
	{
		entire_path = _which(args[0], env);
	}
	if (entire_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", programme, args[0]);
		return (127);
	}
	pid = fork();

	if (pid == 0)
	{
		execve(entire_path, args, env);
		fprintf(stderr, "%s: 1: %s: not found\n", programme, args[0]);
		free(entire_path);
		exit(127);
	}
	else if (pid > 0)
	{
		wait(&status);
		free(entire_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else
	{
		perror("fork");
		free(entire_path);
		return (1);
	}
	return (0);
}
