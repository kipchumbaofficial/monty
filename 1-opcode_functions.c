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
/**
 * add_function - Adds top two elements
 * @stack: Stack pointer
 * @line_number: Line number
 */
void add_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n += temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * sub_function - Subtact top element from the second one
 * @stack: Pointer to stack
 * @line_number: Line number
 */
void sub_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n -= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * div_function - Divides top two elements
 * @stack: Pointer to stack
 * @line_number: Line number
 */
void div_function(stack_t ** stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
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
	temp->next->n /= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
