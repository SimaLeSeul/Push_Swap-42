/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:49 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/06 14:55:50 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	append_number(int value, t_ps_state *state)
{
	t_node	*node;

	if (contains_value(&state->a, value) == 1)
		freexit(state);
	node = node_new(value);
	if (!node)
		freexit(state);
	stack_append(&state->a, node);
}

size_t	argtoint(const char *s, t_ps_state *state)
{
	size_t	i;
	size_t	len;
	size_t	old_count;

	if (!s || !state)
		freexit(state);
	i = 0;
	old_count = state->a.size;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i]) == 1)
			i++;
		if (s[i])
		{
			len = number_len(s + i, state);
			append_number(ft_atoi(s + i), state);
			i += len;
		}
	}
	if (state->a.size == old_count)
		freexit(state);
	return (state->a.size);
}
