/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:45:52 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 17:54:49 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdest;
	char	*ptr;
	size_t	i;

	csrc = (char *) src;
	cdest = (char *) dst;
	ptr = NULL;
	i = 0;
	if (!cdest && !csrc)
		return (NULL);
	if (!cdest || !csrc)
		*ptr = 1;
	if (cdest > csrc)
		while (len-- > 0)
			cdest[len] = csrc[len];
	else
	{
		while (i < len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
