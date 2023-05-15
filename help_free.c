#include "shell.h"

void free_used_data(data_t *data)
{
	if (data->get_cmd)
		free(data->get_cmd);
	if (data->cmd)
		free_grid_char(data->cmd);
	if (data->run_cmd)
		free(data->run_cmd);
	
	data->run_cmd = NULL;
	data->cmd = NULL;
	data->get_cmd = NULL;
}

/**
 * free_data - free all arrays in data_t struct
 * @data: data_t struct holds commands
 *
 */
void free_data(data_t *data)
{
	free_used_data(data);
	free_grid_char(data->env);

	writechar(BUF_FLUSH);
}

/**
 * free_grid_char - frees a 2d arrays of char
 * @arr: the 2d array
 *
 */

void free_grid_char(char **arr)
{
	int i;

	if (arr != NULL)
	{
		for (i = 0; arr[i]; i++)
			free(arr[i]);

		free(arr);
		arr = NULL;
	}
}
