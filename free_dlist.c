#include "monty.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to head
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp, *next;

	temp = head;

	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
