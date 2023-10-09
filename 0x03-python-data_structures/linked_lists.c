#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/*
 * print_listint - print elements of a listint_t list current
 * @h: A pointer to head of list
 * Return: number of nodes of listint_t list
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
	printf("%i\n", current->n);
	current = current->next;
	n++;
    }

    return (n);
}

/*
 * add_nodeint_end - at the end of a listint_t list add a new node
 * @head: A pointer to pointer of first node of listint_t list
 * @n: included intiger in a new node
 * Return: address of new elements
 *         NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
	return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
	*head = new;
    else
    {
	while (current->next != NULL)
	    current = current->next;
	current->next = new;
    }

    return (new);
}

/*
 * free_listint - a listint_t list frees
 * @heaad: The pointer to list freed
 * Return: To void
 */

void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
	current = head;
	head = head->next;
	free(current);
    }
}

