/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:42:32 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 15:26:34 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init(t_data *data)
{
	int	y;

	y = 0;
	data -> max_x = ft_strlen(data -> map[0]) - 1;
	y = 0;
	while (data -> map[y])
		y++;
	data -> max_y = y - 1;
	data -> map_width = (data -> max_x + 1) * 64;
	data -> map_height = (data -> max_y + 1) * 64;
	data -> end = 0;
	data -> moves = 0;
	data -> enemy_anim = 1;
}

void	ft_init_imgs(t_data *data)
{
	data -> txtr_mc = mlx_load_png("./assets/textures/mc-d.png");
	data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	data -> txtr_wall = mlx_load_png("./assets/textures/wall.png");
	data -> img_wall = mlx_texture_to_image(data -> mlx, data -> txtr_wall);
	data -> txtr_background = mlx_load_png("./assets/textures/background.png");
	data -> img_background
		= mlx_texture_to_image(data -> mlx, data -> txtr_background);
	data -> txtr_collec = mlx_load_png("./assets/textures/collectable.png");
	data -> img_collec = mlx_texture_to_image(data -> mlx, data -> txtr_collec);
	data -> txtr_enemy = mlx_load_png("./assets/textures/enemy1.png");
	data -> img_enemy = mlx_texture_to_image(data -> mlx, data -> txtr_enemy);
	data -> txtr_exit = mlx_load_png("./assets/textures/exit.png");
	data -> img_exit = mlx_texture_to_image(data -> mlx, data -> txtr_exit);
}

void	ft_find_collectables(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data -> map[y])
	{
		x = 0;
		while (data -> map[y][x])
		{
			if (data -> map[y][x] == 'C')
				data -> n_collectable++;
			else if (data -> map[y][x] == 'P')
				data -> n_player++;
			else if (data -> map[y][x] == 'E')
				data -> n_exit++;
			x++;
		}
		y++;
	}
}

void	ft_collectables(t_data *data)
{
	data -> collectable++;
	if (data -> collectable == data -> n_collectable)
	{
		mlx_delete_texture(data -> txtr_exit);
		data -> txtr_exit = mlx_load_png("./assets/textures/exit2.png");
		data -> img_exit = mlx_texture_to_image(data -> mlx, data -> txtr_exit);
	}
}
