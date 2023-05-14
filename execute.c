#include "shell.h"

/**
 * filter_cmd - we have data->get_cmd as a full command now
 * we will seperate the spaces and put it as a list in data->cmd
 * 
 * @data: data_t struct that holds the commands
 */
void filter_cmd(data_t *data)
{
	/* char *my_av[] = {NULL}; */
	int  i, j, tokens_count = 0;
	char *token;
	char *get_cmd_cpy;
	const char *delim = " ";


	get_cmd_cpy = _strdup(data->get_cmd);


	token = strtok(get_cmd_cpy, delim);
	while (token)
	{
		tokens_count++;
		token = strtok(NULL, delim);
	}
	tokens_count++;

	free(get_cmd_cpy);
	get_cmd_cpy = _strdup(data->get_cmd);

	data->cmd = malloc(sizeof(char *) * tokens_count);

	token = strtok(get_cmd_cpy, delim);

	i = 0;
	while (token)
	{
		data->cmd[i] = malloc(sizeof(char) * _strlen(token));

		_strcpy(data->cmd[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	data->cmd[i] = NULL;
	
	free(get_cmd_cpy);
}


/**
 * get_location - after filtering the inputed string,
 * an example of data->cmd : {"ls", "-l", "/tmp", NULL}
 * now we want the first command "ls" to be included with 
 * the command path, like "usr/bin/ls"
 *
 * @cmd: the commaned which will be taken from data->cmd
 *
 * Return: full command with path or null if DNE
 */
char *get_location(char *cmd)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len;
	int dir_len;
	struct stat sfile;

	path = getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path);

		cmd_len = _strlen(cmd);

		path_token = strtok(path_copy, ":");
		while(path_token)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(cmd_len + dir_len + 2);
			
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");

			if (stat(file_path, &sfile) == 0)
			{
				free(path_copy);
				return (file_path);
			}

			free(file_path);
			path_token = strtok(NULL, ":");
		}

		free(path_copy);

		if (stat(cmd, &sfile) == 0)
			return (cmd);
		
		return (NULL);
	}
	
	return (NULL);
}









