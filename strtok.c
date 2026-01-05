#include "shell.h"
/**
* str_tok - separates each token from
* the line
* @line: The line tu cut each token
* @single_order: command
*
* Return: args
*/
char **str_tok(char *line, int single_order)
{
	char *separator = " \t\n";
	char **args, *token;
	int slider;


	args = malloc(sizeof(char *) * 10);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	slider = 0;

	token = strtok(line, separator);
	if (single_order != 0)
	{
		args[0] = token;
		args[1] = NULL;
		return (args);
	}
	while (token != NULL)
	{
		args[slider] = token;
		slider++;
		token = strtok(NULL, separator);
	}
	args[slider] = NULL;
	return (args);
}
