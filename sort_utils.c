/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:30:00 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/08 19:30:00 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorted_values(t_ps_state *state)
{
	int		*values;
	t_node	*node;
	size_t	i;
	size_t	j;

	values = malloc(sizeof(int) * state->a.size);
	if (!values)
		freexit(state);
	node = state->a.top;
	i = 0;
	while (i < state->a.size)
	{
		j = i;
		while (j > 0 && values[j - 1] > node->value)
		{
			values[j] = values[j - 1];
			j--;
		}
		values[j] = node->value;
		node = node->next;
		i++;
	}
	return (values);
}
