#include "monty.h"

/**
 * mod - Computes the remainder of the division of the
 * second top element by the top element of the stack
 * @head:  Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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

	res = current->next->n % current->n;
	current->next->n = res;
	*head = current->next;
	free(current);
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void pchar(stack_t **head, unsigned int counter)
{
	stack_t *current;

	current = *head;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}

/**
 * pstr - rints the string starting at the top of the stack, followed by \n
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * rotl- Rotates the stack to the top
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head;
	stack_t *res;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	res = (*head)->next;
	res->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = res;
}

/**
 * rotr- Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
