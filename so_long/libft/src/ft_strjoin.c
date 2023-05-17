/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:10:57 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/20 16:21:12 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char			*dest;
	unsigned int	slen;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (0);
	slen = ft_strlen(str1) + ft_strlen(str2);
	dest = malloc(sizeof(char) * (slen + 1));
	if (!dest)
		return (0);
	ft_memcpy(dest, str1, ft_strlen(str1) + 1);
	ft_strlcat(dest, str2, slen + 1);
	free (str1);
	return (dest);
}
