#include "monty.h"

/**
 * divide - divides the second top element by the top element of the stack
 *
 * @stack: head of the stack
 * @line_number: line where the error occured
 *
 * Return: Null
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
	{
		handle_error(ERR_DIV_USG, NULL, line_number, NULL);
	}

	a = temp->n;

	if (a == 0)
	{
		handle_error(ERR_DIV_ZRO, NULL, line_number, NULL);
	}

	b = temp->next->n;
	temp->next->n = b / a;
	*stack = temp->next;
	free(temp);
}
