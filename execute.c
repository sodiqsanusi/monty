#include "monty.h"

/**
* execute - finds the function matching the opcode
* @h: pointer to dll
* @line: command line
* @line_number: line number of the command line in the file
*
* Return: 0 on Success, 1 on blank lines or push
* return -1 on catastrophic failure
*/
int execute(stack_t **h, char *line, unsigned int line_number)
{
	instruction_t instr[] = {
		{"pall", pall}, {"add", _add},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod},
		{"pint", pint}, {"pchar", pchar},
		{"pop", pop}, {"rotl", rotl},
		{"rotr", rotr}, {"stack", stack},
		{"queue", queue}, {"nop", nop},
		{"swap", swap}, {"pstr", pstr},
		{NULL, NULL}
	};
	int i, push_return;
	char *start_c;

	start_c = skip_spaces(line);
	if (start_c == NULL)
	{
		free(line);
		return (1);
	}
	if (_strncmp(start_c, "push", _strlen("push")) == 0)
	{
		push_return = push(h, line, line_number);
		return ((push_return == 0) ? 0 : -1);
	}
	for (i = 0; instr[i].opcode; ++i)
	{
		if (_strncmp(start_c, instr[i].opcode, _strlen(instr[i].opcode)) == 0)
		{
			free(line), (instr[i].f)(h, line_number);
			return (0);
		}
	}
	printf("L%d: unknown instruction ", line_number);
	while (*start_c && (*start_c != ' ' && *start_c != '\t'))
		putchar(*start_c++);
	putchar('\n');
	free(line);
	return (-1);
}


/**
* get_argument - return the arguments for calulations
* @h: "stack_t **" pointer to dll
* @opcode: "char *" opcode string
* @l: "unsigned int" line number
*
* Return: "int" the argument
*/
int get_argument(stack_t **h, char *opcode, unsigned int l)
{
	stack_t *node;
	int tmp;

	node = pop_s(h);

	if (node == NULL)
	{
		printf("L%d: can't %s, stack too short\n", l, opcode);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = node->n;
	free(node);
	return (tmp);
}

