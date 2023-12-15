#define _GNU_SOURCE
#include "monty.h"

line_t line = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t line_rd = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	line.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_rd > 0)
	{
		cont = NULL;
		line_rd = getline(&cont, &size, file);
		line.cont = cont;
		counter++;

		if (line_rd > 0)
		{
			exec(cont, &stack, counter, file);
		}

		free(cont);
	}

	f_stack(stack);
	fclose(file);

	return (0);
}

/**
 * _stack - Sets the stack mode (LIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	line.flag_c = 0;
}

/**
 * _queue - Sets the stack mode (FIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	line.flag_c = 1;
}

/**
 * _addqueue - Adds a node to the tail of the stack
 * @head: Pointer to the head of the stack
 * @n: New value to be added to the stack
*/

void _addqueue(stack_t **head, int n)
{
	stack_t *n_node, *res;

	res = *head;
	n_node = malloc(sizeof(stack_t));

	if (n_node == NULL)
	{
		printf("Error\n");
	}

	n_node->n = n;
	n_node->next = NULL;
	if (res)
	{
		while (res->next)
			res = res->next;
	}
	if (!res)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		res->next = n_node;
		n_node->prev = res;
	}
}

/**
 * _addnode - Adds a node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: New value to be added to the stack
*/

void _addnode(stack_t **head, int n)
{
	stack_t *n_node, *res;

	res = *head;
	n_node = malloc(sizeof(stack_t));

	if (n_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (res)
	{
		res->prev = n_node;
	}

	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;
	*head = n_node;
}
