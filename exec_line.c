#include "shell.h"

/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **splitstring(char *str, const char *delim)
{
	int i = 0, wn = 0; /* declared variables */
	char **array = NULL;
	char *token = NULL;
	char *copy = NULL;

	copy = _calloc((_strlen(str) + 1), 1); /* allocate the space in */
	if (!copy)					/*memory of the string received */
	{
		perror(_getenv("_"));
		return (NULL);
	}
	while (str[i]) /* Copy the string received into anothe variable */
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim); /* Use the strtok to tokenize the string */
	array = _calloc((sizeof(char *)), 1); /* Allocate memory for the array */
	array[0] = _strdup(token); /* Copy the pointer of token into array */

	i = 1; /* index */
	wn = 2; /* variable to reallocate the memory */
	while (token) /* Start the loop while token exits */
	{
		token = strtok(NULL, delim); /* Skip to the next token */
		array = _realloc(array, (sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[i] = _strdup(token); /* Copy the pointer of token into array */
		i++;
		wn++;
	}
	free(copy); /* Free allocated memory */
	return (array);
}

/**
 * _calloc - allocates memory using malloc, and initializes it to zero
 * @size: size of the memory block to be allocated
 * @nmemb: number of elements
 *
 * Return: pointer to the address of the memory block
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *block = NULL;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);
	block = malloc(nmemb * size);
	if (block)
	{
		for (i = 0; i < (nmemb * size); i++)
			block[i] = 0;
		return (block);
	}
	else
		return (NULL);
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new = NULL;
	char *old = NULL;

	unsigned int i;

	if (!ptr)
		return (_calloc(new_size, 1));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	new = _calloc(new_size, 1);
	old = ptr;
	if (!new)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * execute - executes a command
 * @arv: array of arguments
 */
void execute(char **arv)
{
	int d = 0, status; /* declared variables */

	if (!arv || !arv[0])
		return;
	d = fork(); /* fork the process */
	if (d == -1) /* if the fork failed error*/
	{
		perror(_getenv("_"));
	}
	if (d == 0) /* if the fork succeeded execute the command */
	{
		execve(arv[0], arv, environ); /* replace the child process */
			perror(arv[0]); /* if the execve failed error and exit*/
		exit(EXIT_FAILURE);
	}
	freearv(arv);
	wait(&status);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */
void freearv(char **arv)
{
	int i = 0;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
