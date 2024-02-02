#include "monty.h"

/**
 * pop_element - removes the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void pop_element(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    top = *stack;
    *stack = (*stack)->next;
    free(top);
}
