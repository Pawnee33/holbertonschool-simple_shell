#include "shell.h"
/**
* main - The super simple shell
*
* Return: 0
*/
int main(int ac, char **av, char **env)
{
	char *line;
	char **args;

	(void)ac;
	(void)av;
	while (1)
	{
		line = get_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		args = str_tok(line);
		fork_execv_wait(args, env);

		free(line);
		free(args);
	}
	return (0);
}
