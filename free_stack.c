#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
	if (*stack == NULL)
		return;
	while (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
