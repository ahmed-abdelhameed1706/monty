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
	int i;
	char **command, *temp, *token;
	size_t size = 0;

	size = get_command_size(str);

	command = malloc(sizeof(char *) * (size + 1));
	if (!command)
	{
		free_tokens(lines);
		free_dlist(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; str[i] == ' '; i++)
	;
	temp = strdup(&(str[i]));
	token = strtok(temp, " \n");
	command[0] = strdup(token);
	if (strcmp(token, "push") != 0)
	{
		free(temp);
		command[1] = NULL;
		return (command);
	}

	for (; str[i] != ' '; i++)
	{
		if (!str[i])
		{
			command[1] = strdup("nil");
			return (command);
		}
	}
	free(temp);
	str = &(str[i + 1]);
	token = strtok(str, " \n");
	command[1] = strdup(token);
	command[2] = NULL;
	return (command);
}
