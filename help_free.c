#include "shell.h"

/**
 * free_data - free all arrays in data_t struct
 * @data: data_t struct holds commands
 *
 */
void free_data(data_t *data)
{
	int i;

	free(data->get_cmd);

	i = 0;
	while (data->cmd[i])
	{
		free(data->cmd[i]);
		i++;
	}
	
	free(data->cmd);
}
