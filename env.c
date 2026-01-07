#include "shell.h"
/**
* env - Prints all environment variables
* @env: Array of environment variables
*/
void print_env(char **env, char **argv, char *line)
{
	int read = 0;

	while (env[read] != NULL)
	{
		printf("%s\n", env[read]);
		read++;
	}
	if (argv && argc[0] && strcmp(argv[0], "exit") == 0)
    {
        free(args);
        free(line);
        exit(last_status);
    }
}