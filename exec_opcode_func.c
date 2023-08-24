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
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{NULL, NULL}
	};

	while (instructions[x].f != NULL)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			instructions[x].f(&stack, line_number);
			return;
		}
		x++;
	}
	free(&stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
