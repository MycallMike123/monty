#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @cont: line content
 * @flag_c: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct line_s
{
	char *arg;
	FILE *file;
	char *cont;
	int flag_c;
}  line_t;

line_t line = {NULL, NULL, NULL, 0};

int exec(char *cont, stack_t **stack, unsigned int counter, FILE *file);
void f_stack(stack_t *head);
void add(stack_t **head, unsigned int counter);
void handle_nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, __attribute__((unused)) unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void handle_push(stack_t **head, unsigned int counter);
void handle_pall(stack_t **head, unsigned int counter);
void handle_pint(stack_t **head, unsigned int counter);
void handle_pop(stack_t **head, unsigned int counter);
void handle_swap(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);
void _queue(stack_t **head, unsigned int counter);
void _addqueue(stack_t **head, int n);
void _addnode(stack_t **head, int n);


#endif
