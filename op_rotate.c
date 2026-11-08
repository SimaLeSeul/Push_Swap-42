/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:36:46 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/08 19:19:29 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack->top = stack->top->next;
}

void	op_ra(t_ps_state *state, int flag)
{
	stack_rotate(&state->a);
	if (flag == 0)
		ft_printf("ra\n");
}

void	op_rb(t_ps_state *state, int flag)
{
	stack_rotate(&state->b);
	if (flag == 0)
		ft_printf("rb\n");
}

void	op_rr(t_ps_state *state)
{
	op_ra(state, 1);
	op_rb(state, 1);
	ft_printf("rr\n");
}
