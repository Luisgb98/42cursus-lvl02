/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:58:23 by lguisado          #+#    #+#             */
/*   Updated: 2022/09/23 12:33:43 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (src[i])
		i++;
	slen = i;
	dlen = j;
	if (dstsize == 0 || dstsize <= j)
		return (slen + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
