#include "main.h"

#define MAX_LINE_LENGTH 256
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		char *token = strtok(line, " \n");
		if (token)
		{
			if (strcmp(token, "push") == 0)
			{
				push(&stack, line_number);
			}
			else if (strcmp(token, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else if (strcmp(token, "pint") == 0)
			{
				pint(&stack, line_number);
			}
			else if (strcmp(token, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(token, "add") == 0)
			{
				add(&stack, line_number);
			}
			else if (strcmp(token, "nop") == 0)
			{
				nop(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "Error: Unknown command at line %u\n", line_number);
				return (EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);

}
