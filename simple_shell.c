#include "shell.h"
/**
* main - The super simple shell
* @ac: arguments
*
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	char *line;
	char **args;

	(void)ac;
	while (1)
	{
		line = get_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		line[strcspn(line, "\n")] = '\0';

		args = str_tok(line);
		fork_execv_wait(args, env, av[0]);

		free(line);
		free(args);
	}
	return (0);
}
