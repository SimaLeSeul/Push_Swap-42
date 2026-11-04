/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:36:46 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:53:49 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ps_state state)
{
	size_t		i;
	int			first;

	if (state.pa <= 1)
		return ;
	i = 0;
	first = state.a[0];
	while (i < state.pa - 1)
	{
		state.a[i] = state.a[i + 1];
		i++;
	}
	state.a[state.pa - 1] = first;
}

void	op_rb(t_ps_state state)
{
	size_t		i;
	int			first;

	if (state.pb <= 1)
		return ;
	i = 0;
	first = state.b[0];
	while (i < state.pb - 1)
	{
		state.b[i] = state.b[i + 1];
		i++;
	}
	state.b[state.pb - 1] = first;
}

void	op_rr(t_ps_state state)
{
	op_ra(state);
	op_rb(state);
}
