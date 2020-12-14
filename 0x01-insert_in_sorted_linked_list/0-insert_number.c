#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - inserts a number into a sorted linked list
 *
 *@head: head of the list
 *@number: int number to insert
 *
 * Return: Address of the new node or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *next = *head;
	listint_t *prev, *new;

	new = (void *)malloc(sizeof(listint_t));
	if (*head == NULL)
	{
		new->next = NULL;
		new->n = number;
		*head = new;
		return (*head);
	}


	prev = *head;
	while (number > next->n)
	{
		prev = next;
		if (next->next == NULL)
		{
			next = NULL;
			break;
		}
		next = next->next;
	}

	if (prev == *head && prev->n > number)
	{
		next = *head;
		new->next = next;
		new->n = number;
		*head = new;
		return (*head);
	}

	new->n = number;
	prev->next = new;
	new->next = next;

	return (new);
}
