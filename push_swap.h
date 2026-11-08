/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:56:08 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/08 19:56:30 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}			t_stack;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}			t_strategy;

typedef struct s_ps_state
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			bench;
}			t_ps_state;

typedef struct s_nop
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}			t_nop;

double		calculate_disorder(const t_stack *a);
void		bench(t_nop *nop, double disorder, t_ps_state *state);
void		execute(t_ps_state *state, double disorder, int bflag, t_nop *nop);

size_t		find_min_position(t_stack *stack);
double		calculate_disorder(const t_stack *a);
void		put_min_first(t_ps_state *state, t_nop *nop);
void		simple_sort(t_ps_state *state, t_nop *nop);
int			stack_is_sorted(const t_stack *stack);
int			*sorted_values(t_ps_state *state);

t_ps_state	*str_to_list(void);
void		free_state(t_ps_state *state);
void		freexit(t_ps_state *state);
t_node		*node_new(int value);
void		stack_append(t_stack *stack, t_node *node);
void		stack_clear(t_stack *stack);

int			is_whitespace(char c);
int			contains_value(const t_stack *stack, int value);
size_t		argtoint(const char *s, t_ps_state *state);

t_ps_state	*parse_args(int argc, char **argv);
int			flags_handler(const char *s, t_ps_state *state);

void		op_sa(t_ps_state *state, int flag);
void		op_sb(t_ps_state *state, int flag);
void		op_ss(t_ps_state *state);
void		op_pa(t_ps_state *state);
void		op_pb(t_ps_state *state);
void		op_ra(t_ps_state *state, int flag);
void		op_rb(t_ps_state *state, int flag);
void		op_rr(t_ps_state *state);
void		op_rra(t_ps_state *state, int flag);
void		op_rrb(t_ps_state *state, int flag);
void		op_rrr(t_ps_state *state);
#endif
