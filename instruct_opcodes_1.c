#include "monty.h"

/**
 * _push -  pushes a node to the top of a stack
 * @stack: pointer to the head of stack
 * @line_number: number for new node
 *
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *op;
	int num;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(op, line_number);
	new->n = num;
	new->next = *stack;
	new->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: value of node
 *
 * Return: Nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - prints value at top of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 *
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	new  = *stack;
	(*stack) = (*stack)->next;
	free(new);
}
