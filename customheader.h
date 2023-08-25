#ifndef _CUSTOMHEADER_H_
#define _CUSTOMHEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct stack_s - Doubly linked list stack (or queue).
 * @n: Integer.
 * @next: Points to next element of the stack (or queue).
 * @prev: Points to previous element of the stack (or queue).
 *
 * Code by 0xOneBeing
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - The variables: args, file, line content.
 * @file: Pointer to monty file.
 * @lifi: Flag change stack <-> queue.
 * @content: Line content.
 * @arg: Value.
 *
 * Code by 0xOneBeing
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

extern bus_t bus;

/**
 * struct instruction_s - Opcode and fxn.
 * @opcode: Opcode.
 * @f: Fxn to handle opcode.
 *
 * Code by 0xOneBeing
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

ssize_t getstdin(char **lineptr, int file);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
char *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
void f_pop(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

#endif /* CUSTOMHEADER_H */
