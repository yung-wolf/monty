#include "monty.h"

/**
 * main - check/ run codes
 * @argc - args count
 * @argv - arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, *arg, *line = NULL;
	unsigned int line_number = 1;
	size_t num_read = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &num_read, file) != -1)
	{
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				push(&stack, arg, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number;
		}
	}

	fclose(file);
	if (line)
		free(line);

	return (0);
}
