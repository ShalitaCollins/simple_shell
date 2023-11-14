#include "main.h"

/**
 * main -
 * @c:
 * @argv
 * Return: 0
 */

int main(void)
{
	char *prompt = "(myshell)>$ ", *buffer;
	size_t size = 0;
        ssize_t num_chars;
	while(1)
	{
	printf("%s", prompt);
      num_chars = getline(&buffer, &size, stdin);


        if (num_chars == -1)
	{
	  printf("Exit (myshell)> $ ....\n");
          return (-1);
	}	  
	printf("%s\n", buffer);
	}
        free(buffer);
		
	return (0);
}
