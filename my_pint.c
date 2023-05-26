#include "monty.h"
/**
 * pint_func - function that prints the stack head
 * @head: stack head
 * @num: line_number
 * Return: no return
 */
void pint_func(stack_t **head, unsigned int num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
