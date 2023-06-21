#include "monty.h"


/**
 * free_dlist - free out stack/queue
 * @top: the top of the stack
 *
 * Return: Nothing.
*/
void free_dlist(stack_t *top)
{
	stack_t *temp;

	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
