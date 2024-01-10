#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

/*execute_builtin_cmd*/
int execute_builtin_cmd(char **arguments, char **env_vars);
/*environ */
int show_environment(char **arguments, char **env_vars);
/*exit_cmd*/
void show_exit_error(char *arguments, int exit_code);
int manage_exit_cmd(char **arguments, char **env_vars);
/*environ1*/
char *get_env_value(const char *var_name, char **env_vars);
/*locate_path*/
void locate_cmd_path(char **command, char **env_vars);
/*memory_handlers*/
void free_cmd_list(char **command_list);
void release_strings(int exit_code, const unsigned int str_count, ...);
/*show_cmd*/
int show_command_prompt(char **input);
/*showsignal*/
void show_signal(int signal_val);
/*main*/
int main(int args_count, char *args_values[], char **env_vars);
/*strings*/
int word_count(char *input_str);
char **string_tok(char *input_string);
void get_word(int dest_len, char *src, char **dest);
int _atoi(char *input_str);
int comp_strings(const char *str1, const char *str2);
int comp_n_strings(const char *str1, const char *str2);
int _strlen(const char *input_str);
char *_stringconcat(char *str1, char *str2);
void extract_substrings(char **substring_array, char *input_string);
void copy_segment(int seg_len, char *seg, char **dest);

/**
 * struct builtin_comand - contains builtin command and functions for shell
 * @cmd_name: name of command
 * @ptr: pointer to builtin functions
 * Description: struct for builtin functions
*/
typedef struct builtin_comand
{
	char *cmd_name;
	int (*ptr)(char **arguments, char **env_vars);

} list_t;
#endif /*MAIN_H*/