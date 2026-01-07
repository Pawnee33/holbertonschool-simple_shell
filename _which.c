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
* rebuild_path - build the entire path
* @order: command to search in PATH
* @folder: command name to append
* Return: entire path
*/
char *rebuild_path(char *folder, char *order)
{
	char *slash = "/";
	char *entire_path;

	entire_path = malloc(strlen(folder) + 1 + strlen(order) + 1);
	if (entire_path == NULL)
		return (NULL);

	else
	{
		strcpy(entire_path, folder);
		strcat(entire_path, slash);
		strcat(entire_path, order);
	}
	return (entire_path);
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
	char *delimiter = ":";

	path = search_path(env);
	if (path == NULL)
	{
		return (NULL);
	}
	path_dup = strdup(path);
	folder = strtok(path_dup, delimiter);
	while (folder != NULL)
	{
		entire_path = rebuild_path(folder, order);
		if (entire_path == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		if (access(entire_path, X_OK) == 0)
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
