#include "monty.h"

/**
 * push_element - pushes an element onto the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void push_element(stack_t **stack, unsigned int line_number)
{
    int value, index;

    if (!vglo.arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    for (index = 0; vglo.arg[index] != '\0'; index++)
    {
        if (!isdigit(vglo.arg[index]) && vglo.arg[index] != '-')
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            free_vglo();
            exit(EXIT_FAILURE);
        }
    }

    value = atoi(vglo.arg);

    if (vglo.lifo == 1)
        add_stack_top(stack, value);
    else
        add_stack_bottom(stack, value);
}
