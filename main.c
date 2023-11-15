#include "monty.h"
stack_node *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	releas_nodes();
	return (0);
}

/**
 * make_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_node *make_node(int n)
{
	stack_node *node;

	node = malloc(sizeof(stack_node));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prv = NULL;
	node->n = n;
	return (node);
}

/**
 * releas_nodes - Fr nodes in the stack.
 */
void releas_nodes(void)
{
	stack_node *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * insert_to_queue -Insert a node to the queue.
 * @point_new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void insert_to_queue(stack_node **point_new_node, __attribute__((unused))unsigned int ln)
{
	stack_node *tmp;

	if (point_new_node == NULL || *point_new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *point_new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *point_new_node;
	(*point_new_node)->prv = tmp;

}
