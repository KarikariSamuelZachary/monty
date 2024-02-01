#include "monty.h"

void monty_execute(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read file line by line and execute Monty bytecode
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1) {
        line_number++;
        tokenize_and_execute(line, line_number);
    }

    free(line);
    fclose(file);
}
