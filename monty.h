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

typedef struct custom_file_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  custom_file_t;
extern custom_file_t custom_file;

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
void get_opcoodes(stack_t **stack, char *op, unsigned int line_number);

/** instruction 1 */
void _push(stack_t **head, unsigned int counter);
void _pall(stack_t **head, unsigned int counter);
void _pint(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);


char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void  _sub(stack_t **head, unsigned int counter);

/** functio that divide the second to element by the top one of the  stack */
void _add(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);

void div_function(stack_t **head, unsigned int counter);

void mul_function(stack_t **head, unsigned int counter);

/** function that compute the division*/
void mod_function(stack_t **head, unsigned int counter);

/** comments(do nothing) */
void pchar_function(stack_t **head, unsigned int counter);

/** function that prints the string starting at the top of the stack, followed by a new line */
void pstr_function(stack_t **head, unsigned int counter);

/** rotate stack to the top */
void rotl_function(stack_t **head, unsigned int counter);

/** rotate stack to the bottom */
void rotr_function(stack_t **head, __attribute__((unused)) unsigned int counter);

#endif
