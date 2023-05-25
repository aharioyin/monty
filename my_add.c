#include "monty.h"

/**
 * add_func - function that adds the top two elements of the stack.
 * @head: head of the stack
 * @count: line_number
 * Return: no return
*/

void add_func(stack_t **head, unsigned int count)
{
	stack_t *p;
	int length = 0, sum;

	p = *head;
	while (p)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	sum = p->n + p->next->n;
	p->next->n = sum;
	*head = p->next;
	free(p);
}
