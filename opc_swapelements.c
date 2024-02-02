#include "monty.h"

/**
 * swap_elements - swaps the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 */
void swap_elements(stack_t **stack, unsigned int line_number)
{
    int count = 0;
    stack_t *current = *stack;
    stack_t *temp = NULL;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    if (count < 2)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    current = *stack;
    *stack = (*stack)->next;
    temp = current->next;
    current->next = temp->next;
    current->prev = temp;
    temp->next = current;
    temp->prev = NULL;

    if (current->next != NULL)
        current->next->prev = current;
}
