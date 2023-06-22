#include "monty.h"

/**
 * mul - muls 2 n from stack
 * @stack: stack to be added from
 * @line_num : line number
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int mul;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	mul = temp->n * temp->next->n;
	temp->next->n = mul;
	*stack = temp->next;
	free(temp);
}
