#include "monty.h"

/**
 * swap - swaps 2 n from stack
 * @stack: stack to be added from
 * @line_num : line number
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int value;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = value;
}
