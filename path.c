#include "shell.h"

/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int i = 0, j = 0; /* declared variables */
	char *value = NULL;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++) /* loop through the environment variable */
	{
		if (name[j] == environ[i][j]) /* check the first digit */
		{
			while (name[j])
			{
				if (name[j] != environ[i][j]) /* if the digits are different */
					break;

				j++;
			}
			if (name[j] == '\0') /* if the digits are equals */
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *add_node_end(list_path **head, char *str)
{
	list_path *tmp = NULL;
	list_path *new = NULL;

	new = _calloc((sizeof(list_path)), 1);

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}

/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0'; /* declared variables */
	char *token = NULL;
	char *cpath = _strdup(path); /* copy the path */

	token = strtok(cpath, ":"); /* divide the path in tokens */
	while (token)
	{
		head = add_node_end(&head, token); /* assign the path */
		token = strtok(NULL, ":"); /* next token */
	}
	return (head);
}

/**
 * _which - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *_which(char *filename, list_path *head)
{
	/* declared variables */
	struct stat st;
	char *string = NULL;

	list_path *tmp = head; /* create a copy of head */

	while (tmp) /* loop through list of paths */
	{

		string = concat_all(tmp->dir, "/", filename); /* possible executables */
		if (stat(string, &st) == 0)
		/* The stat() function shall continue pathname */
		/* resolution using the contents of string, and shall return */
		/* information pertaining to the resulting file if the file exists */
		{
			return (string);
		}
		free(string);
		tmp = tmp->p; /* next node */
	}

	return (NULL);
}

/**
 * free_list -  function that frees a linked list.
 * @head: the head of the linked lint
 * Return: nothing
 */
void free_list(list_path *head)
{
	list_path *actual;

	if (!head)
		return;

	while (head->p)
	{
		actual = head->p;
		free(head);
		head = actual;
	}
	free(head);
}
