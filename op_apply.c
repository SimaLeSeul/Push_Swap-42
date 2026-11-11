/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:51:01 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 01:24:32 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_apply(t_ps_state *state, char *op)
{
	if (strings_equal(op, "sa"))
		op_sa(state);
	else if (strings_equal(op, "sb"))
		op_sb(state);
	else if (strings_equal(op, "pa"))
		op_pa(state);
	else if (strings_equal(op, "pb"))
		op_pb(state);
	else if (strings_equal(op, "ra"))
		op_ra(state);
	else if (strings_equal(op, "rb"))
		op_rb(state);
	else if (strings_equal(op, "rr"))
		op_rr(state);
	else if (strings_equal(op, "rra"))
		op_rra(state);
	else if (strings_equal(op, "rrb"))
		op_rrb(state);
	else if (strings_equal(op, "rrr"))
		op_rrr(state);
	else
		ft_putendl_fd("Warning: op_apply invalid operator", 2);
}

void	op_apply_list(t_ps_state *state, char **ops)
{
	int		i;

	if (ops == NULL)
		return (ft_putendl_fd("Warning: op_apply_list NULL", 2));
	i = 0;
	while (ops[i] != NULL)
	{
		op_apply(state, ops[i]);
		free(ops[i]);
		i++;
	}
	free(ops);
}
