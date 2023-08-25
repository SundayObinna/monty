#include "customheader.h"

void f_mod(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);

/**
 * f_mod - Computes the rest of the division
 * @head: Head.
 * @counter: Line number.
 *
 * Code by 0xOneBeing
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len, aux;

	len = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}


/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Head.
 * @counter: Line number.
 *
 * Code by 0xOneBeing
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len, aux;

	len = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}


/**
 * f_nop- Not a thing
 * @head: Head.
 * @counter: Line number.
 *
 * Code by 0xOneBeing
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}


/**
 * f_pall - Prints the stack.
 * @head: Head.
 * @counter: Counter.
 *
 * Code by 0xOneBeing
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
 * f_pchar - Prints the character at the top of stack.
 * @head: Head.
 * @counter: Line number.
 *
 * Code by 0xOneBeingf
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
