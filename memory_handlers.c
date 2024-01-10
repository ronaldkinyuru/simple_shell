#include "main.h"

/**
 * free_cmd_list - Release memory allocated for the command list.
 * @command_list: The command list to be freed.
 */
void free_cmd_list(char **command_list)
{
	int index = 0;

	if (!command_list)
		exit(0);

	while (command_list[index])
	{
		free(command_list[index]);
		index++;
	}
	free(command_list);
}

/**
 * release_strings - Release multiple string pointers.
 * @exit_code: If not 99, then exit after freeing.
 * @str_count: The number of string pointers.
 * ...: Variable number of string pointers.
 */
void release_strings(int exit_code, const unsigned int str_count, ...)
{
	unsigned int loop_idx;
	va_list string_args;
	char *str_pointer;

	va_start(string_args, str_count);

	for (loop_idx = 0; loop_idx < str_count; loop_idx++)
	{
		str_pointer = va_arg(string_args, char *);
		free(str_pointer);
	}

	va_end(string_args);

	if (exit_code == 99)
		return;
	exit(0);
}
