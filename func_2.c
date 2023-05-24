#include "monty.h"
/**
 * c_pint - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void c_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * c_pop - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void c_pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * c_swap - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void c_swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

/**
 * c_add - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void c_add(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
  *c_nop- nothing
  *@head: stack head
  *@count: line_number
  *Return: no return
 */
void c_nop(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}
