#include "monty.h"

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
