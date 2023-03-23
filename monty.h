#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define DELIMS "\n \t\r"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
**/
typedef struct glob_s
{
	stack_t **top;
	instruction_t **ops;
} glob_t;

extern glob_t glob;

/* get_opcodes.c */
void get_opcodes(stack_t **stack, char *op, unsigned int line_number);


/** get opcodes function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/** instruction 1 */
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

/** swap code function */
void swap_function(stack_t **head, unsigned int counter);

/** add top two element function */
void add_function(stack_t **head, unsigned int counter);

/** function that do nothing */
void nop_function(stack_t **head, unsigned int counter);

/** substraction function */
void  sub_function(stack_t **head, unsigned int counter);

/** functio that divide the second to element by the top one of the  stack */
void div_function(stack_t **head, unsigned int counter);

/** function that multiplies the second top element of the stack with the top element of the stack */
void mul_function(stack_t **head, unsigned int counter);

/** function that compute the division*/
void mod_function(stack_t **head, unsigned int counter);

#endif
