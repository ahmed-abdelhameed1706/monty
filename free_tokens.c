#include "monty.h"

/**
 * free_tokens - frees the space of the tokens we already used
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
	tokens = NULL;
}

