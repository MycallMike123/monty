#include "monty.h"


/**
 * handle_push - Adds a node to the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
*/

void handle_push(stack_t **head, unsigned int counter)
{
	int value, b, flag;

	b = 0;
	flag = 0;
	if (line.arg)
	{
		if (line.arg[0] == '-')
			b++;
		for (; line.arg[b] != '\0'; b++)
		{
			if (line.arg[b] > 57 || line.arg[b] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(line.file);
			free(line.cont);
			f_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE); }
	value = atoi(line.arg);

	if (line.flag_c == 0)
	{
		_addnode(head, value);
	}
	else
	{
		_addqueue(head, value);
	}
}

/**
 * handle_pall - Prints the elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter
 */

void handle_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
	{
		return;
	}
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * handle_pint - Prints the value at the top of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * handle_pop - Removes the top element from the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * handle_swap - Swaps the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty bytecode file
 */

void handle_swap(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int len, temp;

	len = 0;
	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(line.file);
		free(line.cont);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
