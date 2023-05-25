#include "monty.h"


/**
* main - Entry point and intepreter of the Monty code
* @argc: number of arguments
* @argv: monty fil location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *data;
	FILE *fil;
	size_t size = 0;
	ssize_t nums_reads = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;


	context_t context = {NULL, NULL, NULL, 0};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty fil\n");
		exit(EXIT_FAILURE);
	}
	fil = fopen(argv[1], "r");
	context.fil = fil;
	if (!fil)
	{
		fprintf(stderr, "Error: Can't open fil %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (nums_reads > 0)
	{
		data = NULL;
		nums_reads = getline(&data, &size, fil);
		context.data = data;
		count++;
		if (nums_reads > 0)
		{
			exec(data, &stack, count, fil);
		}
		free(data);
	}
	free_mem_stack(stack);
	fclose(fil);
return (0);
}
