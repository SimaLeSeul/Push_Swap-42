/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:35:13 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/02 20:35:26 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ps_state
{
	int			*a;
	int			*b;
	size_t		pa;
	size_t		pb;
	size_t		tlen;
}			t_ps_state;

// Push-Swap-Rotate operations
void	op_sa(t_ps_state state);
void	op_sb(t_ps_state state);
void	op_ss(t_ps_state state);
void	op_pa(t_ps_state state);
void	op_pb(t_ps_state state);
void	op_ra(t_ps_state state);
void	op_rb(t_ps_state state);
void	op_rr(t_ps_state state);
void	op_rra(t_ps_state state);
void	op_rrb(t_ps_state state);
void	op_rrr(t_ps_state state);

#endif
