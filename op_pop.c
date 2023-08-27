#include "monty.h"

/**
 * pop - Removes the top element of the stack
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
	{
		handle_error(ERR_POP_USG, NULL, line_number, NULL);
	}

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
