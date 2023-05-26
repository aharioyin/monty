#include "monty.h"
/**
 *rotl_func- funciton to rotate the stack to top
 *@head: stack head
 *@count: line_number
 *Return: no return
 */
void rotl_func(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp = *head, *auxilliary;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	auxilliary = (*head)->next;
	auxilliary->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = auxilliary;
}
