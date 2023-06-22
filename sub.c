#include "monty.h"

/**
 * sub - subs 2 n from stack
 * @stack: stack to be added from
 * @line_num : line number
 * 
 * Return: Nothing 
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int sub;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		free_dlistint(*stack);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		exit(EXIT_FAILURE);
	}

	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*stack = temp->next;
	free(temp);
}
