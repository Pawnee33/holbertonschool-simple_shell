#include "shell.h"
/**
* _which - find the PATH of a command in the env
* @env: environment variables to
* finds PATH
* @order: command to search in PATH
*
* Return: pointer to a string containing the path to a command
* or NULL
*/
char *_which(char *order, char **env)
{
	int index;
	char *folder, *entire_path, *path = NULL;
	char *delimiter = ":";
	char *slash = "/";
	struct stat st;

	for (index = 0; env[index] != NULL && path == NULL; index++)
	{
		if (strncmp(env[index], "PATH=", 5) == 0)
		{
			path = env[index] + 5;
		}
	}
	folder = strtok(path, delimiter);
	while (folder != NULL)
	{
		entire_path = malloc(strlen(folder) + 1 + strlen(order) + 1);
		if (entire_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		strcpy(entire_path, folder);
		strcat(entire_path, slash);
		strcat(entire_path, order);

		if (stat(entire_path, &st) == 0)
		{
			return (entire_path);
		}
		free(entire_path);
		folder = strtok(NULL, delimiter);
	}
	return (NULL);
}
