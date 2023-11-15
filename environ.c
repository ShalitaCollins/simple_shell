#include "main.h"


int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}


char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *a;

	while (node)
	{
		a = starts_with(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}


int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


int _myunsetenv(info_t *info)
{
	int q;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (q = 1; q <= info->argc; q++)
		_unsetenv(info, info->argv[q]);

	return (0);
}


int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t q;

	for (q = 0; environ[q]; q++)
		add_node_end(&node, environ[q], 0);
	info->env = node;
	return (0);
}
