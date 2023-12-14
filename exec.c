#include "monty.h"

/**
* exec - Executes the Monty opcode
* @stack: Pointer to the head of the stack
* @counter: Line content containing the Monty instruction
* @file: Pointer to the Monty bytecode file
* @cont: Line number in the Monty bytecode file
* Return: 0 Success, 1 otherwise
*/

int exec(char *cont, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", handle_push}, {"pall", handle_pall}, {"pint", handle_pint},
				{"pop", handle_pop},
				{"swap", handle_swap},
				{"add", add},
				{"nop", handle_nop},
				{"sub", sub},
				{"div", _div},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *op_;

	op_ = strtok(cont, " \n\t");
	if (op_ && op_[0] == '#')
		return (0);
	line.arg = strtok(NULL, " \n\t");
	while (opst[a].opcode && op_)
	{
		if (strcmp(op_, opst[a].opcode) == 0)
		{	opst[a].f(stack, counter);
			return (0);
		}
		a++;
	}
	if (op_ && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_);
		fclose(file);
		free(cont);
		f_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
* f_stack - Frees a doubly linked list
* @head: Pointer to the head of the stack
*/

void f_stack(stack_t *head)
{
	stack_t *res;

	res = head;
	while (head)
	{
		res = head->next;
		free(head);
		head = res;
	}
}
