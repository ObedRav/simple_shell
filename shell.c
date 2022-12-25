#include "shell.h"

/**
 * _EOF - handles the End of File
 * @len: return value of getline function
 * @buff: buffer
 */
void _EOF(int len, __attribute__((unused))char *buff)
{
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - verif if is interactive
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_puts("\n$ ");
}

/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
	int bytes_read = 0; /*Declarations*/
	char *string = NULL, *value = NULL, *pathname = NULL, **arv = NULL;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **) = NULL; /* Declare the store of the func*/

	signal(SIGINT, sig_handler); /*Signal be sure tat the user press the ctrl+c*/
	while (1) /*Starting the infinitive loop*/
	{
		_isatty(); /*Check if the input is interative or not interative*/
		fflush(stdin);
		bytes_read = getline(&string, &size, stdin); /*Read the line from user*/
		_EOF(bytes_read, string); /*If an error occured the program finish*/
		arv = splitstring(string, " \n"); /*Split the string into an array*/
		if (arv[0])
		{
			value = _getenv("PATH"); /*Obtain the value from the environment variable*/
			head = linkpath(value); /*Create an linked list of the path directories*/
			pathname = _which(arv[0], head); /*Search if the command exits in paths*/
			free_list(head); /*Free the linked list*/
			f = checkbuild(arv); /*Check if the command is an buildin*/
			if (f) /*If the command is an buildin free the input*/
			{
				f(arv); /*from user and run the buildin*/
			}
			if (pathname) /*If the _which find the executable in the paths, */
			{					/*free the space in memory of the command*/
				free(arv[0]);	/*and replace with the path to an success executation*/
				arv[0] = pathname;
			}
			execute(arv);
		}
		else
			freearv(arv);
	}
	free_list(head);
	freearv(arv);
	free(string);
	return (0);
}
