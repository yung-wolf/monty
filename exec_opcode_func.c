#include "monty.h"

/**
 * exec_opcode_func - execute opcode
 * @opcode: opcode
 * @line_number: line number
 * Return: ptr to opcode
 */
void exec_opcode_func(char *opcode, unsigned int line_number)
{
	int x = 0;

	instruction_t instructions[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	while (x < 2)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			instructions[x].f(&stack, line_number);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
