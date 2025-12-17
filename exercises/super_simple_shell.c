#include "shell.h"
/**
* main - The super simple shell
*
* Return: 0
*/
int main(void)
{
	char *line;
	char **args;


	while (1)
	{
		line = get_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		args = str_tok(line);
		fork_execv_wait(args);
	
		free(args);
		free(line);	
	}
	return (0);
}
	