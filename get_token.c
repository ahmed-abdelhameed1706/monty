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

	return (size);
}

/**
 * get_tokens - get command tokens
 * @str: given command
 *
 * Return: command tokens
*/
char **get_tokens(char *str)
{
	int is_str = 0, i;
	char **command, *temp = strdup(str), *token;
	size_t size = 0;

	size = get_command_size(str);

	command = malloc(sizeof(char *) * (size + 1));
	if (!command)
		return (NULL);
	for (i = 0; str[i] != ' '; i++)
	{
		if (!str[i])
		{
			token = strtok(temp, "\n");
			command[0] = strdup(token);
			command[1] = NULL;
			return (command);
		}
	}
	token = strtok(temp, " ");
	command[0] = strdup(token);
	for (; str[i] != ' '; i++)
	{
		if (!str[i])
		{
			command[1] = NULL;
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
