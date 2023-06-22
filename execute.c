#include "monty.h"

/**
 * execute - executes a command from a command list
 * @cmd: command to be executed
 * @line_num: line number
 * @stack: stack to be passed down
 *
 * Return: 0 on success -1 on failure
 */
int execute(char *cmd, int line_num, stack_t **stack)
{
	int i;

	instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{NULL, NULL}
	};

	for (i = 0; op_list[i].opcode; i++)
	{
		if (strcmp(cmd, op_list[i].opcode) == 0)
		{
			op_list[i].f(stack, line_num);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd);
	free_tokens(gv.tokens);
	free_dlistint(*stack);
	free_tokens(gv.lines);
	exit(EXIT_FAILURE);
}
