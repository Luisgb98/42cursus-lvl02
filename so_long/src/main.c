/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:02:17 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 17:18:36 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}
/* ANIMATION BUGGED */
// mlx_loop_hook(data -> mlx, ft_enemy_anim, data);

int	main(int argc, char **argv)
{
	t_data	*data;

	atexit(ft_leaks);
	if (argc < 2)
		ft_error(1);
	else if (argc > 2)
		ft_error(10);
	ft_check_ber(argv);
	data = ft_calloc(1, sizeof(t_data));
	data -> map = ft_open_fd(argv);
	if (data -> map[0] == NULL)
		ft_error(0);
	data -> map_copy = ft_open_fd(argv);
	ft_init(data);
	ft_check_errors(data);
	data -> mlx = mlx_init(data -> map_width,
			data -> map_height, "42 Valley!", 0);
	if (!data -> mlx)
		ft_error(3);
	ft_init_imgs(data);
	ft_draw_map(data);
	mlx_key_hook(data -> mlx, &ft_keyhook, data);
	mlx_loop(data -> mlx);
}
