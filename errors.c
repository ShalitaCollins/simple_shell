#include "main.h"


void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}


int _eputchar(char e)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}


int _putfd(char e, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}


int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
