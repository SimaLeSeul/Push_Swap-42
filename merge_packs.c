/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_packs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 04:44:23 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 04:51:36 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_pack_to_a(t_ps_state state, size_t size_a, size_t size_b)
{
	while (size_a > 0)
	{
		op_rra(&state);
		size_a--;
	}
	while (size_b > 0)
	{
		op_pa(&state);
		size_b--;
	}
}

void	merge_pack_to_a(t_ps_state state, size_t size_a, size_t size_b)
{
	t_node		*bot_a;
	t_node		*top_b;

	if (size_a > 0)
		bot_a = state.a.top->prev;
	top_b = state.b.top;
	while (size_a > 0 && size_b > 0)
	{
		if (bot_a->value < top_b->value)
		{
			op_pa(&state);
			size_b--;
		}
		else
		{
			op_rra(&state);
			size_a--;
		}
	}
	put_pack_to_a(state, size_a, size_b);
}

static void	put_pack_to_b(t_ps_state state, size_t size_a, size_t size_b)
{
	while (size_a > 0)
	{
		op_pb(&state);
		size_a--;
	}
	while (size_b > 0)
	{
		op_rrb(&state);
		size_b--;
	}
}

void	merge_pack_to_b(t_ps_state state, size_t size_a, size_t size_b)
{
	t_node		*bot_b;
	t_node		*top_a;

	if (size_b > 0)
		bot_b = state.b.top->prev;
	top_a = state.a.top;
	while (size_a > 0 && size_b > 0)
	{
		if (bot_b->value < top_a->value)
		{
			op_rrb(&state);
			size_b--;
		}
		else
		{
			op_pb(&state);
			size_a--;
		}
	}
	put_pack_to_b(state, size_a, size_b);
}
