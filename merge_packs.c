/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_packs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 04:44:23 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 10:52:55 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_pack_to_a(t_ps_state *state, size_t size_a, size_t size_b)
{
	t_stack		*packlist_a;
	t_stack		*packlist_b;
	t_node		*moved_pack;

	packlist_a = state->a.packs;
	packlist_b = state->b.packs;
	packlist_a->top = packlist_a->top->prev;
	moved_pack = stack_pop(packlist_b);
	packlist_a->top->rank += moved_pack->rank;
	free(moved_pack);
	while (size_a > 0)
	{
		op_rra(state);
		size_a--;
	}
	while (size_b > 0)
	{
		op_pa(state);
		size_b--;
	}
}

void	merge_pack_to_a(t_ps_state *state)
{
	size_t		size_a;
	size_t		size_b;

	size_a = state->a.packs->top->prev->rank;
	size_b = state->b.packs->top->rank;
	while (size_a > 0 && size_b > 0)
	{
		if (state->a.top->prev->value < state->b.top->value)
		{
			op_pa(state);
			size_b--;
		}
		else
		{
			op_rra(state);
			size_a--;
		}
	}
	put_pack_to_a(state, size_a, size_b);
}

static void	put_pack_to_b(t_ps_state *state, size_t size_a, size_t size_b)
{
	t_stack		*packlist_a;
	t_stack		*packlist_b;
	t_node		*moved_pack;

	packlist_a = state->a.packs;
	packlist_b = state->b.packs;
	packlist_b->top = packlist_b->top->prev;
	moved_pack = stack_pop(packlist_a);
	packlist_b->top->rank += moved_pack->rank;
	free(moved_pack);
	while (size_a > 0)
	{
		op_pb(state);
		size_a--;
	}
	while (size_b > 0)
	{
		op_rrb(state);
		size_b--;
	}
}

void	merge_pack_to_b(t_ps_state *state)
{
	size_t		size_a;
	size_t		size_b;

	size_a = state->a.packs->top->rank;
	size_b = state->b.packs->top->prev->rank;
	while (size_a > 0 && size_b > 0)
	{
		if (state->b.top->prev->value < state->a.top->value)
		{
			op_rrb(state);
			size_b--;
		}
		else
		{
			op_pb(state);
			size_a--;
		}
	}
	put_pack_to_b(state, size_a, size_b);
}

void	merge_packs(t_ps_state *state)
{
	size_t		nb_packs;
	void		(*merge_function)(t_ps_state *);

	merge_function = merge_pack_to_a;
	nb_packs = state->a.packs->size;
	if (state->a.packs->size > state->b.packs->size)
	{
		merge_function = merge_pack_to_b;
		nb_packs = state->b.packs->size;
	}
	while (nb_packs > 0)
	{
		merge_function(state);
		nb_packs--;
	}
}
