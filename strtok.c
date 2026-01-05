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
	char *separator = " \t\n";
	char **args, *token;


	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, separator);
	args[0] = token;
	args[1] = NULL;

	return (args);
}
