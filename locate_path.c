#include "main.h"

/**
 * locate_cmd_path -  if  command is in the path directory.
 * @command: Command to be inspected.
 * @env_vars: Environment variables.
 */
void locate_cmd_path(char **command, char **env_vars)
{
	char *cmd_prefix, *command_path, *path_env;
	int index, seg_start, is_final_segment;

	cmd_prefix = _stringconcat("/", command[0]);
	path_env = get_env_value("PATH", env_vars);
	if (!path_env)
	{
		free(cmd_prefix);
		exit(0);
	}

	seg_start = index = is_final_segment = 0;
	while (path_env[index])
	{
		if (path_env[index] == ':' || !path_env[index + 1])
		{
			is_final_segment = !path_env[index + 1];
			if (is_final_segment)
				index++;

			command_path = _stringconcat(path_env + seg_start, cmd_prefix);

			if (access(command_path, F_OK) == 0)
			{
				free(command[0]);
				command[0] = command_path;
				free(cmd_prefix);
				return;
			}

			free(command_path);
			if (is_final_segment)
				break;

			seg_start = index + 1;
		}
		index++;
	}
	free(cmd_prefix);
}
