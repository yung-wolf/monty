#include "monty.h"

void exec_opcode_func(char *opcode, char *arg, unsigned int line_number)
{
	int x = 0;

	instruction_t instructions[] = {
		{"pall"; pall},
		{NULL, NULL}
	};

	while (x < 2)
	{
		if (strcmp(f, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number;
			return;
		}
		x++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
