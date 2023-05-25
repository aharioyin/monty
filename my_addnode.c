#include "monty.h"

/**
 * node_add - function that adds node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void node_add(stack_t **head, int n)
{

	stack_t *new, *sum;

	sum = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{ printf("Error\n");
		exit(0); }
	if (sum)
		sum->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
