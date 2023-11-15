#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_linkd - doubly linked list representation of a stack or queue
 * @n: integer
 * @prv: points to the previous element of the stack queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX SE project
 */
typedef struct stack_linkd
{
        int n;
        struct stack_linkd *prv;
        struct stack_linkd *next;
} stack_node;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_node **stack, unsigned int line_number);
} instruction_t;

extern stack_node *head;
typedef void (*op_func)(stack_node **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_node *make_node(int n);
void releas_nodes(void);
void print_stack(stack_node **, unsigned int);
void add_to_stack(stack_node **, unsigned int);
void insert_to_queue(stack_node **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void print_top(stack_node **, unsigned int);
void pop_top(stack_node **, unsigned int);
void nop(stack_node **, unsigned int);
void swap_nodes(stack_node **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_node **, unsigned int);
void sub_nodes(stack_node **, unsigned int);
void div_nodes(stack_node **, unsigned int);
void mul_nodes(stack_node **, unsigned int);
void mod_nodes(stack_node **, unsigned int);

/*String operations*/
void print_char(stack_node **, unsigned int);
void print_str(stack_node **, unsigned int);
void rotl(stack_node **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_node **, unsigned int);

#endif
