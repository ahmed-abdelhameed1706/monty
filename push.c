#include "monty.h"

/**
 * push - pushed int to the stack
 * @stack: stack to push ints in
 * @line_num: line number to handle errors
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_num)
{
	int i = 0, n;
	stack_t *new_node;

	if (gv.global_arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (gv.global_arg[0] == '-')
			i++;
		for (; gv.global_arg[i] != '\0'; i++)
		{
			if (!isdigit(gv.global_arg[i]))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				free_tokens(gv.tokens);
				free_tokens(gv.lines);
				free_dlistint(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	n = atoi(gv.global_arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
