/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:04:26 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:13:13 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long addr, int fd)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (addr > 15)
		count = ft_putptr_hex(addr / 16, fd);
	if (count == -1 || ft_putchar(hex[addr % 16], fd) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *ptr, int fd)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)", fd));
	if (write(fd, "0x", 2) != 2)
		return (-1);
	count = ft_putptr_hex((unsigned long)ptr, fd);
	if (count == -1)
		return (-1);
	return (count + 2);
}
