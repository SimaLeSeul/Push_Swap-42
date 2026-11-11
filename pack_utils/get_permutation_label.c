/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permutation_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:18:00 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 03:18:29 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "structures.h"

static void	set_partial_rank(t_stack stack, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	rank;
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack.top;
	i = 0;
	while (i < n)
	{
		len = n;
		rank = 1;
		tmp2 = stack.top;
		while (len > 0)
		{
			if (tmp2->value < tmp->value)
				rank++;
			tmp2 = tmp2->next;
			len--;
		}
		tmp->rank = rank;
		tmp = tmp->next;
		i++;
	}
}

char	*get_permutation_label(size_t n, t_ps_state *state)
{
	char		*result;
	t_node		*tmp;
	size_t		i;

	set_partial_rank(state->a, n);
	tmp = (state->a).top;
	result = malloc((n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = '0' + tmp->rank;
		tmp = tmp->next;
		i++;
	}
	result[n] = '\0';
	return (result);
}
