#include "monty.h"
/**
 * pushError - When cant push
 * @buffer: Buffer
 * @line_number: Line_number
 * @stack: Stack
 */
void pushError(char *buffer, unsigned int line_number, stack_t *stack)
{
	dprintf(STDERR_FILENO, "L%u: Usage: push integer", line_number);
	free(buffer);
	free_stack(stack);
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
	dprintf(STDERR_FILENO, "L%u: uknown instructions %s\n", line_number, cmd);
	free(buffer);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
