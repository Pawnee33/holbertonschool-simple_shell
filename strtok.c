#include "shell.h"
/**
* str_tok - separates each token from
* the line
* @line: The line tu cut each token
*
* Return: args
*/
char **str_tok(char *line)
{
	char **args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	args[0] = line;
	args[1] = NULL;
	
	return (args);
}
