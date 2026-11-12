/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:36:46 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 00:58:59 by jecourto         ###   ########.fr       */
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
	ft_printf("ra\n");
	state->nop.ra++;
}

void	op_rb(t_ps_state *state)
{
	stack_rotate(&state->b);
	ft_printf("rb\n");
	state->nop.rb++;
}

void	op_rr(t_ps_state *state)
{
	stack_rotate(&state->a);
	stack_rotate(&state->b);
	ft_printf("rr\n");
	state->nop.rr++;
}
