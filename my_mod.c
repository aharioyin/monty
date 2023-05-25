#include "monty.h"

/**
 * mod_func - function that computes the the remainder of 
 *              the division of the second top element 
 *              of the stack by the top element of the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/

void mod_func(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
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
	temp = p->next->n % p->n;
	p->next->n = temp;
	*head = p->next;
	free(p);
}
