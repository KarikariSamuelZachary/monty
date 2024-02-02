#include "monty.h"

/**
 * print_top - prints the value at the top of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */

void print_top(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
