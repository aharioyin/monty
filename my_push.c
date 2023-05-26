#include "monty.h"
/**
 * push_func - function to add a node to stack
 * @head: stack head
 * @num: line_number
 * Return: no return
 */
void push_func(stack_t **head, unsigned int num)
{
	int n, index = 0, ident = 0;

	if (context.arg)
	{
		if (context.arg[0] == '-')
			index++;
		for (; context.arg[index] != '\0'; index++)
		{
			if (context.arg[index] > 57 || context.arg[index] < 48)
				ident = 1;
		}
		if (ident == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(context.fil);
			free(context.data);
			free_mem_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(context.fil);
		free(context.data);
		free_mem_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(context.arg);
	if (context.flag == 0)
		node_add(head, n);
	else
		queue_add(head, n);
}
