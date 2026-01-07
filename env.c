#include "shell.h"
/**
* env - Prints all environment variables
* @env: Array of environment variables
*/
void env(char **env)
{
	int read = 0;

	while (env[read] != NULL)
	{
		printf("%s\n", env[read]);
		read++;
	}
}
