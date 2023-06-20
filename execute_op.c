#include "monty.h"

/**
 * execute_op - execute a given command
 * @top: given stack/queue
 * @command: given command
 * @line_number: given command line number
 *
 * Return: Nothing
*/
void execute_op(stack_t **top, char **command, unsigned int line_number)
{
	instruction_t op_list[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	if (strcmp(command[0], "push") == 0)
		push(&(*top), line_number, command[1]);

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(command[0], op_list[i].opcode) == 0)
			op_list[i].f(&(*top), line_number);
	}
}
