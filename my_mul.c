#include "monty.h"

/**
 * mul_func - function that multiplies the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
*/

void mul_func(stack_t **head, unsigned int count)
{
	stack_t *p;
	int length = 0, temp;

	p = *head;
	while (p)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	temp = p->next->n * p->n;
	p->next->n = temp;
	*head = p->next;
	free(p);
}
