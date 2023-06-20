#include "monty.h"


void execute_op(char **command)
{
	instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(command[0], op_list[i].opcode) == 0)
			printf("execute: %s\n", op_list[i].opcode);
	}
}
