#include "monty.h"


/**
 * push - add node to the Stack/Queue
 * @stack: given stack/queue
 * @lines: given file lines to free
 * @line_num: given command line number
 * @data: given node data
 *
 * Return: Nothing
*/
void push(stack_t **stack, char **lines, unsigned int line_num, char **data)
{
	stack_t *new_stack;
	int data_num;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		free_tokens(lines);
		free_dlist(*stack);
		free_tokens(data);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!str_isdigit(data[1]))
	{
		free_tokens(lines);
		free_dlist(*stack);
		free_tokens(data);
		free(new_stack);
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	data_num = atoi(data[1]);
	new_stack->n = data_num;
	new_stack->prev = NULL;

	if (!stack || !(*stack))
		new_stack->next = NULL;

	else
	{
		new_stack->next = *stack;
		(*stack)->prev = new_stack;
	}
	*stack = new_stack;
}
