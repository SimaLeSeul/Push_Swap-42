#include "push_swap.h"

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	contains_value(int *tab, size_t count, int value)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (tab[i] == value)
			return (1);
		i++;
	}
	return (0);
}
