/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:39:35 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:53 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_convert(va_list list, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (type == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (type == 'p')
		len += ft_putptr(va_arg(list, unsigned long long));
	else if (type == 'd')
		len += ft_putnbr(va_arg(list, int));
	else if (type == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (type == 'u')
		len += ft_putunbr(va_arg(list, unsigned int));
	else if (type == 'x')
		len += ft_puthex(va_arg(list, unsigned int), 'x');
	else if (type == 'X')
		len += ft_puthex(va_arg(list, unsigned int), 'X');
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	va_start(list, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_convert(list, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
