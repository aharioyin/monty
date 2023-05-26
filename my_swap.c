#include "monty.h"

/**
 * swap_func - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void swap_func(stack_t **head, unsigned int count)
{
	stack_t *p;
	int lenght = 0, auxilliary;

	p = *head;
	while (p)
	{
		p = p->next;
		lenght++;
	}
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	auxilliary = p->n;
	p->n = p->next->n;
	p->next->n = auxilliary;
}
