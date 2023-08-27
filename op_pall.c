#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * beginning from the top of the stack
 *
 * @stack: head of the stack
 * @line_number: line where the error occurred
 *
 * Return: Null
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void) line_number;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
