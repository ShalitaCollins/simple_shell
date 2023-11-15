#include "main.h"


char *_strncpy(char *dest, char *src, int q)
{
	int i, j;
	char *z = dest;

	i = 0;
	while (src[i] != '\0' && i < q - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < q)
	{
		j = i;
		while (j < q)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (z);
}


char *_strncat(char *dest, char *src, int q)
{
	int i, j;
	char *z = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < q)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < q)
		dest[i] = '\0';
	return (z);
}


char *_strchr(char *z, char c)
{
	do {
		if (*z == c)
			return (z);
	} while (*z++ != '\0');

	return (NULL);
}
