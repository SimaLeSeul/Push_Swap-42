/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:58:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 02:42:31 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pack_utils/packing.h"

void	medium_sort(t_ps_state *state, t_nop *nop)
{
	op_ss(state);
	op_apply(state, "pa");
	op_apply_list(state, ft_split("pb,ra,rb,rr,rra,rrb,rrr", ','));
	make_pack(STACK_B, 6, state);
	make_pack(STACK_A, 4, state);
	nop->pa++;
	nop->ss++;
}
