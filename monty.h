#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct context_s - variables -args, file, line content
 * @arg: value
 * @fil: pointer to monty file
 * @data: line content
 * @flag: flag change stack <-> queue
 * Description: struct that carries values through the program
 */
typedef struct context_s
{
	char *arg;
	FILE *fil;
	char *data;
	int flag;
}  context_t;
extern context_t context;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_reallocate(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t get_stdin(char **lineptr, int fil);
char  *clean_line(char *data);
void push_func(stack_t **head, unsigned int num);
void pall_func(stack_t **head, unsigned int count);
void pint_func(stack_t **head, unsigned int num);
int exec(char *data, stack_t **head, unsigned int count, FILE *fil, context_t context);
void free_mem_stack(stack_t *head);
void pop_func(stack_t **head, unsigned int count);
void swap_func(stack_t **head, unsigned int count);
void add_func(stack_t **head, unsigned int count);
void nop_func(stack_t **head, unsigned int count);
void sub_func(stack_t **head, unsigned int count);
void div_func(stack_t **head, unsigned int count);
void mul_func(stack_t **head, unsigned int count);
void mod_func(stack_t **head, unsigned int count);
void pchar_func(stack_t **head, unsigned int count);
void pstr_func(stack_t **head, unsigned int count);
void rotl_func(stack_t **head, unsigned int count);
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int count);
void node_add(stack_t **head, int n);
void queue_add(stack_t **head, int n);
void queue_func(stack_t **head, unsigned int count);
void stack_func(stack_t **head, unsigned int count);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
