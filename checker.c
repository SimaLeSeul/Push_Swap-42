/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 01:45:00 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/13 02:03:22 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_state	*state;
	char		buffer[101];

	if (argc < 2)
		return (0);
	state = parse_args(argc, argv);
	read(0, buffer, 100);
	buffer[100] = '\0';
	ft_printf("Ok %s", buffer);
	free_state(state);
	return (0);
}
