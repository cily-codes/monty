#include "monty.h"

/**
 * handle_error - Manages the printing of interpreter errors
 *
 * @errno: The error code to manage
 * @opcode: The operation code to manage
 * @line: The line on which the error occurred
 * @buff: The reserved error line buffer
 *
 * Return: Null
 */
void handle_error(int errno, char *opcode, unsigned int line)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 200 && errno < 300)
		handle_uerror(errno, line);
	else
		return;

	frees_stack();
	exit(EXIT_FAILURE);
}

/**
 * handle_cerror - Manages common interpreter errors
 *
 * @errno: The error code to manage
 * @opcode: The operation code to manage
 * @line: The line on which the error occurred
 *
 * Return: Null
 */
void handle_cerror(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
 * handle_uerror - Manages interpreter usage errors
 *
 * @errno: The error code to manage
 * @line: The line on which the error occurred
 *
 * Return: Null
 */
void handle_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_ARG_USG:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_PUSH_USG:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case ERR_PINT_USG:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case ERR_POP_USG:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case ERR_SWAP_USG:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ERR_ADD_USG:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case ERR_SUB_USG:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case ERR_DIV_USG:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ERR_DIV_ZRO:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case ERR_MUL_USG:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case ERR_MOD_USG:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}