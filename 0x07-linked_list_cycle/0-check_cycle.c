#include "lists.h"

/**
 * check_cycle - checks if the listint_t list loops
 *@list: list to check
 *
 * Return: true/false
 */

int check_cycle(listint_t *list)
{
	listint_t *node = list;

	if (node == NULL)
		return (false);

	while (node != NULL)
	{
		if (node->next >= node)
			return (true);

		node = node->next;
	}

	return (false);
}
