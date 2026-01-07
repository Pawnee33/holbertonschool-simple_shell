#include "shell.h"
/**
* print_env - Prints all environment variables
* @env: Array of environment variables
*/
void print_env(char **env)
{
	int read = 0;

	while (env[read] != NULL)
	{
		printf("%s\n", env[read]);
		read++;
	}
}
/**
* built_ins - Executes built-in functions exit and env
* @args: Array of commands
* @env: Environment
* @line: Input line
* @status: last exit status
*
* Return: 1 if a built-in function was executed,
* 0 otherwise
*/
int built_ins(char **args, char **env, char *line, int status)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(status);
	}
	return (0);
}
