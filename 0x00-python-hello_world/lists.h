#define LISTS_H
#ifndef LISTS_H

#include <stdlib.h>

/*
 * structure listint_s - singly linked lists
 * @n: integer
 * @next: point to the next node
 *
 * Description: singly linked list node structure for holbernschool
 */

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

int check_cycle(listint_t *list);
void free_listint(listint_t *head);
size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);

#endif
