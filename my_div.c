#include "monty.h"

/**
 * div_func - function that performs division of the
 *          top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
*/

void div_func(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	sum = p->next->n / p->n;
	p->next->n = sum;
	*head = p->next;
	free(p);
}
