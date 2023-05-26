#include "monty.h"
/**
 * pop_func -function that  prints
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void pop_func(stack_t **head, unsigned int count)
{
	stack_t *stack_head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack_head = *head;
	*head = stack_head->next;
	free(stack_head);
}
