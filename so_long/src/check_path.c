/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:24:55 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/27 18:40:23 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_flood(t_data *data, int y, int x)
{
	if (!(y < 1 || x < 1 || y > data -> max_y
			|| x > data -> max_x || data -> map_copy[y][x] == '1'
		|| data -> map_copy[y][x] == 'T'))
	{
		data -> map_copy[y][x] = 'T';
		ft_flood(data, y + 1, x);
		ft_flood(data, y, x + 1);
		ft_flood(data, y - 1, x);
		ft_flood(data, y, x - 1);
	}
}

int	*ft_mc_pos(t_data *data, int *pos)
{
	int	x;
	int	y;

	y = 0;
	while (data -> map_copy[y])
	{
		x = 0;
		while (data -> map_copy[y][x])
		{
			if (data -> map_copy[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	ft_check_path(t_data *data)
{
	int	y;
	int	x;
	int	*pos;

	pos = ft_calloc(2, sizeof(int));
	ft_mc_pos(data, pos);
	ft_flood(data, pos[0], pos[1]);
	free (pos);
	y = 0;
	while (data -> map_copy[y])
	{
		x = 0;
		while (data -> map_copy[y][x])
		{
			if (data -> map_copy[y][x] == 'E'
				|| data -> map_copy[y][x] == 'C'
				|| data -> map_copy[y][x] == 'P')
				ft_error(11);
			x++;
		}
		y++;
	}
}
