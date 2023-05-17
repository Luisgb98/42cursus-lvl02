/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:17:26 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 15:21:46 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_keymove(t_data *data)
{
	if (mlx_is_key_down(data -> mlx, MLX_KEY_W)
		|| mlx_is_key_down(data -> mlx, MLX_KEY_UP))
	{
		data -> player_y -= 1;
		ft_player_up(data);
	}
	if (mlx_is_key_down(data -> mlx, MLX_KEY_S)
		|| mlx_is_key_down(data -> mlx, MLX_KEY_DOWN))
	{
		data -> player_y += 1;
		ft_player_down(data);
	}
	if (mlx_is_key_down(data -> mlx, MLX_KEY_A)
		|| mlx_is_key_down(data -> mlx, MLX_KEY_LEFT))
	{
		data -> player_x -= 1;
		ft_player_left(data);
	}
	if (mlx_is_key_down(data -> mlx, MLX_KEY_D)
		|| mlx_is_key_down(data -> mlx, MLX_KEY_RIGHT))
	{
		data -> player_x += 1;
		ft_player_right(data);
	}
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (data -> end == 1)
	{
		usleep(150000);
		ft_exit_game(data);
	}
	else
	{
		ft_keymove(data);
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_exit_game(data);
	}	
}
