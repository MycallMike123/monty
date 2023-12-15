#include "monty.h"

/**
 * mod - Computes the remainder of the division of the
 * second top element by the top element of the stack
 * @head:  Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void mod(stack_t **head, unsigned int counter)
{
	int res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		_error(8, counter, "mod");

	if ((*head)->n == 0)
		_error(9, counter);

	(*head) = (*head)->next;
	res = (*head)->n % (*head)->prev->n;
	(*head)->n = res;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void pchar(stack_t **head, unsigned int counter)
{
	int characters;

	if (head == NULL || *head == NULL)
		str_error(11, counter);

	characters = (*head)->n;
	if (characters < 0 || characters > 127)
		str_error(10, counter);
	printf("%c\n", characters);
}

/**
 * pstr - rints the string starting at the top of the stack, followed by \n
 * @head: Pointer to the head of the stack
 * @integer: Line number in the Monty bytecode file
*/

void pstr(stack_t **head, __attribute__((unused))unsigned int integer)
{
	int characters;
	stack_t *res;

	if (head == NULL || *head == NULL)
	{
		printf("\n");
		return;
	}

	res = *head;
	while (res != NULL)
	{
		characters = res->n;
		if (characters <= 0 || characters > 127)
		{
			break;
		}
		printf("%c", characters);
		res = res->next;
	}
	printf("\n");
}

/**
 * rotl- Rotates the stack to the top
 * @head: Pointer to the head of the stack
 * @integer: Line number in the Monty bytecode file
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int integer)
{
	stack_t *res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		return;
	}

	res = *head;
	while (res->next != NULL)
		res = res->next;

	res->next = *head;
	(*head)->prev = res;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

/**
 * rotr- Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @integer: Line number in the Monty bytecode file
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int integer)
{
	stack_t *res;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		return;
	}

	res = *head;
	while (res->next != NULL)
		res = res->next;

	res->next = *head;
	res->prev->next = NULL;
	res->prev = NULL;
	(*head)->prev = res;
	(*head) = res;
}
