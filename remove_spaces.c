#include "monty.h"

/**
 * remove_spaces - removes all spaces while leaving only one
 * @input: str to remove spaces from
 *
 * Return: a string with only 1 space
 */
char *remove_spaces(char *input)
{
	int input_len, i, j = 0, space_count = 0, lead_space = 0, back_space = 0;
	int output_len;
	char *output;

	input_len = strlen(input);
	while (isspace(input[lead_space]))
		lead_space++;
	i = input_len - 1;
	while (i > 0 && isspace(input[i]))
	{
		back_space++;
		i--;
	}
	output_len = input_len - lead_space - back_space;
	output = malloc(sizeof(char) * (output_len + 1));
	if (output == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = lead_space; i < input_len - back_space; i++)
	{
		if (isspace(input[i]))
		{
			if (space_count == 0)
			{
				output[j] = ' ';
				j++;
			}
			space_count++;
		}
		else
		{
			output[j] = input[i];
			j++;
			space_count = 0;
		}
	}
	output[j] = '\0';
	return (output);
}
