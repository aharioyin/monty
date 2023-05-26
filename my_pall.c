#include "monty.h"
/**
 * pall_func -function that prints the values of all
 *              elements in the stack
 * @head: stack head
 * @count: line counter but it is not used
 * Return: no return
*/
void pall_func(stack_t **head, unsigned int count)
{
	stack_t *p;
	(void)count;

	p = *head;
	if (p == NULL)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
