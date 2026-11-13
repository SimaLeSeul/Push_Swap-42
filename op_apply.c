/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:51:01 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/13 02:34:58 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Apply the given push-swap operator, then return 0.
	Return 1 if the operator is invalid.
*/
int	op_apply(t_ps_state *state, char *op)
{
	if (strings_equal(op, "sa"))
		op_sa(state);
	else if (strings_equal(op, "sb"))
		op_sb(state);
	else if (strings_equal(op, "ss"))
		op_ss(state);
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
		return (1);
	return (0);
}

// Apply and free the given list of push-swap operators.
void	op_apply_list(t_ps_state *state, char **ops)
{
	int		i;
	int		is_error;

	if (ops == NULL)
		return (ft_putendl_fd("Warning: op_apply_list NULL", 2));
	i = 0;
	is_error = 0;
	while (ops[i] != NULL)
	{
		if (!is_error)
			is_error |= op_apply(state, ops[i]);
		free(ops[i]);
		i++;
	}
	free(ops);
	if (is_error)
		freexit(state);
}
