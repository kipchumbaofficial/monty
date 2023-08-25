#include "monty.h"
/**
 * mul_function - Multiplies first two elements
 * @stack: Stack pointer
 * @line_number: Line number
 */
void mul_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n *= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * mod_function - Gets remainder
 * @stack: Stack pointer
 * line_number: Line number
 */
void mod_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
