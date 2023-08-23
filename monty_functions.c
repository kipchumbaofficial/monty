#include <stdio.h>
#include "monty.h"
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
			retval = executor(line_number, command, arg, stack);
			if (retval == 1)
				pushError(buffer, line_number, stack);
			if (retval == 2)
				not_instruction(fd, line_number, stack);
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
