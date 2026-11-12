/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 00:08:15 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/11 01:00:14 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_min_position(t_stack *stack)
{
	size_t	i;
	int		min;
	size_t	min_pos;
	t_node	*node;

	if (!stack || stack->size == 0)
		return (0);
	i = 0;
	node = stack->top;
	min = node->value;
	min_pos = 0;
	while (i < stack->size)
	{
		if (min > node->value)
		{
			min = node->value;
			min_pos = i;
		}
		i++;
		node = node->next;
	}
	return (min_pos);
}

void	put_min_first(t_ps_state *state)
{
	size_t	min_pos;
	size_t	i;
	size_t	count;

	if (!state)
		freexit(state);
	if (state->a.size == 0)
		return ;
	i = 0;
	min_pos = find_min_position(&state->a);
	if (min_pos <= state->a.size / 2)
	{
		count = min_pos;
		while (i++ < count)
			op_ra(state);
	}
	else
	{
		count = state->a.size - min_pos;
		while (i++ < count)
			op_rra(state);
	}
}

int	stack_is_sorted(const t_stack *stack)
{
	t_node	*node;
	size_t	i;

	node = stack->top;
	i = 1;
	while (i < stack->size)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

void	simple_sort(t_ps_state *state)
{
	if (!state)
		freexit(state);
	if (state->b.size == 0 && stack_is_sorted(&state->a) == 1)
		return ;
	while (state->a.size > 0)
	{
		put_min_first(state);
		op_pb(state);
	}
	while (state->b.size > 0)
	{
		op_pa(state);
	}
}
