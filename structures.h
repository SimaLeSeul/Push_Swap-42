/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:57:48 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 05:23:41 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stddef.h>

typedef struct s_node
{
	int				value;
	size_t			rank;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_stack
{
	t_node				*top;
	struct s_stack		*packs;
	size_t				size;
}			t_stack;

typedef enum e_stack_name
{
	STACK_A,
	STACK_B,
}			t_stack_name;

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

#endif
