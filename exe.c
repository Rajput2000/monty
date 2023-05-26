#include "monty.h"
/**
* exe - executes the opcode
* @stack: head linked list - stack
* @freq: line_counter
* @data: pointer to monty file
* @content: line content
* Return: no return
*/
int exe(char *content, stack_t **stack, unsigned int freq, FILE *data)
{
	instruction_t opst[] = {
		{"push", c_push},
		{"pall", c_pall},
		{"pint", c_pint},
		{"pop", c_pop},
		{"swap", c_swap},
		{"add", c_add},
		{"nop", c_nop},
		{"queue", c_queue},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"sub", f_sub},
		{"stack", f_stack},
		{NULL, NULL}	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, freq);
			return (0);		}
		i++;	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", freq, op);
		fclose(data);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
