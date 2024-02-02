#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
    instruction_t instruct[] = {
        {"push", push_element},
        {"pall", print_stack},
        {"pint", print_top},
        {"pop", pop_element},
        {"swap", swap_elements},
        /* Add other opcode-function mappings as needed */
        {NULL, NULL}
    };
    int i;

    for (i = 0; instruct[i].opcode; i++)
    {
        if (_strcmp(instruct[i].opcode, opc) == 0)
            break;
    }

    if (instruct[i].f == NULL) {
        fprintf(stderr, "L%u: Unknown opcode: %s\n", vglo.cont, opc);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    return (instruct[i].f);
}