/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:58:14 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/13 00:57:46 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pack_utils/packing.h"

static void	debug(t_ps_state *state)
{
	size_t	i;
	t_node	*node;

	ft_printf("A(%d): ", state->a.size);
	i = 0;
	node = state->a.top;
	while (i < state->a.size)
	{
		ft_printf("%d ", node->value);
		node = node->next;
		i++;
	}
	ft_printf("\nB(%d): ", state->b.size);
	i = 0;
	node = state->b.top;
	while (i < state->b.size)
	{
		ft_printf("%d ", node->value);
		node = node->next;
		i++;
	}
	ft_printf("\nA_packs(%d): ", state->a.packs->size);
	node = state->a.packs->top;
	i = 0;
	while (i < state->a.packs->size)
	{
		ft_printf("%d ", node->rank);
		node = node->next;
		i++;
	}
	ft_printf("\nB_packs(%d): ", state->b.packs->size);
	node = state->b.packs->top;
	i = 0;
	while (i < state->b.packs->size)
	{
		ft_printf("%d ", node->rank);
		node = node->next;
		i++;
	}
	ft_printf("\n");
}

static t_stack	*new_packlist(void)
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

static int	ft_fibonacci(size_t limit, size_t *small)
{
	size_t		a;
	size_t		b;

	a = 1;
	b = 2;
	while (b <= limit)
	{
		b += a;
		a = b - a;
	}
	*small = b - a;
	return (a);
}

static void	pack_a(t_ps_state *state, size_t nb_packs_a, size_t size_a)
{
	size_t	size_pack;

	while (nb_packs_a > 1)
	{
		size_pack = size_a / nb_packs_a;
		if (size_pack * nb_packs_a < size_a)
			size_pack++;
		make_pack(STACK_A, size_pack, state);
		size_a -= size_pack;
		nb_packs_a--;
	}
	make_pack(STACK_A, size_a, state);
}

void	medium_sort(t_ps_state *state)
{
	size_t		nb_packs_a;
	size_t		nb_packs_b;
	size_t		size_packs_b;

	state->a.packs = new_packlist();
	state->b.packs = new_packlist();
	if (state->a.packs == NULL || state->b.packs == NULL)
		freexit(state);
	nb_packs_b = ft_fibonacci(state->a.size / 5, &nb_packs_a);
	size_packs_b = 6;
	while (nb_packs_b > 0)
	{
		debug(state);
		make_pack(STACK_B, size_packs_b, state);
		nb_packs_b--;
		if (state->a.size < 3 * nb_packs_a + size_packs_b * nb_packs_b)
			size_packs_b--;
	}
	debug(state);
	pack_a(state, nb_packs_a, state->a.size);
	while (state->b.packs->size > 0)
	{
		debug(state);
		merge_packs(state);
	}
	if (0)
		debug(state);
}
