#include "monty.h"

/**
* exec - Executes the Monty opcode
* @opcode: Pointer to the head of the stack
* @value: Line content containing the Monty instruction
* @type: The storage
* @n: Line number in the Monty bytecode file
*/

void exec(char *opcode, char *value, int n, int type)
{
	int a, fl;

	instruction_t opst[] = {
				{"push", _addnode}, {"pall", _stack}, {"pint", handle_pint},
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
				{NULL, NULL}
				};

	if (opcode[0] == '#')
	{
		return;
	}

	for (fl = 1, a = 0;  opst[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, opst[a].opcode) == 0)
		{
			f_call(opst[a].f, opcode, value, n, type);
			fl = 0;
		}
	}
	if (fl == 1)
		error_(3, n, opcode);
}

/**
 * f_stack - Frees nodes in the stack.
 */

void f_stack(void)
{
	stack_t *res;

	if (first == NULL)
	{
		return;
	}

	while (first != NULL)
	{
		res = first;
		first = first->next;
		free(res);
	}
}

/**
 * error_ - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes 1, 2,3,4,5,6,7, and 8
 */

void error_(int error_code, ...)
{
	va_list argument;
	char *op_code;
	int dig;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argument, char *));
			break;
		case 3:
			dig = va_arg(argument, int);
			op_code = va_arg(argument, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", dig, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argument, int));
			break;
		default:
			break;
	}
	f_stack();
	exit(EXIT_FAILURE);
}

/**
 * _error - handles errors.
 * @error_code: The error codes are 6 to nine
 */

void _error(int error_code, ...)
{
	va_list argument;
	char *op_code;
	int dig;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argument, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argument, int));
			break;
		case 8:
			dig = va_arg(argument, unsigned int);
			op_code = va_arg(argument, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", dig, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argument, unsigned int));
			break;
		default:
			break;
	}
	f_stack();
	exit(EXIT_FAILURE);
}

/**
 * str_error - handles errors error in strings
 * @error_code: The error codes are 10 and 11
 */

void str_error(int error_code, ...)
{
	va_list argument;
	int dig;

	va_start(argument, error_code);
	dig = va_arg(argument, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", dig);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", dig);
			break;
		default:
			break;
	}
	f_stack();
	exit(EXIT_FAILURE);
}
