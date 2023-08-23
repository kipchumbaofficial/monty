#include "monty.h"
/**
 * push_function -Pushes tostack
 * @stack: Stack to push ti
 * @line_number: line number
 */
void push_function(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc faild\n");
		exit(EXIT_FAILURE);
	}
	new->n = int_value;
	new->next = NULL;
	new->prev = NULL;
	if (stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}
