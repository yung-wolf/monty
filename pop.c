#include "monty.h"

/**
 * pop - deletes top element of stack
 * @stack: stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		free(stack);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *ptr = NULL;

		ptr = *stack;
		if ((*stack)->next == NULL)
		{
			free(ptr);
			*stack = NULL;
		}
		else
		{
		*stack = (*stack)->next;
		(*stack->prev) = NULL;
		free(ptr);
		}
	}
}
