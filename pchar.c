#include "monty.h"


/**
 * pchar - print out top data char
 * @stack: stack
 * @line_num: line number
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
