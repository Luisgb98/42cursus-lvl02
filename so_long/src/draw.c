/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:18:06 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 17:19:35 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_mc(t_data *data, int y, int x)
{
	data -> player_y = y;
	data -> player_x = x;
	ft_draw_images(data -> mlx, data -> img_mc, x, y);
}

void	ft_draw_images(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(mlx, img, x * 64, y * 64);
}

void	ft_draw_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data -> moves);
	mlx_put_string(data -> mlx, "MOVES: ", 0 * 64, 0 * 64);
	mlx_put_string(data -> mlx, moves, 1 * 64, 0 * 64);
	ft_printf("MOVES: %d\n", data -> moves);
	free (moves);
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data -> map[++y])
	{
		x = -1;
		while (data -> map[y][++x])
		{
			ft_draw_images(data -> mlx, data -> img_background, x, y);
			if (data -> map[y][x] == '1')
				ft_draw_images(data -> mlx, data -> img_wall, x, y);
			else if (data -> map[y][x] == '0')
				ft_draw_images(data -> mlx, data -> img_background, x, y);
			else if (data -> map[y][x] == 'P')
				ft_draw_mc(data, y, x);
			else if (data -> map[y][x] == 'S')
				ft_draw_images(data -> mlx, data -> img_enemy, x, y);
			else if (data -> map[y][x] == 'C')
				ft_draw_images(data -> mlx, data -> img_collec, x, y);
			else if (data -> map[y][x] == 'E')
				ft_draw_images(data -> mlx, data -> img_exit, x, y);
		}
	}
	ft_draw_moves(data);
}
/* BUGGED ANIMATION FUNC
void	ft_enemy_anim(void *param)
{
	t_data	*data;

	data = param;
	mlx_delete_texture(data -> txtr_enemy);
	if (data -> enemy_anim++ < 10)
	{
		data -> txtr_enemy = mlx_load_png("./assets/textures/enemy1.png");
		data -> img_enemy
			= mlx_texture_to_image(data -> mlx, data -> txtr_enemy);
	}
	else if (data -> enemy_anim++ < 20)
	{
		data -> txtr_enemy = mlx_load_png("./assets/textures/enemy2.png");
		data -> img_enemy
			= mlx_texture_to_image(data -> mlx, data -> txtr_enemy);
	}
	else if (data -> enemy_anim++ < 30)
	{
		data -> txtr_enemy = mlx_load_png("./assets/textures/enemy3.png");
		data -> img_enemy
			= mlx_texture_to_image(data -> mlx, data -> txtr_enemy);
		if (data -> enemy_anim == 29)
			data -> enemy_anim = 0;
	}
	ft_draw_map(data);
}
*/
