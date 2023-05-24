#include "shell.h"

t_alias *add_alias_end(t_alias **head, char *name, char *value);
void free_alias_list(t_alias *head);
t_list *add_node_end(t_list **head, char *dir);
void free_list(t_list *head);

/**
 * add_alias_end - Adds a node to the end of a t_alias linked list.
 * @head: A pointer to the head of the t_list list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
t_alias *add_alias_end(t_alias **head, char *name, char *value)
{
	t_alias *new_node = malloc(sizeof(t_alias));
	t_alias *last;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * add_node_end - Adds a node to the end of a t_list linked list.
 * @head: A pointer to the head of the t_list list.
 * @dir: The directory path for the new node to contain.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
t_list *add_node_end(t_list **head, char *dir)
{
	t_list *new_node = malloc(sizeof(t_list));
	t_list *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * free_alias_list - Frees a alias_t linked list.
 * @head: THe head of the alias_t list.
 */
void free_alias_list(t_alias *head)
{
	t_alias *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_list - Frees a t_list linked list.
 * @head: The head of the t_list list.
 */
void free_list(t_list *head)
{
	t_list *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}