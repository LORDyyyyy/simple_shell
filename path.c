#include "shell.h"

/**
 * filter_cmd - we have data->get_cmd as a full command now
 * we will seperate the spaces and put it as a list in data->cmd
 *
 * @data: data_t struct that holds the commands
 */
void filter_cmd(data_t *data)
{
	char *delimiter = " \t";
	int i, j, counter = 2;


	for (i = 0; data->get_cmd[i]; i++)
		for (j = 0; delimiter[j]; j++)
			if (data->get_cmd[i] == delimiter[j])
				counter++;

	data->cmd = malloc(counter * sizeof(char *));
	if (data->cmd == NULL)
	{
		perror(data->prog_name);
		exit(errno);
	}

	i = 0;

	data->cmd[i] = full_strdup(strtok(data->get_cmd, delimiter));

	while (data->cmd[i++])
		data->cmd[i] = full_strdup(strtok(NULL, delimiter));
}

/**
 * get_location - after filtering the inputed string,
 * an example of data->cmd : {"ls", "-l", "/tmp", NULL}
 * now we want the first command "ls" to be included with
 * the command path, like "usr/bin/ls"
 *
 * @data: data_t struct holds the commands
 *
 * Return: full command with path or null if DNE
 */
char *get_location(data_t *data)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat sfile;

	path = _getenv("PATH", data);
	if (path)
	{
		path_copy = full_strdup(path);
		cmd_len = _strlen(data->cmd[0]);
		path_token = strtok(path_copy, ":");
		while (path_token)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(cmd_len + dir_len + 2);
			if (file_path == NULL)
			{
				perror(data->prog_name);
				exit(errno);
			}
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, data->cmd[0]);
			_strcat(file_path, "\0");
			if (stat(file_path, &sfile) == 0)
			{
				free(path_copy);
				data->run_cmd = full_strdup(file_path);
				free(file_path);
				return (data->cmd[0]);
			}
			free(file_path);
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
		if (stat(data->cmd[0], &sfile) == 0)
			return (data->run_cmd = full_strdup(data->cmd[0]));
	}
	return (NULL);
}


/**
 * _getenv - getting the path envirment variable from
 * data->env list
 * @key: var name "PATH"
 * @data: data_t struct that holds everything
 *
 * Return: the path var value
 *
 */

char *_getenv(char *key, data_t *data)
{
	int i, key_len = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_len = _strlen(key);
	for (i = 0; data->env[i]; i++)
		if (_strncmp(key, data->env[i], key_len) &&
		 data->env[i][key_len] == '=')
			return (data->env[i] + key_len + 1);
	return (NULL);
}
