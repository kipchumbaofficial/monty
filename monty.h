#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct stack_s - DLL rep of a stack
 * @n: int
 * @prev: Previous pointer
 * @next: Next pointer
 *
 * Description: DLL node structure for stack or queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack or ques
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}  instruction_t;

extern int int_value;

void push_function(stack_t **stack, unsigned int line_number);
void file_handler(char *file_path);
int executor(int line_number, char *command, char *arg, stack_t **stack);
void pushError(char *buffer, unsigned int line_number, stack_t *stack);
void pall_function(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void not_ins(FILE *fd, char *buffer, unsigned int line_number, stack_t *stack, char *cmd);
int isDigit(char *arg);

#endif
