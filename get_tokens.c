#include "monty.h"

/**
 * get_tokens - tokenize a string
 * @str: string to be tokenized
 *
 * Return: an array of strings
 */
char **get_tokens(char *str)
{
	char **tokens = NULL, *token = NULL;
	const char *delim = " \n";
	int i;

	tokens = malloc(sizeof(char *) * 3);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delim);
	for (i = 0; token; i++)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	global_arg = tokens[1];
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_tokens - frees tokens
 * @tokens: tokens to be freed
 *
 * Return: nothing
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}
