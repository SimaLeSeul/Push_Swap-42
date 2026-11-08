/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:26:35 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:10:26 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-', fd) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
		count = ft_putnbr(nb / 10, fd);
	if (count == -1 || ft_putchar((nb % 10) + '0', fd) == -1)
		return (-1);
	return (count + 1 + (n < 0));
}
