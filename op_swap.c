/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:11:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/08 18:57:16 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
}

void	op_sa(t_ps_state *state, int flag)
{
	stack_swap(&state->a);
	if (flag == 0)
		ft_printf("sa\n");
}

void	op_sb(t_ps_state *state, int flag)
{
	stack_swap(&state->b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	op_ss(t_ps_state *state)
{
	op_sa(state, 1);
	op_sb(state, 1);
	ft_printf("ss\n");
}
