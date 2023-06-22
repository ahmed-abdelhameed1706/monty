#include "monty.h"

/**
 * add - adds 2 n from stack
 * @stack: stack to be added from
 * @line_num : line number
 * 
 * Return: Nothing 
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sum;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}
