#include "monty.h"

/**
 * swap - Swaps the two elements at the top of the stack
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0, temp = 0;

	length = count_stack(*stack);

	if (length < 2)
	{
		handle_error(ERR_SWAP_USG, NULL, line_number, NULL);
	}

	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
