/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:23:22 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:57:09 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_ps_state state)
{
	size_t		i;

	if (state.pa == 0)
		return ;
	i = state.pb;
	while (i > 0)
	{
		state.b[i] = state.b[i - 1];
		i--;
	}
	state.b[0] = state.a[0];
	while (i < state.pa - 1)
	{
		state.a[i] = state.a[i + 1];
		i++;
	}
	state.a[state.pa - 1] = -1;
	state.pa--;
	state.pb++;
}

void	op_pb(t_ps_state state)
{
	size_t		i;

	if (state.pb == 0)
		return ;
	i = state.pa;
	while (i > 0)
	{
		state.a[i] = state.a[i - 1];
		i--;
	}
	state.a[0] = state.b[0];
	while (i < state.pb - 1)
	{
		state.b[i] = state.b[i + 1];
		i++;
	}
	state.b[state.pb - 1] = -1;
	state.pb--;
	state.pa++;
}
