#include "monty.h"
/**
 * main - calls the various functions to excute command
 * @argc: argument counter
 * @argv: file to be passsed in
 * Return: 1 on sucess, 0 on error
 *
 */
var_t var;
int main(int argc, char *argv[])
{
	char *line = NULL;
	FILE *fp;
	int line_number = 0;
	stack_t *stack = NULL;
	size_t line_read = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	var.fp = fp;
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, line_read, fp) != NULL)
	{
		line_number++;
		var.line = line;
		if (line[0] != '\0' && line[0] != '\n')
		{
			execute(&stack, line_number, fp);
		}
	}
	fclose(fp);
	free_stack(&stack);
	free(line);
	return (0);
}
