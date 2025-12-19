#include "shell.h"
/**
* search_path - search path in the env
* @env: env to search the path
* Return: path
*/
char *search_path(char **env)
{
	int index;
	char *path = NULL;

	for (index = 0; env[index] != NULL && path == NULL; index++)
	{
		if (strncmp(env[index], "PATH=", 5) == 0)
		{
			path = env[index] + 5;
		}
	}
	return (path);
}
/**
* _which - find the PATH of a command in the env
* @env: environment variables to finds PATH
* @order: command to search in PATH
* Return: pointer to a string containing the path to a command or NULL
*/
char *_which(char *order, char **env)
{
	char *folder, *entire_path, *path_dup, *path = NULL;
	char *delimiter = ":", *slash = "/";
	struct stat st;

	path = search_path(env);
	if (path == NULL)
	{
		return (NULL);
	}
	path_dup = strdup(path);
	folder = strtok(path_dup, delimiter);
	while (folder != NULL)
	{
		entire_path = malloc(strlen(folder) + 1 + strlen(order) + 1);
		if (entire_path == NULL)
		{
			perror("malloc");
			free(path_dup);
			return (NULL);
		}
		if (order[0] == slash)
			strcpy(entire_path, order);
		else
		{
		strcpy(entire_path, folder);
		strcat(entire_path, slash);
		strcat(entire_path, order);
		}
		if (stat(entire_path, &st) == 0)
		{
			free(path_dup);
			return (entire_path);
		}
		free(entire_path);
		folder = strtok(NULL, delimiter);
	}
	free(path_dup);
	return (NULL);
}
