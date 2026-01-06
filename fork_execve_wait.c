#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
*
* Return: void
*/
void fork_execv_wait(char **args, char **env, char *programme)
{
	char *path_value = get_path_value(env);
	char *full_path = resolve_command(args[0], path_value);

	if (full_path == NULL)
	{
		errno = ENOENT;
		perror(av0); /* av0 = ton nom de programme, ex: av[0] depuis main */
		return;
	}
	
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
			perror("execve");
		}
		free(entire_path);
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
		free(entire_path);
	}
}
