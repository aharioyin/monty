#include "monty.h"
/**
 *sub_func- function to subtract
 *@head: stack head
 *@count: line_number
 *Return: no return
 */
void sub_func(stack_t **head, unsigned int count)
{
	stack_t *auxilliary;
	int subs, items;

	auxilliary = *head;
	for (items = 0; auxilliary != NULL; items++)
		auxilliary = auxilliary->next;
	if (items < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxilliary = *head;
	subs = auxilliary->next->n - auxilliary->n;
	auxilliary->next->n = subs;
	*head = auxilliary->next;
	free(auxilliary);
}
