#include "monty.h"

/**
* free_mem_stack - function that frees memory allocated
*               to a doubly linked list
* @head: head of the stack
*/

void free_mem_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
