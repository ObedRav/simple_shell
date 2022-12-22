#include "shell.h"

/**
 * _EOF - handles the End of File
 * @len: return value of getline function
 * @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
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
 * _isatty - verif if terminal
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
	{
		printf("\n$ ");
	}
}

/**
 * main - Shell
 * Return: 0 on success
 */
int main(void)
{
	int bytes_read; /*Declarations*/
	char *string = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler); /*Signal be sure tat the user press the ctrl+c*/
	while (bytes_read != EOF) /*Starting the infinitive loop*/
	{
		_isatty(); /*Check if the input is interative or not interative*/
		bytes_read = getline(&string, &size, stdin); /*Read the line from user*/
		_EOF(bytes_read, string); /*If an error occured the program finish*/
		arv = splitstring(string, " \n"); /*Split the string into an array*/
		if (!arv || !arv[0])
			execute(arv); /*Execute the args and return an error*/
		else
		{
			value = _getenv("PATH"); /*Obtain the value from the environment variable*/
			head = linkpath(value); /*Create an linked list of the path directories*/
			pathname = _which(arv[0], head); /*Search if the command exits in paths*/
			f = checkbuild(arv); /*Check if the command is an buildin*/
			if (f) /*If the command is an buildin free the input*/
			{		/*from user and run the buildin*/
				free(string);
				f(arv);
			}
			else if (!pathname) /*If the _which don't found the executable*/
				execute(arv);	/*in the paths, execute the command*/
			else if (pathname) /*If the _which find the executable in the paths, */
			{					/*free the space in memori of the command*/
				free(arv[0]);	/*and replace with the path to an success executation*/
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head); /*Free the linked list*/
	freearv(arv); /*Free the array of input from user*/
	free(string); /*Free the input from user*/
	return (0);
}