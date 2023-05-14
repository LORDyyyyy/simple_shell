#include "shell.h"

/**
 * main - entry point, makes the infinite loop
 * and rediredt to the execve functioni
 * @av: passed argument list
 * @ac: av count
 * @env: the enviroment list
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	data_t data_struct = {NULL}, *data = &data_struct;

	init_data(data, ac, av, env);

	shell_loop(data, ac, av, env);

	/*
	 *
	 * writestr(data->get_cmd);
	 * writechar(10);
	 *
	 *
	 */

	writechar(BUF_FLUSH);
	return (0);
}

/**
 * init_data - initialization the data
 * @data: data_t struct holds commands
 * @av: passed argument
 * @ac: av counter
 *
 */
void init_data(data_t *data, int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int i;

	data->get_cmd = NULL;
	data->cmd = NULL;
	/*
	if (env)
		for ( i = 0; env[i]; i++)
			_strcpy(data->env[i], env[i]);
	data->env[i] = NULL;*/
}

/**
 * clear_getline - if the last char is '\n', remove it
 * @str: the string from getline
 *
 * Return: str after clearing it
 */
char *clear_getline(char *str)
{
	size_t last = strlen(str) - 1;

	str[last] = str[last] == 10 ? '\0' : str[last];
	return (str);
}

/**
 * shell_loop - the shell's infinte loop
 * @data: data_t struct holds commands
 * @av: passed argument
 * @ac: av counter
 * @env: enviroment list
 *
 */
void shell_loop(data_t *data, int ac, char **av, char **env)
{
	int error_code = 0, i;
	size_t BUF = 1024;
	char *command;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			writestr("$ ");
		writechar(BUF_FLUSH);

		error_code = getline(&data->get_cmd, &BUF, stdin);

		if (error_code == -1)
		{
			free(data->cmd);
			free(data->get_cmd);
			exit(EXIT_FAILURE);
		}

		data->get_cmd = clear_getline(data->get_cmd);

		//writestr(data->get_cmd);
		//writechar(10);
		//writechar(BUF_FLUSH);
		
		if (!(_strcmp(data->get_cmd, "exit")))
			exit(error_code);

		filter_cmd(data);
		
		
		command = get_location(data->cmd[0]);

		if(!command)
			break;
		
		free(data->cmd[0]);
		data->cmd[0] = malloc(sizeof(char) * _strlen(command));

		data->cmd[0] = _strdup(command);

		
		i = 0;
		while (data->cmd[i])
		{
			writestr(data->cmd[i]);
			writechar(' ');
			writechar(BUF_FLUSH);
			free(data->cmd[i]);
			i++;
		}
		writechar(10);

		//free(command);
	}
	free_data(data);
}
