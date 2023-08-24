#include "monty.h"
/**
 * push_function -Pushes tostack
 * @stack: Stack to push ti
 * @line_number: line number
 */
void push_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = int_value;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}
/**
 * pall_function - prints all ellements in the stack
 * @stack: stack
 * @line_number: Line number
 *
 */
void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (stack && *stack)
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
/**
 * pint_function - Prints top element in stack
 * @stack: Stack
 * @line_number: Line number
 *
 */
void pint_function(stack_t **stack, unsigned int line_number)
{
	if (!stack ||  !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop_function - Removes top element from stack
 * @stack: Stack pointer
 * @line_number: Line number
 */
void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		if (temp->next)
			(*stack)->prev = NULL;
		else
			*stack = NULL;
		free(temp);
	}
}

/**
 * nop_function - Does nothing
 * @stack: Pointer to stack
 * @line_number: Line number
 */
void nop_function(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
