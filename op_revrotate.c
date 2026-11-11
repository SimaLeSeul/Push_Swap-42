/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:47:45 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 00:58:51 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_revrotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack->top = stack->top->prev;
}

void	op_rra(t_ps_state *state)
{
	stack_revrotate(&state->a);
	ft_printf("rra\n");
}

void	op_rrb(t_ps_state *state)
{
	stack_revrotate(&state->b);
	ft_printf("rrb\n");
}

void	op_rrr(t_ps_state *state)
{
	stack_revrotate(&state->a);
	stack_revrotate(&state->b);
	ft_printf("rrr\n");
}
