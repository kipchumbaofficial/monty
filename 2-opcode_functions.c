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
/**
 * pchar - pchar opcode function
 * @stack: Pointer to stack
 * @line_number: line number
 */
void pchar_function(stack_t **stack, unsigned int line_number)
{
	char c;
	int i;

	if (!stack  || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(fd);
		free(stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;

	if (i < 0 || i > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(fd);
		free_stack(*stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	c = (char)i;
	putchar(c);
	putchar('\n');
}
/**
 * pstr_function - Prints string from stack elements
 * @stack: stack pointer
 * @line_number: Line number
 */
void pstr_function(stack_t **stack, unsigned int line_number)
{
	char c;
	int i;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pstr, stack empty\n", line_number);
		free_func(*stack);
		exit(EXIT_FAILURE);
	}

	i = (*stack)->n;
	if (i < 0 || i > 127)
	{
		fprintf(stderr, "L%u: can't pstr, value out of range\n", line_number);
		free_func(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->prev && (*stack)->next)
	{
		c = (char)i;
		printf("%c", c);
	}
	while ((*stack)->next && i != 0)
	{
		c = (char)i;
		printf("%c", c);
		*stack = (*stack)->next;
		i = (*stack)->n;
	}
	putchar('\n');
}
