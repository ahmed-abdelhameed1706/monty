#include "monty.h"

/**
 * mod - mod the remaining of the division of 2 n from stack
 * @stack: stack to be added from
 * @line_num : line number
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int mod;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*stack = temp->next;
	free(temp);
}
