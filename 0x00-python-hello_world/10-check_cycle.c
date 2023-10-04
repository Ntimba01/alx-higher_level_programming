#include "lists.h"

/*
 * check_cycle - check if a singly linked list contains a cycle
 * @list: a singly linked list to check
 *
 * Return: 1 if there is a list cycle.
 * 	   0 if it doesn't have a list cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fair = list;
	listint_t *wonder = list;

	if (!list)
		return (0);

	while (fair && wonder && wonder->next)
	{
		fair = fair->next;
		wonder = wonder->next->next;
		if (fair == wonder)
			return (1);
	}

	return (0);
}
