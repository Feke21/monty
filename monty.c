#include "monty.h"

glob_t glob;

/**
 * stack_init - initialize all the things
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}

/**
 * main - monty bytecode interpreter
 * @argc: number of command line arguments
 * @argv: array of strings containing the comm line args
 * Return: EXIT_SUCCESS or EXIT_FAILURE!!!
 **/
int main(int argc, char **argv)
{
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}

