#include "monty.h"

/**
 * print_stack - prints all values on the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line numbers
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
