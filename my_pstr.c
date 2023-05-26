#include "monty.h"
/**
 * pstr_func - function that prints the string
 * starting at the stack head
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void pstr_func(stack_t **head, unsigned int count)
{
	stack_t *stack_head;
	(void)count;

	stack_head = *head;
	while (stack_head)
	{
		if (stack_head->n > 127 || stack_head->n <= 0)
		{
			break;
		}
		printf("%c", stack_head->n);
		stack_head = stack_head->next;
	}
	printf("\n");
}
