#ifndef MONTY_H
#define MONTY_H

/* Includes */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
char **read_file(char *filename);
char **get_tokens(char *str, char **lines, stack_t *stack);
size_t get_command_size(char *str);
void free_tokens(char **tokens);
void free_dlist(stack_t *top);
void execute_op(stack_t **top, char **lines, char **cmd, unsigned int l_num);
void push(stack_t **stack, char **lines, unsigned int line_number, char *data);
void pall(stack_t **stack, unsigned int line_number);

#endif
