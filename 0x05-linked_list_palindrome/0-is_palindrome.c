#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a linked list of integers is a palindrome
 *
 *@head: head node of the linked list
 *
 * Return: true | false
 */

int is_palindrome(listint_t **head)
{
	int length = get_length(head);
	int start = 0, end = length - 1;
	int *list;

	if (length == 0)
		return (true);

	list = malloc(sizeof(int) * length);
	build_list(list, head);

	for (; start < end; start++, end--)
	{
		if (list[start] != list[end])
		{
			free(list);
			return (false);
		}
	}

	free(list);
	return (true);
}

/**
 * get_length - gets the length of a listint_t linked list
 *@head: head node of the linked list
 *
 * Return: Length of the list as an integer
 */

int get_length(listint_t **head)
{
	int length;
	listint_t *temp = *head;

	if (temp == NULL)
		return (0);

	for (length = 0; temp != NULL; length++)
	{
		temp = temp->next;
	}
	return (length);
}

/**
 * build_list - build an array of integers from a listint_t linked list
 *@list: array of integers to populate
 *@head: head node of the linked list
 */

void build_list(int *list, listint_t **head)
{
	listint_t *temp = *head;
	int index;

	for (index = 0; temp != NULL; index++)
	{
		list[index] = temp->n;
		temp = temp->next;
	}
}
