/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:11:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:35:47 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_ps_state state)
{
	int		tmp;

	if (state.pa <= 1)
		return ;
	tmp = state.a[0];
	state.a[0] = state.a[1];
	state.a[1] = tmp;
}

void	op_sb(t_ps_state state)
{
	int		tmp;

	if (state.pb <= 1)
		return ;
	tmp = state.b[0];
	state.b[0] = state.b[1];
	state.b[1] = tmp;
}

void	op_ss(t_ps_state state)
{
	op_sa(state);
	op_sb(state);
}
