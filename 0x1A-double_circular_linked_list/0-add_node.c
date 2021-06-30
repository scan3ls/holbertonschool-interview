#include "list.h"

/**
 * add_node_end - add a node to the end of List list
 *@list: head node of type List
 *@str: value stored in List node
 *
 * Return: new node created
 */

List *add_node_end(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));
	List *old_end;

	if (!list || !new_node)
		return (NULL);

	new_node->str = copy(str);
	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;

		*list = new_node;
		return (new_node);
	}

	old_end = (*list)->prev;
	old_end->next = new_node;
	(*list)->prev = new_node;

	new_node->prev = old_end;
	new_node->next = (*list);

	return (new_node);
}

/**
 * add_node_begin - add a node to the begin of List list
 *@list: head node of type List
 *@str: value stored in List node
 *
 * Return: head of the list
 */

List *add_node_begin(List **list, char *str)
{
	List *new_node = malloc(sizeof(List));

	if (!list || !new_node)
		return (NULL);

	new_node->str = copy(str);
	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = (*list);

		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	*list = new_node;
	return (new_node);
}

/**
 * copy - copy a string
 *@str: source string to copy
 *
 * Return: copy of str
 */
char *copy(char *str)
{
	int length, i;
	char *str_copy;

	for (length = 0; str[length] != '\0'; length++)
		;

	str_copy = malloc(sizeof(char) * length);
	for (i = 0; i < length; i++)
		str_copy[i] = str[i];

	return (str_copy);
}
