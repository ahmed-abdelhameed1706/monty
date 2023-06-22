#include "monty.h"


/**
 * str_isdigit - checks if the given string is integer
 * @str: given string
 *
 * Return: 1 if integer else 0
*/
int str_isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
