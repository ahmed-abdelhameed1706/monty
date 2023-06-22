#include "monty.h"

/**
 * pop - removes element
 * @stack: stack to remove element from
 * @line_num: line number
 *
 * Return: nothing
 */
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
	if ((*stack))
		(*stack)->prev = NULL;
	free(temp);
}
