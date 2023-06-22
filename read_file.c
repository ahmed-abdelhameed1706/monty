#include "monty.h"

/**
 * read_file - reads a file
 * @filename: file name to read from
 *
 * Return: array of strings
 */
char **read_file(char *filename)
{
	FILE *file;
	char **lines = NULL, *line = NULL;
	size_t n = 0, i = 0, lines_count = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, file) != -1)
		lines_count++;

	fseek(file, 0, SEEK_SET);
	lines = malloc(sizeof(char *) * (lines_count + 1));

	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, file) != -1)
	{
		lines[i] = malloc(sizeof(char) * (strlen(line) + 1));
		if (lines[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(file);
			exit(EXIT_FAILURE);
		}
		strcpy(lines[i], line);
		i++;
	}
	lines[i] = NULL;
	fclose(file);
	free(line);
	return (lines);
}
