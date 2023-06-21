#include "monty.h"

/**
 * execute_op - execute a given command
 * @top: given stack/queue
 * @cmd: given command
 * @l_num: given command line number
 * @lines: the lines to be freed
 *
 * Return: Nothing
*/
void execute_op(stack_t **top, char **lines, char **cmd, unsigned int l_num)
{
	instruction_t op_list[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	if (strcmp(cmd[0], "push") == 0)
	{
		push(&(*top), lines, l_num, cmd[1]);
		return;
	}

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(cmd[0], op_list[i].opcode) == 0)
		{
			op_list[i].f(&(*top), l_num);
			return;
		}
	}
	free_dlist(*top);
	free_tokens(lines);
	fprintf(stderr, "L%d: unknown instruction %s", l_num, cmd[0]);
	free_tokens(cmd);
	exit(EXIT_FAILURE);
}
