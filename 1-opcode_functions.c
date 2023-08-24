 #include "monty.h"
/**
 * swap_function - Swaps top 2 elements
 * @stack: Stack pointer
 * @line_number: Line number
 *
 */
void swap_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i;
	if (!*stack || !stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	i = temp->n;
	temp->n = temp->next->n;
	temp->next->n = i;
}
