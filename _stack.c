#include "monty.h"

/**
 * is_num - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_num(char *n)
{
	int x = 0;

	if (*n == '-')
		x = 1;
	for (; *(n + x) != '\0'; x++)
	{
		if (isdigit(*(n + x)) == 0)
			return (-1);
	}
	return (0);
}


/**
 * push - push element to top of stack
 * @stack: stack
 * @n: int n parsed as char from token
 * @line_number: line number of n
 */
void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (is_num(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	i = atoi(n);
	new_node->n = i;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	(*stack) = new_node;
}


/**
 * pall - prints elements in stack from top to bottom
 * @stack: custome stack
 * @line_number: current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!stack || !*stack)
		return;

	(void) line_number;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}


/**
 * pint - print top element of stack
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - deletes top element of stack
 * @stack: stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
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
			(*stack)->prev = NULL;
			free(ptr);
		}
	}
}
