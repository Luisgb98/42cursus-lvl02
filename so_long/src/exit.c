/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:52:30 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 15:36:22 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player_dead(char keydata, t_data *data)
{
	int	i;

	i = 0;
	data -> moves++;
	data -> end = 1;
	mlx_delete_texture(data -> txtr_mc);
	mlx_delete_image(data -> mlx, data -> img_mc);
	data -> txtr_mc = mlx_load_png("./assets/textures/mc-dead.png");
	data -> img_mc = mlx_texture_to_image(data -> mlx, data -> txtr_mc);
	if (keydata == 'w')
		data -> player_y += 1;
	if (keydata == 's')
		data -> player_y -= 1;
	if (keydata == 'a')
		data -> player_x += 1;
	if (keydata == 'd')
		data -> player_x -= 1;
	data -> map[data -> player_y][data -> player_x] = 'P';
	ft_draw_map(data);
	mlx_put_string(data -> mlx, "YOU DIED!",
		data -> max_x / 2 * 64, data -> max_y / 2 * 64);
}

void	ft_player_win(t_data *data)
{
	data -> moves++;
	ft_draw_map(data);
	mlx_delete_image(data -> mlx, data -> img_mc);
	mlx_put_string(data -> mlx, "YOU WON!",
		data -> max_x / 2 * 64, data -> max_y / 2 * 64);
	data -> end = 1;
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit_game(t_data *data)
{
	ft_free_map(data -> map);
	mlx_delete_texture(data -> txtr_mc);
	mlx_delete_texture(data -> txtr_wall);
	mlx_delete_texture(data -> txtr_background);
	mlx_delete_texture(data -> txtr_collec);
	mlx_delete_texture(data -> txtr_enemy);
	mlx_delete_texture(data -> txtr_exit);
	mlx_delete_image(data -> mlx, data -> img_mc);
	mlx_delete_image(data -> mlx, data -> img_wall);
	mlx_delete_image(data -> mlx, data -> img_background);
	mlx_delete_image(data -> mlx, data -> img_collec);
	mlx_delete_image(data -> mlx, data -> img_enemy);
	mlx_delete_image(data -> mlx, data -> img_exit);
	free(data -> mlx);
	exit (0);
	return (0);
}
