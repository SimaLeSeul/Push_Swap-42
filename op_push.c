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

static void	stack_push(t_stack *source, t_stack *destination)
{
	t_node	*node;

	if (source->size == 0)
		return ;
	node = source->top;
	if (source->size == 1)
		source->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		source->top = node->next;
	}
	source->size--;
	stack_append(destination, node);
	destination->top = node;
}

void	op_pa(t_ps_state *state)
{
	stack_push(&state->b, &state->a);
}

void	op_pb(t_ps_state *state)
{
	stack_push(&state->a, &state->b);
}
