#include "monty.h"

/**
* add_node - push or enqueue an element at the beginning of the stack
* @head: pointer to dll
* @n: value to add
* Return: pointer to new node or NULL
*/
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;


	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}


/**
* free_stack - free a dll of int
* @head: a pointer to a dll
*/
void free_stack(stack_t *head)
{
	stack_t *tmp;


	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}



/**
* pop_s - return the node at the beginning
* @head: pointer to a dll
* Return: pointer to the node or NULL
*/
stack_t *pop_s(stack_t **head)
{
	stack_t *tmp;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;


	return (tmp);
}


/**
* dequeue - return the node at the end
* @head: pointer to a dll
* Return: pointer to node or NULL
*/
stack_t *dequeue(stack_t **head)
{
	stack_t *h;

	if (!head || !*head)
		return (NULL);

	h = *head;
	while (h->next != NULL)
		h = h->next;

	if (h->prev)
		(h->prev)->next = NULL;
	else
		*head = NULL;

	return (h);
}

/**
* add_node_end - add node at the end of a dll
* @head: pointer to a linked list
* @n: value to insert
* Return: address of node or NULL
*/
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		for (tmp = *head; tmp->next;)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}

