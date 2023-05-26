#include "monty.h"
/**
 * queue_func - function to print
 * @head: stack head
 * @count: line_number
 * Return: no return
 */
void queue_func(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	context.flag = 1;
}

/**
 * queue_add - function to add node to tail
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void queue_add(stack_t **head, int n)
{
	stack_t *add_node, *auxilliary;

	auxilliary = *head;
	add_node = malloc(sizeof(stack_t));
	if (add_node == NULL)
	{
		printf("Error\n");
	}
	add_node->n = n;
	add_node->next = NULL;
	if (auxilliary)
	{
		while (auxilliary->next)
			auxilliary = auxilliary->next;
	}
	if (!auxilliary)
	{
		*head = add_node;
		add_node->prev = NULL;
	}
	else
	{
		auxilliary->next = add_node;
		add_node->prev = auxilliary;
	}
}
