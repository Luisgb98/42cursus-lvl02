/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:36:24 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/16 18:25:55 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;
	int				i;

	str = (char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr || str[i] == chr - 256)
			return (str + i);
		i++;
	}
	if (str[i] == chr)
	{
		return (str + i);
	}
	return (0);
}
