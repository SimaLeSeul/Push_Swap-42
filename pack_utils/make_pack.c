/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:22:25 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 03:18:46 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "packing.h"
#include "utils/packing_utils.h"

static char	*make_pack_a(size_t n, char *perm_label)
{
	if (n == 1)
		return ("ra");
	if (n == 2)
		return (make_pack_2a(perm_label));
	if (n == 3)
		return (make_pack_3a(perm_label));
	if (n == 4)
		return (make_pack_4a(perm_label));
	if (n == 5)
		return (make_pack_5a(perm_label));
	return (NULL);
}

static char	*make_pack_b(size_t n, char *perm_label)
{
	if (n == 1)
		return ("pb");
	if (n == 2)
		return (make_pack_2b(perm_label));
	if (n == 3)
		return (make_pack_3b(perm_label));
	if (n == 4)
		return (make_pack_4b(perm_label));
	if (n == 5)
		return (make_pack_5b(perm_label));
	if (n == 6)
		return (make_pack_6b(perm_label));
	return (NULL);
}

void	make_pack(t_stack_name stack, size_t n, t_ps_state *state)
{
	char	*perm_label;
	char	*raw_result;

	perm_label = get_permutation_label(n, state);
	if (perm_label == NULL)
		return ;
	if (stack == STACK_A)
		raw_result = make_pack_a(n, perm_label);
	else if (stack == STACK_B)
		raw_result = make_pack_b(n, perm_label);
	else
		raw_result = NULL;
	free(perm_label);
	op_apply_list(state, ft_split(raw_result, ','));
}
