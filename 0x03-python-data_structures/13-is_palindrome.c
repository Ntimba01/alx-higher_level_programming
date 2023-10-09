#include "lists.h"

/*
 * palindrome - check if is palindrome with recursion
 *
 */

listint_t *reverse_listint(listint_t **head);
int is_palindrome(listint_t **head);

/*
 * reverse_listint - A singly-linked listint_t list.
 * @head: A starting node of the list to reverse.
 *
 * Return: To the head of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *node = *head, *next, *prev = NULL;

	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	*head = prev;
	return (*head);
}

/*
 * is_palindrome - Checks if a singly-linked list if is a palindrome.
 * @head: The head of the linked list.
 *
 * Return: The list is not a palindrome (0)
 *         The list is a palindrome (1)
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp, *rev, *mid;
	size_t size = 0, i;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	tmp = *head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}

	tmp = *head;
	for (i = 0; i < (size / 2) - 1; i++)
		tmp = tmp->next;

	if ((size % 2) == 0 && tmp->n != tmp->next->n)
		return (0);

	tmp = tmp->next->next;
	rev = reverse_listint(&tmp);
	mid = rev;

	tmp = *head;
	while (rev)
	{
		if (tmp->n != rev->n)
			return (0);
		tmp = tmp->next;
		rev = rev->next;
	}
	reverse_listint(&mid);

	return (1);
}
