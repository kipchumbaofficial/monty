#include "monty.h"
/**
 * main - Entry point
 * @argv: Argument vector
 * @argc: Argument count
 *
 * Return: Always 0
 */
extern int int_value;

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		file_handler(argv[1]);
	}
	else
	{
		dprintf(STDERR_FILENO, "USAGE: Monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
