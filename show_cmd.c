#include "main.h"

/**
 * show_command_prompt - Presents command interface to user
 * @input: Captures the user's command.
 * Return: 1 on success, -1 otherwise.
 */

int show_command_prompt(char **input)
{
	size_t buf_size = 0;
	int getline_status;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	getline_status = getline(input, &buf_size, stdin);

	if (getline_status == EOF)
		release_strings(-1, 1, *input);

	(*input)[getline_status - 1] = '\0';

	if (*(*input) == '\0' || (*(*input) == '.' && (*input)[1] == '\0'))
	{
		release_strings(99, 1, *input);
		return (-1);
	}
	else
		return (1);
}
