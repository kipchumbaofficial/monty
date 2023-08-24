#include "monty.h"
int int_value;
/**
 * file_handler - Handles file passed
 * @file_path: path of file
 *
 */
void file_handler(char *file_path)
{
	unsigned int retval = 0, line_number = 0;
	stack_t *stack = NULL;
	char *buffer = NULL;
	size_t buffsize = 0;
	char *command = NULL, *arg = NULL;
	FILE *fd;

	fd = fopen(file_path, "r");
	if (fd)
	{
		while (getline(&buffer, &buffsize, fd) !=  -1)
		{
			line_number++;
			command = strtok(buffer, " \n\t\r");
			if (command == NULL)
			{
				free(command);
				continue;
			}
			else if (*command == '#')
				continue;
			arg = strtok(NULL, " \n\t\r");
			retval = executor(line_number, command, arg, &stack);
			if (retval == 1)
				pushError(buffer, line_number, stack);
			if (retval == 2)
				not_ins(fd, buffer, line_number, stack, command);
		}
		free(buffer);
		free_stack(stack);
		fclose(fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * executor - Calls opcode function
 * @line_number: Line ni of commands
 * @command: opcode
 * @arg: command args
 * @stack: stack
 *
 * Return: 1 if cantpush and 2 if not opcode
 */
int executor(int line_number, char *command, char *arg, stack_t **stack)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push_function},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, command))
		{
			if (!strcmp(ops[i].opcode, "push"))
			{
				if (isDigit(arg) == 1)
					int_value = atoi(arg);
				else
					return (1);
			}
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (!ops[i].opcode)
		return (2);
	return (0);
}
