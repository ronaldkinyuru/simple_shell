#include "main.h"

/**
 * word_count - Function that counts the number of words in a string.
 * @input_str: Pointer to the string.
 * Return: Number of words in the string or -1 if there are no words.
 */
int word_count(char *input_str)
{
	unsigned int length, counter;
	int words_count;

	if (input_str == NULL || *input_str == '\0')
		return (-1);

	words_count = counter = length = 0;

	if (input_str[1] == '\0' && *input_str == ' ')
		return (-1);
	while (input_str[counter] != '\0')
	{
		if (input_str[counter] == ' ' || input_str[counter + 1] == '\0')
		{
			if (input_str[counter] != ' ')
				words_count = 1;
			if (words_count)
			{
				length += 1;
				words_count = 0;
			}
			counter += 1;
			continue;
		}
		else
			words_count = 1;
		counter += 1;
	}

	return (length);
}

/**
 * string_tok - Tokenize a string into words.
 * @input_string: The input string.
 * Return: An array of tokens.
 */
char **string_tok(char *input_string)
{
	char **array_tokens;
	int tokens_count;

	tokens_count = word_count(input_string);
	if (tokens_count <= 0)
		return (NULL);

	array_tokens = malloc(sizeof(char *) * (tokens_count + 1));
	if (!array_tokens)
		return (NULL);
	extract_substrings(array_tokens, input_string);

	return (array_tokens);
}

/**
 * get_word - Copies a word from a string.
 * @dest_len: The length of the destination string.
 * @src: The source string to extract the word from.
 * @dest: The destination to store the copied word.
 */
void get_word(int dest_len, char *src, char **dest)
{
	int loop_idx;

	*dest = malloc(sizeof(char) * (dest_len + 1));
	if (!(*dest))
	{
		perror("Error: malloc failed");
		free(dest);
		exit(0);
	}

	for (loop_idx = 0; loop_idx < dest_len; loop_idx++)
		(*dest)[loop_idx] = src[loop_idx];
	(*dest)[loop_idx] = '\0';
}

/**
 * _atoi - Convert a string to an integer.
 * @input_str: The string to be converted.
 * Return: Converted integer value.
 */
int _atoi(char *input_str)
{
	int loop_idx, multiplier;
	unsigned int int_result;

	int_result = loop_idx = 0;
	multiplier = 1;

	while ((input_str[loop_idx] < '0' || input_str[loop_idx] > '9')
	&& input_str[loop_idx] != '\0')
	{
		if (input_str[loop_idx] == '-')
			multiplier *= -1;
		loop_idx++;
	}
	for (; input_str[loop_idx] != '\0' && input_str[loop_idx] >= '0'
	&& input_str[loop_idx] <= '9'; loop_idx++)
	{
		int_result = int_result * 10 + (input_str[loop_idx] - '0');
	}
	int_result *= multiplier;

	return (int_result);
}
