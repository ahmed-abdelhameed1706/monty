#include "monty.h"

gv_t gv;

/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
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
	gv.lines = lines;

	for (i = 0; lines[i]; i++)
	{
		line = remove_spaces(lines[i]);
		if (strcmp(line, "") != 0)
		{
			tokens = get_tokens(line);
			free(line);
			gv.tokens = tokens;
			execute(tokens[0], i + 1, &stack);
			free_tokens(tokens);
		}
		else
			free(line);
	}
	free(line);
	free(gv.global_arg);
	free_dlistint(stack);
	free_tokens(lines);
	return (0);
}
