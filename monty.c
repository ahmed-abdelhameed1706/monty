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
	FILE *file;
	char **lines = NULL;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
        	exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        	exit(EXIT_FAILURE);
	}

	lines = read_file(file);

	while (lines[i] != NULL)
	{
		printf("%s\n", lines[i]);
		i++;
	}

	return (0);
}
