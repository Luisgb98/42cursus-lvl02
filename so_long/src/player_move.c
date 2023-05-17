/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:13:55 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 15:37:03 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_update_img(char keydata, t_data *data)
{
	mlx_delete_texture(data -> txtr_mc);
	mlx_delete_image(data -> mlx, data -> img_mc);
	if (keydata == 'w')
	{
		data -> txtr_mc = mlx_load_png("./assets/textures/mc-w.png");
		data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	}
	else if (keydata == 's')
	{
		data -> txtr_mc = mlx_load_png("./assets/textures/mc-s.png");
		data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	}
	else if (keydata == 'a')
	{
		data -> txtr_mc = mlx_load_png("./assets/textures/mc-a.png");
		data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	}
	else if (keydata == 'd')
	{
		data -> txtr_mc = mlx_load_png("./assets/textures/mc-d.png");
		data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	}
}

void	ft_player_up(t_data *data)
{
	if (data -> map[data -> player_y][data -> player_x] == 'E'
		&& data -> collectable == data -> n_collectable)
		ft_player_win(data);
	else if (data -> map[data -> player_y][data -> player_x] == 'S')
		ft_player_dead('w', data);
	else if (data -> map[data -> player_y][data -> player_x] == '1'
		|| data -> map[data -> player_y][data -> player_x] == 'E')
		data -> player_y += 1;
	else
	{
		ft_update_img('w', data);
		if (data -> map[data -> player_y][data -> player_x] == 'C')
			ft_collectables(data);
		data -> map[data -> player_y][data -> player_x] = 'P';
		data -> map[data -> player_y + 1][data -> player_x] = '0';
		data -> moves++;
		ft_draw_map(data);
	}
}

void	ft_player_down(t_data *data)
{
	if (data -> map[data -> player_y][data -> player_x] == 'E'
		&& data -> collectable == data -> n_collectable)
		ft_player_win(data);
	else if (data -> map[data -> player_y][data -> player_x] == 'S')
		ft_player_dead('s', data);
	else if (data -> map[data -> player_y][data -> player_x] == '1'
		|| data -> map[data -> player_y][data -> player_x] == 'E')
		data -> player_y -= 1;
	else
	{
		ft_update_img('s', data);
		if (data -> map[data -> player_y][data -> player_x] == 'C')
			ft_collectables(data);
		data -> map[data -> player_y][data -> player_x] = 'P';
		data -> map[data -> player_y - 1][data -> player_x] = '0';
		data -> moves++;
		ft_draw_map(data);
	}
}

void	ft_player_left(t_data *data)
{
	if (data -> map[data -> player_y][data -> player_x] == 'E'
		&& data -> collectable == data -> n_collectable)
		ft_player_win(data);
	else if (data -> map[data -> player_y][data -> player_x] == 'S')
		ft_player_dead('a', data);
	else if (data -> map[data -> player_y][data -> player_x] == '1'
		|| data -> map[data -> player_y][data -> player_x] == 'E')
		data -> player_x += 1;
	else
	{
		ft_update_img('a', data);
		if (data -> map[data -> player_y][data -> player_x] == 'C')
			ft_collectables(data);
		data -> map[data -> player_y][data -> player_x] = 'P';
		data -> map[data -> player_y][data -> player_x + 1] = '0';
		data -> moves++;
		ft_draw_map(data);
	}
}

void	ft_player_right(t_data *data)
{
	if (data -> map[data -> player_y][data -> player_x] == 'E'
		&& data -> collectable == data -> n_collectable)
		ft_player_win(data);
	else if (data -> map[data -> player_y][data -> player_x] == 'S')
		ft_player_dead('d', data);
	else if (data -> map[data -> player_y][data -> player_x] == '1'
		|| data -> map[data -> player_y][data -> player_x] == 'E')
		data -> player_x -= 1;
	else
	{
		ft_update_img('d', data);
		if (data -> map[data -> player_y][data -> player_x] == 'C')
			ft_collectables(data);
		data -> map[data -> player_y][data -> player_x] = 'P';
		data -> map[data -> player_y][data -> player_x - 1] = '0';
		data -> moves++;
		ft_draw_map(data);
	}
}
