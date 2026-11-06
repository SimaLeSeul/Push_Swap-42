/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:11:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:35:47 by jecourto         ###   ########.fr       */
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
}

void	op_sb(t_ps_state *state)
{
	stack_swap(&state->b);
}

void	op_ss(t_ps_state *state)
{
	op_sa(state);
	op_sb(state);
}
