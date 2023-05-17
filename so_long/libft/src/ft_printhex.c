/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:22:37 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:56 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_puthex(unsigned int nbr, char format)
{
	char	*base;
	int		i;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = ft_hexnbrlen(nbr);
	if (nbr < 16)
	{
		ft_putchar(base[nbr % 16]);
	}
	else
	{
		ft_puthex(nbr / 16, format);
		ft_putchar(base[nbr % 16]);
	}
	return (i);
}

int	ft_putptr(unsigned long long nbr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (nbr == 0)
		i += ft_putchar('0');
	else
	{
		i += ft_ptrlen(nbr);
		ft_puthexptr(nbr);
	}
	return (i);
}

void	ft_puthexptr(unsigned long long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		ft_putchar(base[nbr % 16]);
	}
	else
	{
		ft_puthexptr(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
}
