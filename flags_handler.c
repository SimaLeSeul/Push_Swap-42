/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:33 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/08 17:45:10 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	flags_handler(const char *s, t_ps_state *state)
{
	if (!s || !state)
		freexit(state);
	if (strings_equal(s, "--bench") == 1)
	{
		state->bench = 1;
		return (0);
	}
	if (strings_equal(s, "--simple") == 1)
		state->strategy = SIMPLE;
	else if (strings_equal(s, "--medium") == 1)
		state->strategy = MEDIUM;
	else if (strings_equal(s, "--complex") == 1)
		state->strategy = COMPLEX;
	else if (strings_equal(s, "--adaptive") == 1)
		state->strategy = ADAPTIVE;
	else
		freexit(state);
	return (1);
}
