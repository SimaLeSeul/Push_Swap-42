/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:07:23 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/13 02:02:44 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(const t_stack *a)
{
	t_node	*first;
	t_node	*second;
	double	mistakes;

	if (a->size < 2)
		return (0.0);
	mistakes = 0.0;
	first = a->top;
	while (first->next != a->top)
	{
		second = first->next;
		while (second != a->top)
		{
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	return (mistakes / ((double)a->size * (a->size - 1) / 2.0));
}

static void	bench_strategy(double disorder, t_ps_state *state)
{
	ft_printf_fd(2, "\n[bench] strategy :");
	if (state->strategy == SIMPLE)
		ft_printf_fd(2, "Simple | O(n^2)\n");
	else if (state->strategy == MEDIUM)
		ft_printf_fd(2, "Medium | O(n*sqrt(n))\n");
	else if (state->strategy == COMPLEX)
		ft_printf_fd(2, "Complex | O(n*log(n))\n");
	else if (disorder < 0.2)
		ft_printf_fd(2, "Adaptive | O(n^2)\n");
	else if (disorder < 0.5)
		ft_printf_fd(2, "Adaptive | O(n*sqrt(n))\n");
	else
		ft_printf_fd(2, "Adaptive | O(n*log(n))\n");
}

void	bench(t_ps_state *state, double disorder)
{
	size_t			total_ops;
	size_t			percent;
	size_t			pairs;
	const t_nop		*nop;

	nop = &state->nop;
	total_ops = nop->pa + nop->pb + nop->sa + nop->sb + nop->ss
		+ nop->ra + nop->rb + nop->rr + nop->rra + nop->rrb + nop->rrr;
	pairs = state->a.size * (state->a.size - 1) / 2;
	percent = (size_t)(disorder * pairs + 0.5);
	if (pairs > 0)
		percent = (percent * 10000 + pairs / 2) / pairs;
	ft_printf_fd(2, "[bench] disorder :%zu.", percent / 100);
	if (percent % 100 < 10)
		ft_printf_fd(2, "0");
	ft_printf_fd(2, "%zu%%", percent % 100);
	bench_strategy(disorder, state);
	ft_printf_fd(2, "[bench] total operations : %zu\n", total_ops);
	ft_printf_fd(2, "[bench] sa : %zu sb : %zu ss : %zu pa : %zu pb : %zu\n",
		nop->sa, nop->sb, nop->ss, nop->pa, nop->pb);
	ft_printf_fd(2, "[bench] ra : %zu rb : %zu rr : %zu ",
		nop->ra, nop->rb, nop->rr);
	ft_printf_fd(2, "rra : %zu rrb : %zu rrr : %zu\n",
		nop->rra, nop->rrb, nop->rrr);
}

void	execute(t_ps_state *state, double disorder)
{
	ft_bzero(&state->nop, sizeof(t_nop));
	if (state->strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			simple_sort(state);
		else if (disorder < 0.5)
			medium_sort(state);
		else
			complex_sort(state);
	}
	else if (state->strategy == SIMPLE)
		simple_sort(state);
	else if (state->strategy == MEDIUM)
		medium_sort(state);
	else if (state->strategy == COMPLEX)
		complex_sort(state);
	if (state->bench == 1)
		bench(state, disorder);
	return ;
}

int	main(int argc, char **argv)
{
	double		disorder;
	t_ps_state	*state;

	if (argc < 2)
		return (0);
	state = parse_args(argc, argv);
	disorder = calculate_disorder(&state->a);
	execute(state, disorder);
	free_state(state);
	return (0);
}
