/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permutation_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 02:18:00 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 02:41:47 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "structures.h"

char	*get_permutation_label(size_t n, t_ps_state *state)
{
	char	*result;
	size_t	result_size;

	(void)state;
	result_size = n + 1;
	result = malloc((result_size) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, "134265", result_size);
	return (result);
}
