/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:57:32 by lguisado          #+#    #+#             */
/*   Updated: 2022/09/23 14:48:48 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;
	int				i;

	str = (char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == chr || str[i] == chr - 256)
			return (str + i);
		i--;
	}
	return (0);
}
