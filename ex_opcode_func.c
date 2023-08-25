#include "monty.h"

/**
 * ex_opcode_func - execute opcode
 * @opcode: opcode
 * Return: ptr to opcode
 */
void (*ex_opcode_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	while (instructions[x].f != NULL)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			return (instructions[x].f);
		}
		x++;
	}
	return (NULL);
}
