#include "shell.h"
/**
* fork_execv_wait - create a child processus
* that executes the command
* @args: the command to executes
*
* Return: void
*/
void fork_execv_wait(char **args)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		execve("/bin/ls", args, NULL);
		perror("execve");
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
