#include "monty.h"


/**
 * pall - print out Stack/Queue data
 * @stack: given stack/queue
 * @line_number: given command line number
 *
 * Return: Nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
