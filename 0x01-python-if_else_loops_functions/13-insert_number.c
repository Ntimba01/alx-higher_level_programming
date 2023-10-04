#include "lists.h"

/**
 * insert_node - Inserts node in a sorted singly-linked list.
 * @head: the linked list.
 * @number: The number to insert.
 *
 * Return: NULL if the function fails
 * Otherwise - a pointer to the address of a  new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}

	while (node && node->next && node->next->n < number)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}

