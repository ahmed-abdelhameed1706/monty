#include "monty.h"


/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */

char *global_arg;

int main(int argc, char **argv)
{
	char **lines = NULL, *line = NULL, **tokens = NULL;
	int i;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	lines = read_file(argv[1]);

	for (i = 0; lines[i]; i++)
	{
		line = remove_spaces(lines[i]);
		free(lines[i]);
		if (strcmp(line, "") != 0)
		{
			tokens = get_tokens(line);
			execute(tokens[0], i + 1, &stack);
			free_tokens(tokens);
		}
		free(line);	
	}
	free(line);
	free(global_arg);
	free_tokens(lines);
	return (0);
}
