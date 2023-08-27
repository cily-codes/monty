#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
	{
		handle_error(ERR_MUL_USG, NULL, line_number, NULL);
	}

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b * a;
	*stack = temp->next;
	free(temp);
}
