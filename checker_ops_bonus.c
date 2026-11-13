/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:00:00 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/13 12:00:00 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	checker_op_index(t_ps_state *state, const char *line)
{
	const char	*ops[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11 && !strings_equal(line, ops[i]))
		i++;
	if (i == 11)
		freexit(state);
	return (i);
}

static void	checker_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
}

static void	checker_push(t_stack *source, t_stack *destination)
{
	t_node	*node;

	if (source->size == 0)
		return ;
	node = source->top;
	if (source->size == 1)
		source->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		source->top = node->next;
	}
	source->size--;
	stack_append(destination, node);
	destination->top = node;
}

static void	checker_rotate(t_stack *stack, int reverse)
{
	if (stack->size < 2)
		return ;
	if (reverse)
		stack->top = stack->top->prev;
	else
		stack->top = stack->top->next;
}

void	checker_apply(t_ps_state *state, const char *line)
{
	int	op;

	op = checker_op_index(state, line);
	if (op < 3)
	{
		if (op != 1)
			checker_swap(&state->a);
		if (op != 0)
			checker_swap(&state->b);
	}
	else if (op == 3)
		checker_push(&state->b, &state->a);
	else if (op == 4)
		checker_push(&state->a, &state->b);
	else
	{
		if ((op - 5) % 3 != 1)
			checker_rotate(&state->a, op >= 8);
		if ((op - 5) % 3 != 0)
			checker_rotate(&state->b, op >= 8);
	}
}
