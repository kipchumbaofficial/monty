#include <stdio.h>
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
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
 * div_opcode - Div opcode
 * @stack: POinter to stack
 * @line_number: Line_number
 */
void div_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack ||!(*stack)->next)
	{
		fprintf(stderr, "L%u: cant div, stack too short\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
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
