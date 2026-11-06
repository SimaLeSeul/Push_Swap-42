/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:36:46 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:53:49 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack->top = stack->top->next;
}

void	op_ra(t_ps_state *state)
{
	stack_rotate(&state->a);
}

void	op_rb(t_ps_state *state)
{
	stack_rotate(&state->b);
}

void	op_rr(t_ps_state *state)
{
	op_ra(state);
	op_rb(state);
}
