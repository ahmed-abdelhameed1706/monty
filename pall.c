#include "monty.h"

/**
 * pall - prints values from stack to the screen
 * @stack: stack to be printed
 * @line_num: line number
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;

	(void)line_num;

	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
