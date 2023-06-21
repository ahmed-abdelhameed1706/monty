#include "monty.h"

/**
 * execute_op - execute a given command
 * @top: given stack/queue
 * @command: given command
 * @line_number: given command line number
 *
 * Return: Nothing
*/
void execute_op(stack_t **top, char **lines, char **command, unsigned int l_num)
{
	instruction_t op_list[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	if (strcmp(command[0], "push") == 0)
	{
		push(&(*top), lines, l_num, command[1]);
		return;
	}

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(command[0], op_list[i].opcode) == 0)
		{
			op_list[i].f(&(*top), l_num);
			return;
		}
	}
	free_dlist(*top);
	free_tokens(lines);
		fprintf(stderr, "L%d: unknown instruction %s", l_num, command[0]);
	free_tokens(command);
		exit(EXIT_FAILURE);
}
