#include "monty.h"

/**
 * get_command_size - get command size to allocate
 * @str: given command
 *
 * Return: command size
*/
size_t get_command_size(char *str)
{
	int i, is_str = 0;
	size_t size = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && !is_str)
		{
			is_str = 1;
			size++;
		}
		else if (str[i] == ' ' && is_str)
			is_str = 0;
	}

	if (size == 3)
		size--;

	return (size);
}

/**
 * get_tokens - get command tokens
 * @str: given command
 * @lines: given file lines to free
 * @stack: given stack to free
 *
 * Return: command tokens
*/
char **get_tokens(char *str, char **lines, stack_t *stack)
{
	char **command, *token;

	command = malloc(sizeof(char *) * 3);
	if (!command)
	{
		free_tokens(lines);
		free_dlist(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " \n\t");
	command[0] = strdup(token);
	token = strtok(NULL, " \n\t");
	if (!token)
		command[1] = strdup("nil");
	else
		command[1] = strdup(token);
	command[2] = NULL;

	return (command);
}
