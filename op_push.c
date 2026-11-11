/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:23:22 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 08:17:13 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_pop(t_stack *source)
{
	t_node	*node;

	node = source->top;
	if (node == NULL)
		return (NULL);
	if (source->size == 1)
		source->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		source->top = node->next;
	}
	source->size--;
	return (node);
}

static void	stack_push(t_stack *source, t_stack *destination)
{
	t_node	*node;

	node = stack_pop(source);
	if (node == NULL)
		return ;
	stack_append(destination, node);
	destination->top = node;
}

void	op_pa(t_ps_state *state)
{
	stack_push(&state->b, &state->a);
	ft_printf("pa\n");
}

void	op_pb(t_ps_state *state)
{
	stack_push(&state->a, &state->b);
	ft_printf("pb\n");
}
