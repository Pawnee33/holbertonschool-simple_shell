#include "shell.h"
/**
* main - The super simple shell
* @ac: arguments
* @av: array of arguments
* @env: anvironment variables
*
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	char *line, **args;
	int status = 0;

	(void)ac;
	while (1)
	{
		line = get_line();
		if (line == NULL)
			break;
		args = str_tok(line);
		if (args == NULL)
		{
			free(line);
			continue;
		}
		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}
		if (built_ins(args, env, line, status))
			continue;
		else
		{
			status = fork_execv_wait(args, env, av[0]);
			if (status == 127)
			{
				free(line);
				free(args);
				exit(127);
			}
		}
		free(line);
		free(args);
	}
	return (0);
}
