#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int i = 0, l = 0;
	char *new = NULL;

	if (!str)
		return (NULL);
	for (l = 0; str[l] != '\0';)
		l++;

	new = _calloc((sizeof(char) * l + 1), 1);
	if (!new)
		return (NULL);

	for (i = 0; i < l; i++)
		new[i] = str[i];
	new[l] = str[l];
	return (new);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result = NULL;
	int l1 = 0, l2 = 0, l3 = 0, i = 0, k = 0;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = _calloc((l1 + l2 + l3 + 1), 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - count chars
 * @s: data from user
 * Return: The result
 */
int _strlen(char *s)
{
	int i = 0, length = 0;

	while (s[i++])
	{
		length++;
	}

	return (length);
}

/**
 * _puts - prints a string
 * @str: String
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
