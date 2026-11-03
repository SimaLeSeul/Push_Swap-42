#include "push_swap.h"

static int	fits_in_int(const char *s, size_t len, int sign)
{
	const char	*limit;
	size_t		i;

	limit = "2147483647";
	if (sign == 1)
		limit = "2147483648";
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	i = 0;
	while (i < len && s[i] == limit[i])
		i++;
	if (i == len || s[i] < limit[i])
		return (1);
	return (0);
}

static size_t	number_len(const char *s, t_ps_state *state)
{
	size_t	i;
	size_t	start;
	int		sign;

	i = 0;
	sign = 0;
	if (s[i] == '-')
		sign = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		freexit(state);
	while (s[i] == '0')
		i++;
	start = i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (fits_in_int(s + start, i - start, sign) == 0)
		freexit(state);
	if (s[i] && is_whitespace(s[i]) == 0)
		freexit(state);
	return (i);
}

static void	append_number(int *res, size_t count, int value,
		t_ps_state *state)
{
	if (count == state->tlen)
		freexit(state);
	if (contains_value(res, count, value) == 1)
		freexit(state);
	res[count] = value;
}

size_t	argtoint(const char *s, int *res, t_ps_state *state, size_t count)
{
	size_t	i;
	size_t	len;
	size_t	old_count;

	if (!s || !state || !res || count > state->tlen)
		freexit(state);
	i = 0;
	old_count = count;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]) == 1)
			i++;
		if (s[i])
		{
			len = number_len(s + i, state);
			append_number(res, count, ft_atoi(s + i), state);
			count++;
			i += len;
		}
	}
	if (count == old_count)
		freexit(state);
	return (count);
}
