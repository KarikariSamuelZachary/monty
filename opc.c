#include "monty.h"

/**
 * op_push - Pushes an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void op_push(stack_t **stack, unsigned int line_number) {
    char *token = strtok(NULL, " \t\n");
    
    if (!token || !isdigit(*token)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(token);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/**
 * op_pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void op_pall(stack_t **stack, unsigned int line_number) {
    if (!stack) {
        fprintf(stderr, "L%u: stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *current = *stack;

    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * op_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void op_pint(stack_t **stack, unsigned int line_number) {
    if (!stack || !*stack) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
