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
	char *line;
	char **args;
	int read = 0;

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
		if (strcmp(args[0], "env") == 0)
		{
			while (env[read] != NULL)
			{
				printf("%s\n", env[read]);
				read++;
			}
		}
		else
		{
			fork_execv_wait(args, env, av[0]);
		}

		free(line);
		free(args);
	}
	return (0);
}
