#include "main.h"

/**
 * comp_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Negative value if str1 < str2, 0 if str1 == str2
 * else positive.
 */
int comp_strings(const char *str1, const char *str2)
{
	int idx = 0;

	while (str1[idx] == str2[idx])
		idx++;

	return (str1[idx] - str2[idx]);
}

/**
 * comp_n_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Negative value if st1 < str2, 0 if str1 == str2, else positive.
 */
int comp_n_strings(const char *str1, const char *str2)
{
	int idx;

	for (idx = 0; str1[idx] != '\0' || str2[idx] != '\0'; idx++)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
	}
	return (0);
}

/**
 * _strlen - Calculate length of a string.
 * @input_str: Input string.
 * Return: Length of the string.
 */
int _strlen(const char *input_str)
{
	int len = 0;

	while (input_str[len] != '\0')
		len++;

	return (len);
}

/**
 * _stringconcat - Concatenate two strings.
 * @str1: First string.
 * @str2: Second string to be appended to first string.
 * Return: Pointer to the concatenated string; else NULL.
 */
char *_stringconcat(char *str1, char *str2)
{
	char *merged_string;
	int i, j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";

	merged_string = malloc(_strlen(str1) + _strlen(str2) + 1);
	if (!merged_string)
		exit(0);

	for (i = 0; str1[i] != '\0'; i++)
		merged_string[i] = str1[i];
	for (j = 0; str2[j] != '\0'; j++)
		merged_string[i + j] = str2[j];
	merged_string[i + j] = '\0';

	return (merged_string);
}

/**
 * extract_substrings - extracts words from a string.
 * @substr_array: store extracted words.
 * @input_str: Point to the input string.
 * Return: array
 */
void extract_substrings(char **substr_array, char *input_str)
{
	int i, init_index, word_flag, len;

	len = i = init_index = word_flag = 0;

	while (input_str[i] != '\0')
	{
		if (input_str[i] == ' ' || input_str[i + 1] == '\0')
		{
			if (input_str[i] != ' ')
			{
				i++;
				word_flag = 1;
			}

			if (word_flag)
			{
				copy_segment(i - init_index, input_str + init_index, substr_array + len);
				if (!substr_array[len])
					exit(0);
				len += 1;
				init_index = i + 1;
				word_flag = 0;
			}

			if (input_str[i] == '\0')
				continue;
			i += 1;
			init_index += 1;
			continue;
		}
		else
		{
			if (!word_flag)
				init_index = i;
			word_flag = 1;
		}
		i += 1;
	}
	substr_array[len] = NULL;
}

/**
 * copy_segment - Copies a segment into a word array.
 * @seg_len: Length of segment.
 * @seg: Pointer to the segment.
 * @dest: Pointer to the destination in the array.
 */
void copy_segment(int seg_len, char *seg, char **dest)
{
	int x;

	*dest = malloc(sizeof(char) * (seg_len + 1));
	if (!(*dest))
	{
		perror("Error: memory allocation failed\n");
		free(dest);
		exit(0);
	}

	for (x = 0; x < seg_len; x++)
		(*dest)[x] = seg[x];
	(*dest)[x] = '\0';
}

