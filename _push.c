#include "monty.h"


/**
 * handle_push - Adds a node to the stack
 * @n: Number to go inside of the node
 * Return: A pointer to the node
*/

stack_t *handle_push(int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		error_(4);
	n_node->next = NULL;
	n_node->prev = NULL;
	n_node->n = n;
	return (n_node);
}

/**
 * handle_pint - Prints the value at the top of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_pint(stack_t **head, unsigned int counter)
{
	if (head == NULL || *head == NULL)
		_error(6, counter);
	printf("%d\n", (*head)->n);
}

/**
 * handle_pop - Removes the top element from the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_pop(stack_t **head, unsigned int counter)
{
	stack_t *res;

	if (head == NULL || *head == NULL)
		_error(7, counter);

	res = *head;
	*head = res->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(res);
}

/**
 * handle_swap - Swaps the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_swap(stack_t **head, unsigned int counter)
{
	stack_t *res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		_error(8, counter, "swap");
	}
	res = (*head)->next;
	(*head)->next = res->next;
	if (res->next != NULL)
	{
		res->next->prev = *head;
	}
	res->next = *head;
	(*head)->prev = res;
	res->prev = NULL;
	*head = res;
}

/**
 * f_open - Opens a file
 * @file_name: the file namepath
 */

void f_open(char *file_name)
{
	FILE *file_descriptor = fopen(file_name, "r");

	if (file_name == NULL || file_descriptor == NULL)
		error_(2, file_name);

	rd_file(file_descriptor);
	fclose(file_descriptor);
}
