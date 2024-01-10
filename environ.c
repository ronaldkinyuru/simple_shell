#include "main.h"

/**
 * show_environment - environment variables.
 * @arguments: parameters.
 * @env_vars: environment variables.
 * Return: 1 on success.
 */
int show_environment(char **arguments, char **env_vars)
{
	int length_of_string, index = 0;

	while (env_vars[index])
	{
		length_of_string = _strlen(env_vars[index]);
		write(STDOUT_FILENO, env_vars[index], length_of_string);
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	free_cmd_list(arguments);
	return (1);
}
