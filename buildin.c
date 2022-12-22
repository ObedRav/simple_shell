#include "shell.h"

/**
 * _atoi - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * exitt - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void exitt(char **arv)
{
	int i, n; /* declared variables */

	if (arv[1]) /* check if the user entered the status of exit */
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		freearv(arv);
		exit(n); /* exit with this exact status */
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv); /* free memory */
	exit(0);
}

/**
* checkbuild - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkbuild(char **arv))(char **arv)
{
	int i, j; /* declared variables */
	mybuild T[] = { /* structure of buildings */
		{"exit", exitt},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++) /* loop through the structure */
	{
		j = 0;
		if (T[i].name[j] == arv[0][j]) /* check the first digit */
		{
			for (j = 0; arv[0][j]; j++) /* loop through the input */
			{
				if (T[i].name[j] != arv[0][j]) /* if the digit are different */
					break;						/* break out of loop */
			}
			if (!arv[0][j])	/* if the last digit is '\0' */
				return (T[i].func);
		}
	}
	return (0);
}
