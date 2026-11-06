/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:55:53 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/06 14:55:54 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	stack_append(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
	}
	else
	{
		node->prev = stack->top->prev;
		node->next = stack->top;
		stack->top->prev->next = node;
		stack->top->prev = node;
	}
	stack->size++;
}

void	stack_clear(t_stack *stack)
{
	t_node	*node;
	t_node	*next;
	size_t	remaining;

	node = stack->top;
	remaining = stack->size;
	while (remaining > 0)
	{
		next = node->next;
		free(node);
		node = next;
		remaining--;
	}
	stack->top = NULL;
	stack->size = 0;
}
