/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:24:56 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:55 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
	return (len);
}

int	ft_putunbr(unsigned int nbr)
{
	int	len;

	len = ft_unbrlen(nbr);
	if (nbr >= 10)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
	return (len);
}
