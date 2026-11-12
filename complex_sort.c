/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:53:17 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/11 01:00:36 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rank(t_stack *stack)
{
	size_t	len;
	size_t	i;
	size_t	rank;
	t_node	*tmp;
	t_node	*tmp2;

	len = stack->size;
	tmp = stack->top;
	i = 0;
	while (i < len)
	{
		rank = 0;
		tmp2 = stack->top;
		while (len > 0)
		{
			if (tmp2->value < tmp->value)
				rank++;
			tmp2 = tmp2->next;
			len--;
		}
		len = stack->size;
		tmp->rank = rank;
		tmp = tmp->next;
		i++;
	}
}

static size_t	count_bits(size_t max)
{
	size_t	bits;

	bits = 0;
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

static void	distribute_bit(t_ps_state *state, size_t bit)
{
	size_t	rest;

	rest = state->a.size;
	while (rest > 0)
	{
		if (((state->a.top->rank >> bit) & 1) == 0)
			op_pb(state);
		else
			op_ra(state);
		rest--;
	}
}

static void	restore_a(t_ps_state *state)
{
	while (state->b.size > 0)
		op_pa(state);
}

void	complex_sort(t_ps_state *state)
{
	size_t	bit;
	size_t	bits;

	if (state->a.size < 2)
		return ;
	if (state->b.size == 0 && stack_is_sorted(&state->a) == 1)
		return ;
	set_rank(&state->a);
	bits = count_bits(state->a.size - 1);
	bit = 0;
	while (bit < bits)
	{
		distribute_bit(state, bit);
		restore_a(state);
		bit++;
	}
}
