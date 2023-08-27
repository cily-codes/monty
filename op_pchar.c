#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack,
 * followed by a new line
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_error(ERR_PCH_EMP, NULL, line_number, NULL);
	}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		handle_error(ERR_PCH_USG, NULL, line_number, NULL);
	}
}
