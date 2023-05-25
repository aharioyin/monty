#include "monty.h"

/**
* exec -function that executes the opcode specified in the data string
* @stack: head linked list - stack
* @count: line_counter
* @fil: poiner to monty file
* @data: line content
* Return: no return
*/

int exec(char *data, stack_t **stack, unsigned int count, FILE *fil)
{
	instruction_t opst[] = {
				{"push", push_func}, {"pall", pall_func}, {"pint", pint_func},
				{"pop", pop_func},
				{"swap", swap_func},
				{"add", add_func},
				{"nop", nop_func},
				{"sub", sub_func},
				{"div", div_func},
				{"mul", mul_func},
				{"mod", mod_func},
				{"pchar", pchar_func},
				{"pstr", pstr_func},
				{"rotl", rotl_func},
				{"rotr", rotr_func},
				{"queue", queue_func},
				{"stack", stack_func},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *opCodeptr;

	opCodeptr = strtok(data, " \n\t");
	if (opCodeptr && opCodeptr[0] == '#')
		return (0);
	context.arg = strtok(NULL, " \n\t");
	while (opst[a].opcode && opCodeptr)
	{
		if (strcmp(opCodeptr, opst[a].opcode) == 0)
		{	opst[a].f(stack, count);
			return (0);
		}
		a++;
	}
	if (opCodeptr && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, opCodeptr);
		fclose(fil);
		free(data);
		free_mem_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
