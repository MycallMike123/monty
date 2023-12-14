#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void add(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int len = 0, res;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	res = current->n + current->next->n;
	current->next->n = res;
	*head = current->next;
	free(current);
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
	stack_t *current;
	int res, nodes;

	current = *head;
	for (nodes = 0; current != NULL; nodes++)
		current = current->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	res = current->next->n - current->n;
	current->next->n = res;
	*head = current->next;
	free(current);
}

/**
 * _div - divides the top two elements of the stack.
 * @head:  Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void _div(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int nodes = 0, res;

	current = *head;
	while (current)
	{
		current = current->next;
		nodes++;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}

	res = current->next->n / current->n;
	current->next->n = res;
	*head = current->next;
	free(current);
}

/**
 * mul - Multiplies the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/
void mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int nodes = 0, res;

	current = *head;
	while (current)
	{
		current = current->next;
		nodes++;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	res = current->next->n * current->n;
	current->next->n = res;
	*head = current->next;
	free(current);
}
