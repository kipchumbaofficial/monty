#include <stdio.h>
#include "monty.h"
/**
 * main - Entry point
 * @argv: Argument vector
 * @argc: Argument count
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		file_handler(argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
