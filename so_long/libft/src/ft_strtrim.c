/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:57:40 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:34 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_set(char const *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*dest;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	while (s1[start] && check_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_set(set, s1[end - 1]))
		end--;
	dest = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!dest)
		return (0);
	i = 0;
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}
