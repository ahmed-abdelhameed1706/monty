#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

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

/**
 * struct global_variables - contains the global variables
 * @global_arg: arg to be passed everywhere
 * @line: line to be freed
 * @tokens: to be freed
 * @lines: given file lines to free
 *
 * Description: global variables
 */
typedef struct global_variables
{
	char *global_arg;
	char *line;
	char **tokens;
	char **lines;
} gv_t;

/* Global Variables */
extern gv_t gv;

/* Prototypes */
int isdigit(int arg);
int isspace(int argument);
char **read_file(char *filename);
char **get_tokens(char *str);
size_t get_command_size(char *str);
void free_tokens(char **tokens);
void free_dlist(stack_t *top);
void execute_op(stack_t **top, char **lines, char **cmd, unsigned int l_num);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
char *strdup(const char *s);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *remove_spaces(char *input);
char *strtok(char *str, const char *delim);
int execute(char *cmd, int line_num, stack_t **stack);
void free_dlistint(stack_t *head);
void nop(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void add_node(stack_t **stack, int data);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
#endif
