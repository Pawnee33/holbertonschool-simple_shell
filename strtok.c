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
	int slider = 0;


	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		return (NULL);
	}

	token = strtok(line, separator);
	while (token != NULL)
	{
		args[slider] = token;
		slider++;
		token = strtok(NULL, separator);
	}
	args[slider] = NULL;

	return (args);
}
