#include "main.h"

/*
 *push_opcode - pushes an element to the stack
 *
 *@stack: head of the linked list
 *@line_number: line number
 *Return: no return
 *
 **/
void push(stack_t **stack, unsigned int line_number)
{
	char *num;
	int value;
	int i;
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "Error: Invalid stack\n");
		exit(EXIT_FAILURE);
	}
	num = strtok(NULL, " \n");
	if (!num)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i=0; num[i] != '\0'; i++)
	{

		if (!isdigit(num[i]) && num[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(num);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**i
 *pall_opcode - prints all values on the stack
 *
 *@stack: head of the linked list
 *@line_number: line numbers
 *Return: no return
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
