/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:45:11 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:08 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*ft_worddup(char const *s, int start, char sep)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	while (s[start + i] != sep && s[start + i])
		i++;
	dest = (char *) malloc (sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	len = i;
	i = 0;
	while (i < len)
	{
		dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;
	size_t	j;

	dest = (char **) malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			dest[j] = ft_worddup(s, i, c);
			i += ft_strlen(dest[j]);
			j++;
		}
	}
	dest[j] = 0;
	return (dest);
}
