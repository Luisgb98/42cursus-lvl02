/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:46:14 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 17:17:37 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_errors(t_data *data)
{
	ft_check_walls(data);
	ft_find_collectables(data);
	ft_check_cep(data);
	ft_check_path(data);
	ft_check_len(data);
}

void	ft_check_len(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data -> map[y])
	{
		x = 0;
		while (data -> map[y][x])
			x++;
		x--;
		if (x < data -> max_x || x > data -> max_x)
			ft_error(5);
		y++;
	}
}

void	ft_check_ber(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 4] == '.'
		&& argv[1][len - 3] == 'b'
		&& argv[1][len - 2] == 'e'
		&& argv[1][len - 1] == 'r')
		return ;
	ft_error(6);
}

void	ft_check_cep(t_data *data)
{
	if (data -> n_collectable < 1)
		ft_error(7);
	else if (data -> n_exit != 1)
		ft_error(8);
	else if (data -> n_player != 1)
		ft_error(9);
}

void	ft_check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data -> map[0][x] && data -> map[data -> max_y][x])
	{
		if (data -> map[0][x] != '1' || data -> map[data -> max_y][x] != '1')
			ft_error(3);
		x++;
	}
	y = 0;
	while (data -> map[y])
	{
		if (data -> map[y][0] != '1' || data -> map[y][data -> max_x] != '1')
			ft_error(3);
		y++;
	}
}
