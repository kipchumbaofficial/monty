#include <stdio.h>
#include "monty.h"
/**
 * pushError - When cant push
 * @buffer: Buffer
 * @line_number: Line_number
 * @stack: Stack
 */
void pushError(FILE *fd, char *buffer, unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(buffer);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * not_ins: when ont opcode
 * @buffer: buffer
 * @line_number: line_number
 * @stack: Stack
 * @cmd: command
 */
void not_ins(FILE *fd, char *buffer, unsigned int line_number, stack_t *stack, char *cmd)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
	free(buffer);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
