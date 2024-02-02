#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void push_element(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **doubly, unsigned int cline);
void pop_element(stack_t **doubly, unsigned int cline);
void swap_elements(stack_t **doubly, unsigned int cline);
void stack(stack_t **doubly, unsigned int cline);
void add_top_two(stack_t **doubly, unsigned int cline);
void nop(stack_t **doubly, unsigned int cline);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
int _strcmp(char *s1, char *s2);

void free_vglo(void);

#endif
