#include "monty.h"

stack_t *first = NULL;

/**
 * main - Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_open(argv[1]);
	f_stack();
	return (0);
}

/**
 * _stack - Sets the stack mode (LIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/
void _stack(stack_t **head, unsigned int counter)
{
	stack_t *res;

	(void) counter;
	if (head == NULL)
		exit(EXIT_FAILURE);
	res = *head;
	while (res != NULL)
	{
		printf("%d\n", res->n);
		res = res->next;
	}
}

/**
 * _queue - Separates each line into tokens to determine
 * @buffer: line from the file
 * @type: the format
 * @counter: Line number in the Monty bytecode file
 * Return: 0 if stack, 1 if queue
*/

int _queue(char *buffer, int counter, int type)
{
	char *op_code;
	char *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		error_(4);
	}

	op_code = strtok(buffer, delim);
	if (op_code == NULL)
	{
		return (type);
	}
	value = strtok(NULL, delim);

	if (strcmp(op_code, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(op_code, "queue") == 0)
	{
		return (1);
	}

	exec(op_code, value, counter, type);

	return (type);
}

/**
 * _addqueue - Adds a node to the tail of the stack
 * @n_node: Pointer to the head of the stack
 * @n: New value to be added to the stack
*/

void _addqueue(stack_t **n_node, __attribute__((unused))unsigned int n)
{
	stack_t *res;

	if (n_node == NULL || *n_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (first == NULL)
	{
		first = *n_node;
		return;
	}
	res = first;
	while (res->next != NULL)
		res = res->next;

	res->next = *n_node;
	(*n_node)->prev = res;

}

/**
 * _addnode - Adds a node to the head of the stack
 * @n_node: Pointer to the head of the stack
 * @n: New value to be added to the stack
*/

void _addnode(stack_t **n_node, __attribute__((unused))unsigned int n)
{
	stack_t *res;

	if (n_node == NULL || *n_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (first == NULL)
	{
		first = *n_node;
		return;
	}
	res = first;
	first = *n_node;
	first->next = res;
	res->prev = first;
}
