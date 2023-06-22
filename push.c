#include "monty.h"


/**
 * add_node - add node to the top of the stack
 * @stack: top of the stack
 * @data: new node data
 *
 * Return: Nothing
*/
void add_node(stack_t **stack, int data)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_tokens(gv.tokens);
		free_tokens(gv.lines);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = new_node;
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

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
	add_node(stack, n);
}
