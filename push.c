#include "monty.h"


/**
 * push - add node to the Stack/Queue
 * @stack: given stack/queue
 * @lines: given file lines to free
 * @line_number: given command line number
 * @data: given node data
 *
 * Return: Nothing
*/
void push(stack_t **stack, char **lines, unsigned int line_number, char *data)
{
	stack_t *new_stack;
	int data_num;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		free_tokens(lines);
		free_dlist(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	data_num = atoi(data);
	if (strcmp(data, "nil") == 0 || data_num == 0)
	{
		free_tokens(lines);
		free_dlist(*stack);
		fprintf(stderr, "%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack->n = data_num;
	new_stack->prev = NULL;

	if (!stack)
		new_stack->next = NULL;

	else
		new_stack->next = *stack;

	*stack = new_stack;
}
