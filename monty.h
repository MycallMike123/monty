#ifndef MONTY_H
#define MONTY_H

#define BUFFER_SIZE 1024

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


extern stack_t *first;
typedef void (*_op)(stack_t **, unsigned int);

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

void call_fun(_op, char *, char *, int, int);
void f_open(char *file_name);
void f_stack(void);
void error_(int error_code, ...);
void _error(int error_code, ...);
void str_error(int error_code, ...);
void add(stack_t **, unsigned int);
void handle_nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
stack_t *handle_push(int n);
void handle_pint(stack_t **, unsigned int);
void handle_pop(stack_t **, unsigned int);
void handle_swap(stack_t **, unsigned int);
void _stack(stack_t **, unsigned int);
int _queue(char *buffer, int line_number, int format);
void _addqueue(stack_t **, unsigned int);
void _addnode(stack_t **, unsigned int);
void rd_file(FILE *);
int _len(FILE *);
void f_find(char *, char *, int, int);

#endif
