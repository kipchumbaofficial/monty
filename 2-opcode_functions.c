#include "monty.h"
/**
 * mul_function - mul opcode function
 * @stack: Pointer to pointer to stack
 * @line_number: Line number
 */
void mul_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(fd);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n *= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
/**
 * mod_function - mod opcode function
 * @stack: Pointer to pointer to stack
 * @line_number: Line number
 */
void mod_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if(!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(fd);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(fd);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n %= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
