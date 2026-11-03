#include "push_swap.h"

void	free_flags(char **flags)
{
	size_t	i;

	i = 0;
	while (flags[i])
	{
		free(flags[i]);
		i++;
	}
	free(flags);
}

static char	*copy_flag(const char *s, size_t len, char **flags)
{
	char	*res;
	size_t	i;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
	{
		free_flags(flags);
		freexit(NULL);
	}
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	count_words(const char *s)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]) == 1)
			i++;
		if (s[i])
		{
			w++;
			while (s[i] && is_whitespace(s[i]) == 0)
				i++;
		}
	}
	return (w);
}

static void	fill_flags(char **res, const char *s)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	res[0] = NULL;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]) == 1)
			i++;
		len = 0;
		while (s[i + len] && is_whitespace(s[i + len]) == 0)
			len++;
		if (len >= 2 && s[i] == '-' && s[i + 1] == '-')
		{
			res[j] = copy_flag(s + i + 2, len - 2, res);
			j++;
			res[j] = NULL;
		}
		i += len;
	}
}

char	**flags_parser(const char *s)
{
	char	**res;

	if (!s)
		freexit(NULL);
	res = malloc((count_words(s) + 1) * sizeof(char *));
	if (!res)
		freexit(NULL);
	fill_flags(res, s);
	return (res);
}
