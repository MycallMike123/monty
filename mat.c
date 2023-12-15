#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void add(stack_t **head, unsigned int counter)
{
	int res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		_error(8, counter, "add");

	(*head) = (*head)->next;
	res = (*head)->n + (*head)->prev->n;
	(*stack)->n = res;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 *handle_nop- No operation, does nothing
 *@head:  Pointer to the head of the stack
 *@counter: Line number in the Monty bytecode file
 */

void handle_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 *sub- Subtracts the top element from the second top element of the stack
 *@head:  Pointer to the head of the stack
 *@counter: Line number in the Monty bytecode file
 */
void sub(stack_t **head, unsigned int counter)
{
	int res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)

		_error(8, counter, "sub");


	(*head) = (*head)->next;
	res = (*head)->n - (*head)->prev->n;
	(*head)->n = res;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * _div - divides the top two elements of the stack.
 * @head:  Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void _div(stack_t **head, unsigned int counter)
{
	int res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		_error(8, counter, "div");

	(*head) = (*head)->next;
	res = (*head)->n / (*head)->prev->n;
	(*head)->n = res;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * mul - Multiplies the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/
void mul(stack_t **head, unsigned int counter)
{
	int res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		_error(8, counter, "mul");

	(*head) = (*head)->next;
	res = (*head)->n * (*head)->prev->n;
	(*head)->n = res;
	free((*head)->prev);
	(*head)->prev = NULL;
}
