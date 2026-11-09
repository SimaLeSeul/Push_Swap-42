/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 02:34:54 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKING_H
# define PACKING_H

# include "structures.h"

/*
	Apply a minimal sequence of operations
	to arrange the first n elements of stack A into a sorted pack,
	the pack ending in target stack.

	After applying the result sequence:
	If target is A, the pack ends sorted at the bottom of A.
	If target is B, the pack ends reverse-sorted at the top or the bottom of B.
*/
void	make_pack(t_stack_name stack, size_t n, t_ps_state *state);

/*
	Compute the permutation needed to sort the first n elements of stack A.
	The result is a string with all digits from 1 to n.

	Example:
	First 6 elements of A: [node_100, 10, 1000, 1, 100000, 10000]
	get_permutation_label(6, node_100): "324165"
	get_permutation_label(4, node_100): "3241"
	get_permutation_label(3, node_100): "213"
*/
char	*get_permutation_label(size_t n, t_ps_state *state);

#endif
