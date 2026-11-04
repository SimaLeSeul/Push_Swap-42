/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:47:45 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:52:36 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ps_state state)
{
	int		i;
	int		last;

	if (state.pa <= 1)
		return ;
	i = state.pa - 1;
	last = state.a[state.pa - 1];
	while (i > 0)
	{
		state.a[i] = state.a[i - 1];
		i--;
	}
	state.a[0] = last;
}

void	op_rrb(t_ps_state state)
{
	int		i;
	int		last;

	if (state.pb <= 1)
		return ;
	i = state.pb - 1;
	last = state.b[state.pb - 1];
	while (i > 0)
	{
		state.b[i] = state.b[i - 1];
		i--;
	}
	state.b[0] = last;
}

void	op_rrr(t_ps_state state)
{
	op_rra(state);
	op_rrb(state);
}
