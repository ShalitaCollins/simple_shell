#include "main.h"


int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}


int unset_alias(info_t *info, char *str)
{
	char *d, c;
	int ret;

	d = _strchr(str, '=');
	if (!d)
		return (1);
	c = *d;
	*d = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*d = c;
	return (ret);
}


int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}


int print_alias(list_t *node)
{
	char *z = NULL, *a = NULL;

	if (node)
	{
		z = _strchr(node->str, '=');
		for (a = node->str; a <= z; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(z + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

int _myalias(info_t *info)
{
	int x = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		b = _strchr(info->argv[x], '=');
		if (b)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}
