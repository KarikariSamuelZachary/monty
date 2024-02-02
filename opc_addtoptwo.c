#include "monty.h"

/**
 * add_top_two - adds the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *current = *stack;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    if (count < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    current = (*stack)->next;
    current->n += (*stack)->n;
    pop_element(stack, line_number);
}
