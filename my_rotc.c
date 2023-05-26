#include "monty.h"
/**
 *rotr_func- function to rotate stack to bottom
 *@head: stack head
 *@count: line_number
 *Return: no return
 */
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
