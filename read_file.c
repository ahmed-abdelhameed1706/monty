#include "monty.h"

/**
 * read_file - reads a file
 * @file: file to be read
 *
 * Return: array of strings
 */
char **read_file(FILE *file)
{
	char **lines = NULL, *line = NULL;
	size_t n = 0, i = 0, lines_count = 0;

	while(getline(&line, &n, file) != -1)
		lines_count++;

	fseek(file, 0, SEEK_SET);

	lines = malloc(sizeof(char *) * (lines_count + 1));

	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while(getline(&line, &n, file) != -1)
	{
		lines[i] = line;
		line = NULL;
		i++;
	}

	lines[i] = NULL;

	free(line);
	return (lines);
}
