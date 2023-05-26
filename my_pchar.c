#include "monty.h"
/**
 * pchar_func - a function that prints the characters
 * at the top of the stack,
 * @head: beginning of stack
 * @count: line_number
 * Return: no return
 */
void pchar_func(stack_t **head, unsigned int count)
{
	stack_t *stack_start;

	stack_start = *head;
	if (!stack_start)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (stack_start->n > 127 || stack_start->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", stack_start->n);
}
