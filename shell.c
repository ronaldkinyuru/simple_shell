#include "main.h"
int main(int ac, char *av[], char **env)
{
	char *input = NULL;
	char **cmd = NULL;
	int process_stat;
	pid_t child_process;
	(void)ac;

	while (1)
	{
		input = NULL;
		signal(SIGINT, show_signal);
		if (show_command_prompt(&input) == -1)
			continue;
		cmd = string_tok(input);
		if (!cmd)
		{
			release_strings(99, 1, input);
			continue;
		}
		release_strings(99, 1, input);
		if (execute_builtin_cmd(cmd, env))
			continue;
		child_process = fork();
		if (child_process == 0)
		{
			locate_cmd_path(cmd, env);
			if (execve(cmd[0], cmd, NULL) == -1)
			{
				perror(*av);
				free_cmd_list(cmd);
				exit(0);
			}
		}
		else
		{
			free_cmd_list(cmd);
			if (!wait(&process_stat))
				break;
		}
	}
	return (0);
}
