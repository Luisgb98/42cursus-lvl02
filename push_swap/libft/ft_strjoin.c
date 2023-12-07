/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:10:57 by lguisado          #+#    #+#             */
/*   Updated: 2022/09/26 13:56:55 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str1;
	char			*str2;
	char			*dest;
	unsigned int	slen;

	str1 = (char *) s1;
	str2 = (char *) s2;
	slen = ft_strlen(str1) + ft_strlen(str2);
	dest = malloc(sizeof(char) * (slen + 1));
	if (!dest)
		return (0);
	ft_memcpy(dest, str1, ft_strlen(str1) + 1);
	ft_strlcat(dest, str2, slen + 1);
	return (dest);
}
