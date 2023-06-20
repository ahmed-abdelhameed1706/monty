#include "monty.h"


void execute_op(char **command, unsigned int line_number)
{
	stack_t *top = NULL;
	instruction_t op_list[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	if (strcmp(command[0], "push") == 0)
		push(&top, line_number, command[1]);

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(command[0], op_list[i].opcode) == 0)
			op_list[i].f(&top, line_number);
	}
}
