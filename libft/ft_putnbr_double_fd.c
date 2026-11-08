/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_double_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:00:00 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/08 12:00:00 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_bit(char *digits, int bit)
{
	int	i;

	i = 0;
	while (i < 310)
	{
		bit += digits[i] * 2;
		digits[i] = bit % 10;
		bit /= 10;
		i++;
	}
}

static double	put_integer(double n, int fd)
{
	char	digits[310];
	double	power;
	int		i;

	ft_bzero(digits, sizeof(digits));
	power = 1;
	while (power <= n / 2)
		power *= 2;
	while (power >= 1)
	{
		append_bit(digits, n >= power);
		if (n >= power)
			n -= power;
		power /= 2;
	}
	i = 309;
	while (i > 0 && digits[i] == 0)
		i--;
	while (i >= 0)
		ft_putchar_fd(digits[i--] + '0', fd);
	return (n);
}

static void	put_fraction(double n, int fd)
{
	int	i;
	int	digit;

	ft_putchar_fd('.', fd);
	i = 0;
	while (i < 6)
	{
		n *= 10;
		digit = (int)n;
		ft_putchar_fd(digit + '0', fd);
		n -= digit;
		i++;
	}
}

void	ft_putnbr_double_fd(double n, int fd)
{
	if (n != n)
	{
		ft_putstr_fd("nan", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n != 0 && n / 2 == n)
	{
		ft_putstr_fd("inf", fd);
		return ;
	}
	n += 0.0000005;
	n = put_integer(n, fd);
	put_fraction(n, fd);
}
