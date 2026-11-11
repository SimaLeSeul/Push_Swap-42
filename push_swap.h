/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:56:08 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/11 04:45:16 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "structures.h"
# include "libft/libft.h"

double		calculate_disorder(const t_stack *a);
void		bench(t_nop *nop, double disorder, t_ps_state *state);
void		execute(t_ps_state *state, double disorder, int bflag, t_nop *nop);

size_t		find_min_position(t_stack *stack);
double		calculate_disorder(const t_stack *a);
int			stack_is_sorted(const t_stack *stack);
void		put_min_first(t_ps_state *state, t_nop *nop);
void		simple_sort(t_ps_state *state, t_nop *nop);
void		medium_sort(t_ps_state *state, t_nop *nop);
void		complex_sort(t_ps_state *state, t_nop *nop);
t_ps_state	*str_to_list(void);
void		free_state(t_ps_state *state);
void		freexit(t_ps_state *state);
t_node		*node_new(int value);
void		stack_append(t_stack *stack, t_node *node);
void		stack_clear(t_stack *stack);

int			strings_equal(const char *s1, const char *s2);
int			is_whitespace(char c);
int			contains_value(const t_stack *stack, int value);
size_t		argtoint(const char *s, t_ps_state *state);

t_ps_state	*parse_args(int argc, char **argv);
int			flags_handler(const char *s, t_ps_state *state);

void		op_sa(t_ps_state *state);
void		op_sb(t_ps_state *state);
void		op_ss(t_ps_state *state);
void		op_pa(t_ps_state *state);
void		op_pb(t_ps_state *state);
void		op_ra(t_ps_state *state);
void		op_rb(t_ps_state *state);
void		op_rr(t_ps_state *state);
void		op_rra(t_ps_state *state);
void		op_rrb(t_ps_state *state);
void		op_rrr(t_ps_state *state);

void		op_apply(t_ps_state *state, char *op);
void		op_apply_list(t_ps_state *state, char **ops);

void		merge_pack_to_a(t_ps_state state, size_t size_a, size_t size_b);
void		merge_pack_to_b(t_ps_state state, size_t size_a, size_t size_b);

#endif
