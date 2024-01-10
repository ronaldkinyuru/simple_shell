#include "main.h"

/**
 * show_exit_error - error message and  terminate.
 * @arguments: argument vector.
 * @exit_code: exit status.
 */
void show_exit_error(char *arguments, int exit_code)
{
	(void)exit_code;
	perror(arguments);
	exit(0);
}

/**
 * manage_exit_cmd - Handle termination command.
 * @arguments:  command parameters.
 * @env_vars: Environment variables.
 * Return: 1 on success.
 */
int manage_exit_cmd(char **arguments, char **env_vars)
{
	int termination_status;
	(void)env_vars;

	termination_status = 0;
	if (arguments[1])
		termination_status = _atoi(arguments[1]);
	free_cmd_list(arguments);
	exit(termination_status);
}
