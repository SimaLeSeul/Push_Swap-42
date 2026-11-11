/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:11:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 01:01:36 by jecourto         ###   ########.fr       */
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

void	op_sa(t_ps_state *state)
{
	stack_swap(&state->a);
	ft_printf("sa\n");
}

void	op_sb(t_ps_state *state)
{
	stack_swap(&state->b);
	ft_printf("sb\n");
}

void	op_ss(t_ps_state *state)
{
	stack_swap(&state->a);
	stack_swap(&state->b);
	ft_printf("ss\n");
}
