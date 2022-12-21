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
int main()
{
        int bytes_read;
        char *string;
	    char *buff = NULL, *value, *pathname, **arv;
	    size_t size = 0;
	    list_path *head = '\0';
	    void (*f)(char **);
        
        signal(SIGINT, sig_handler);

        while (bytes_read != EOF)
        {
                _isatty();
                /* These 2 lines are very important. */
                bytes_read = getline (&string, &size, stdin);
                _EOF(bytes_read, string);
                arv = splitstring(string, " \n");
                if (!arv || !arv[0])
                    execute(arv);
                else
                {
                    value = _getenv("PATH");
                    head = linkpath(value);
                    pathname = _which(arv[0], head);
                    f = checkbuild(arv);
                    if (f)
                    {
                        free(buff);
                        f(arv);
                    }
                    else if (!pathname)
                        execute(arv);
                    else if (pathname)
                    {
                        free(arv[0]);
                        arv[0] = pathname;
                        execute(arv);
                    }
                }
        }
        
        free_list(head);
        freearv(arv);
        free(string);
        return 0;
}
