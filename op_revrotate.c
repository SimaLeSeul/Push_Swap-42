/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:47:45 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:52:36 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack->top = stack->top->prev;
}

void	op_rra(t_ps_state *state)
{
	stack_rotate(&state->a);
}

void	op_rrb(t_ps_state *state)
{
	stack_rotate(&state->b);
}

void	op_rrr(t_ps_state *state)
{
	op_rra(state);
	op_rrb(state);
}
