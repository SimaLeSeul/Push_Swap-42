/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:46 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/07 17:21:25 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	contains_value(const t_stack *stack, int value)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (i < stack->size)
	{
		if (node->value == value)
			return (1);
		node = node->next;
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	size_t	i;

	i = 0;
	sign = 0;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 - (nptr[i] - '0');
		i++;
	}
	if (sign == 0)
		res = -res;
	return (res);
}
