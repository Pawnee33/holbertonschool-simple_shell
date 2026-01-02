#include "shell.h"
/**
* get_line - reads a complete line from an
* input
* Return: line to read
*/
char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		printf("($) ");
		fflush(stdout);
	}

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
