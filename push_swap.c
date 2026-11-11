/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:53 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/11 06:08:48 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_state	*str_to_list(void)
{
	t_ps_state	*state;

	state = malloc(sizeof(t_ps_state));
	if (!state)
		return (NULL);
	state->a.top = NULL;
	state->a.packs = NULL;
	state->a.size = 0;
	state->b.top = NULL;
	state->b.packs = NULL;
	state->b.size = 0;
	state->strategy = ADAPTIVE;
	state->bench = 0;
	return (state);
}

void	free_state(t_ps_state *state)
{
	if (state)
	{
		stack_clear(&state->a);
		stack_clear(&state->b);
		free(state);
	}
}

void	freexit(t_ps_state *state)
{
	free_state(state);
	write(2, "Error\n", 6);
	exit(1);
}
