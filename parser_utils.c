/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:46 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/08 19:24:34 by mibaboul         ###   ########.fr       */
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
