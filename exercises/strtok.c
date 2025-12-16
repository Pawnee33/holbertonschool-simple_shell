#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *line = NULL, *separator = " \t\n";
	char **args, *token;
	int slider;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			break;
		}
	
	args = malloc(sizeof(char *) *10);
	slider = 0;

	token = strtok(line, separator);
	while (token != NULL)
	{
		args[slider] = token;
		slider++;
		token = strtok(NULL, separator);
	}
	args[slider] = NULL;

	for (int i = 0; args[i] != NULL; i++)
		printf("arg[%d] = %s\n", i, args[i]);
	free(args);
	}
	free(line);
	return (0);
}
