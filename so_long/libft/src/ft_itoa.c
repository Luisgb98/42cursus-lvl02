/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:08:35 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/22 18:42:22 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

int	ft_nbrlen_itoa(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		negative;
	int		nlen;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	ft_negative(&n, &negative);
	nlen = ft_nbrlen_itoa(n);
	if (negative == 1)
		nlen += 1;
	dest = malloc(sizeof(char) * (nlen + 1));
	if (!dest)
		return (0);
	i = nlen;
	while (i > 0)
	{
		dest[--i] = n % 10 + 48;
		n /= 10;
	}
	if (negative == 1)
		dest[0] = '-';
	dest[nlen] = '\0';
	return (dest);
}
