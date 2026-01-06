#include "shell.h"

char *search_path(char **env)
{
	int i;
	char *path = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
		}
	}
	return (path);
}