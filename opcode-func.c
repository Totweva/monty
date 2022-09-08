#include "monty.h"


/**
 * monty_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (var.arg)
	{
		if (var.arg[0] == '-')
			j++;
		for (; var.arg[j] != '\0'; j++)
		{
			if (var.arg[j] > 57 || var.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(var.file);
			free(var.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(var.file);
		free(var.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(var.arg);
	if (var.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}


/**
 * monty_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void monty_pall(stack_t **head, unsigned int counter)
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
 * monty_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(var.file);
		free(var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * monty_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(var.file);
		free(var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}


/**
 * monty_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void monty_swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(var.file);
		free(var.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
