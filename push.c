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
	int i, n;
	stack_t *new_node;

	if (gv.global_arg == NULL)
	{
		printf("L%u: usage: push integer\n", line_num);
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; gv.global_arg[i] != '\0'; i++)
	{
		if (!isdigit(gv.global_arg[i]))
		{
			printf("L%u: usage: push integer\n", line_num);
			free_tokens(gv.tokens);
			free_tokens(gv.lines);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(gv.global_arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
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
