#include "monty.h"

/**
 * frees_stack - it frees up stack
 *
 * Return: Null
 */
void frees_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}
