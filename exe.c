#include "shell.h"


/**
 * exe - run the program using execve()
 * @data: a data_t structure that holds everything
 * command name, args, program name, env list
 *
 * Return: void
 */

void exe(data_t *data)
{
	if (data->run_cmd == NULL)
	{
		writestr(data->prog_name);
		writestr(": ");
		print_number(data->cmd_count);
		writestr(": ");
		writestr(data->cmd[0]);
		writestr(": ");
		writestr("not found\n");
		return;
	}
	pid_t id = fork();
	int exec_id;

	if (id == -1)
	{
		perror(data->prog_name);
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		exec_id = execve(data->run_cmd, data->cmd, data->env);
		if (exec_id == -1)
		{
			perror(data->prog_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

}
