#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a new line
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_error(ERR_PINT_USG, NULL, line_number, NULL);
	}

	printf("%d\n", (*stack)->n);
}
