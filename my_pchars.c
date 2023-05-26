#include "monty.h"

/**
 * pchar_func -functions that prints the char at the top of the stack,
 *           followed by a new line
 * @head: stack head
 * @count: line_number
 * Return: no return
*/

void pchar_func(stack_t **head, unsigned int count)
{
	stack_t *p;

	p = *head;
	if (!p)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}
