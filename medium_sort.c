/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:58:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 06:15:23 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pack_utils/packing.h"

t_stack	*new_packlist(void)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (result == NULL)
		return (NULL);
	result->size = 0;
	result->top = NULL;
	result->packs = NULL;
	return (result);
}

void	medium_sort(t_ps_state *state, t_nop *nop)
{
	(void) nop;
	state->a.packs = new_packlist();
	state->b.packs = new_packlist();
	if (state->a.packs == NULL || state->b.packs == NULL)
		freexit(state);
	while ((state->a).size > 6)
		make_pack(STACK_B, 6, state);
}
