#include "monty.h"
/**
 * div_function- divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void div_function(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack size is way smaller\n", counter);
		fclose(custom_file.file);
		free(custom_file.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(custom_file.file);
		free(custom_file.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
