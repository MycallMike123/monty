#include "monty.h"

/**
 * f_call - Calls the required function
 * @func: Pointer to the function that is about to be called
 * @op_code: string representing the opcode.
 * @value: string representing a numeric value
 * @n: line number for the instruction
 * @type: Format specifier
 */
void f_call(_op func, char *op_code, char *value, int n, int type)
{
	stack_t *node;
	int fl, a;

	fl = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			fl = -1;
		}
		if (value == NULL)
			error_(5, n);
		for (a = 0; value[a] != '\0'; a++)
		{
			if (isdigit(value[a]) == 0)
			{
				error_(5, n);
			}
		}
		node = handle_push(atoi(value) * fl);
		if (type == 0)
		{
			func(&node, n);
		}
		if (type == 1)
			_addqueue(&node, n);
	}
	else
	{
		func(&first, n);
	}
}

/**
 * rd_file - reads a file
 * @file_descriptor: pointer to file descriptor
 */

void rd_file(FILE *file_descriptor)
{
	int counter, type;
	char *buffer = NULL;
	size_t len = 0;

	type = 0;
	for (counter = 1; custom_getline(&buffer, &len, file_descriptor) != -1; counter++)
	{
		type = _queue(buffer, counter, type);
	}
	free(buffer);
}

/**
 * custom_getline - reads a line from a file stream
 * @content: pointer to the buffer where the line will be stored
 * @size: pointer to the size of the buffer
 * @file: file stream to read from
 * Return: the number of characters read (including newline), or -1 on failure
 */

ssize_t custom_getline(char **content, size_t *size, FILE *file)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread = 0;
	int c;

	if (!content || !size || !file)
		return (-1);
	while (1)
	{
		c = fgetc(file);
		if (c == EOF)
		{
			if (nread == 0)
			{
				free(buffer);
				return (-1);
			}
			break;
		}
		if ((size_t)nread >= bufsize - 1)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
				return (-1);
		}

		buffer[nread++] = c;
		if (c == '\n')
			break;
	}
	buffer[nread] = '\0';
	*content = buffer;
	*size = bufsize;
	return (nread);
}
