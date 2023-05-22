#include "shell.h"
/**
 * args - take arg from user
 * @data: data_t struct holds commands
 * @av: passed argument
 * @ac: av counter
 *
 *
 */

void args(data_t *data, int ac, char **av)
{
	int acc = ac, i;
	data->cmd = malloc (sizeof(char *) * (ac));

	if (data->cmd == NULL)
	{
		perror(data->prog_name);
		exit(errno);
	}
	for (i = 1; i < acc; i++)
	{
		data->cmd[i - 1] = full_strdup(av[i]);

	}
	data->cmd[i - 1] = NULL;
}
