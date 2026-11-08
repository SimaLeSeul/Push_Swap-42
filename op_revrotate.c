/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:47:45 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/08 18:56:53 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack->top = stack->top->prev;
}

void	op_rra(t_ps_state *state, int flag)
{
	stack_rotate(&state->a);
	if (flag == 0)
		ft_printf("rra\n");
}

void	op_rrb(t_ps_state *state, int flag)
{
	stack_rotate(&state->b);
	if (flag == 0)
		ft_printf("rrb\n");
}

void	op_rrr(t_ps_state *state)
{
	op_rra(state, 1);
	op_rrb(state, 1);
	ft_printf("rrr\n");
}
