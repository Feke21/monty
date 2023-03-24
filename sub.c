#include "monty.h"

/**
 * _sub - subtraction
 * @head: pointer to stack
 * @counter: line number
 *
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack is too limited\n", counter);
		fclose(custom_file.file);
		free(custom_file.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
