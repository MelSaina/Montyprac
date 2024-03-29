#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/*
 *struct stack_s - doubly linked list representation of a stack (or queue)
 *@n: integer
 *@prev: points to the previous element of the stack (or queue)
 *@next: points to the next element of the stack (or queue)
 *
 *Description: doubly linked list node structure
 *for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/*
 *struct instruction_s - opcode and its function
 *@opcode: the opcode
 *@f: function to handle the opcode
 *
 *Description: opcode and its function
 *for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct global_s
{
	char *arg;
	int lifo;
	/* Add any other global variables you need */
} global_t;
extern global_t vglo;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
