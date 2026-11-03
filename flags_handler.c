#include "push_swap.h"

static int	strings_equal(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	is_known_flag(const char *s)
{
	if (strings_equal(s, "simple") == 1 || strings_equal(s, "medium") == 1
		|| strings_equal(s, "complex") == 1
		|| strings_equal(s, "adaptive") == 1
		|| strings_equal(s, "bench") == 1)
		return (1);
	return (0);
}

void	flags_handler(const char *s)
{
	char	**flags;
	size_t	i;

	flags = flags_parser(s);
	i = 0;
	while (flags[i])
	{
		if (is_known_flag(flags[i]) == 0)
		{
			free_flags(flags);
			freexit(NULL);
		}
		i++;
	}
	free_flags(flags);
}
