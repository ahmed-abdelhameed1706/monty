#include "monty.h"

/**
 * main - entry point to the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char **lines = NULL, **tokens = NULL;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
        	exit(EXIT_FAILURE);
	}

	lines = read_file(argv[1]);

	for (i = 0; lines[i]; i++)
	{
		tokens = get_tokens(lines[i]);
		execute_op(tokens);
		free_tokens(tokens);
	}
	free_tokens(lines);
	return (0);
}
