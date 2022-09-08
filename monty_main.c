#include "monty.h"

var_t var = {NULL, NULL, NULL, 0};

/**
 * parse - receives args from .m files
 * 
 * 
 */

/**
 * main - the entry point for Monty
 * @argc: the count of the argument passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int argc, int argv[])
{
	char *content;
	FILE *monty_file;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	While (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, monty_file);
		var.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, monty_file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(monty_file);
	return (0);
}
