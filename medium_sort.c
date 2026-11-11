/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:58:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 03:16:06 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pack_utils/packing.h"

void	medium_sort(t_ps_state *state, t_nop *nop)
{
	(void) nop;
	while ((state->a).size > 6)
		make_pack(STACK_B, 6, state);
}
