/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:33 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/11 00:49:45 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
