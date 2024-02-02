#include "monty.h"

global_t vglo;

void free_vglo(void)
{
    free_dlistint(vglo.head);
    free(vglo.buffer);
    fclose(vglo.fd);
}

void start_vglo(FILE *fd)
{
    vglo.lifo = 1;
    vglo.cont = 1;
    vglo.arg = NULL;
    vglo.head = NULL;
    vglo.fd = fd;
    vglo.buffer = NULL;
}

FILE *check_input(int argc, char *argv[])
{
    FILE *fd;

    if (argc == 1 || argc > 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return (fd);
}

int main(int argc, char *argv[])
{
    void (*f)(stack_t **stack, unsigned int line_number);
    FILE *fd;
    size_t size = 256;
    char *lines[2] = {NULL, NULL};

    fd = check_input(argc, argv);
    start_vglo(fd);

    while (fgets(vglo.buffer, size, fd) != NULL)
    {
        lines[0] = _strtoky(vglo.buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#')
        {
            f = get_opcodes(lines[0]);
            if (!f)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", vglo.cont, lines[0]);
                free_vglo();
                exit(EXIT_FAILURE);
            }
            vglo.arg = _strtoky(NULL, " \t\n");
            f(&vglo.head, vglo.cont);
        }
        vglo.cont++;
    }

    free_vglo();

    return (0);
}
