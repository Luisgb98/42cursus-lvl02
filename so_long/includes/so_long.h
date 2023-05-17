/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:49:29 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 17:20:03 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	mlx_t			*mlx;
	char			**map;
	char			**map_copy;
	int				end;
	int				enemy_anim;
	int				max_y;
	int				max_x;
	int				map_width;
	int				map_height;
	int				player_y;
	int				player_x;
	int				n_collectable;
	int				n_player;
	int				n_exit;
	int				collectable;
	int				moves;
	mlx_texture_t	*txtr_mc;
	mlx_image_t		*img_mc;
	mlx_texture_t	*txtr_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*txtr_background;
	mlx_image_t		*img_background;
	mlx_texture_t	*txtr_collec;
	mlx_image_t		*img_collec;
	mlx_texture_t	*txtr_enemy;
	mlx_image_t		*img_enemy;
	mlx_texture_t	*txtr_exit;
	mlx_image_t		*img_exit;
}	t_data;

/*	--	 check_path.c	--	*/
void	ft_flood(t_data *data, int y, int x);
int		*ft_mc_pos(t_data *data, int *pos);
void	ft_check_path(t_data *data);

/*	--	 check.c	--	*/
void	ft_check_errors(t_data *data);
void	ft_check_len(t_data *data);
void	ft_check_ber(char **argv);
void	ft_check_cep(t_data *data);
void	ft_check_walls(t_data *data);

/*	--	 error.c	--	*/
void	ft_error(int error);

/*	--	 exit.c	--	*/
void	ft_player_dead(char keydata, t_data *data);
void	ft_player_win(t_data *data);
void	ft_free_map(char **map);
int		ft_exit_game(t_data *data);

/*	--	 init.c	--	*/
void	ft_init(t_data *data);
void	ft_init_imgs(t_data *data);
void	ft_find_collectables(t_data *data);
void	ft_collectables(t_data *data);

/*	--	 draw.c	--	*/
void	ft_draw_mc(t_data *data, int y, int x);
void	ft_draw_images(mlx_t *mlx, mlx_image_t *img, int x, int y);
void	ft_draw_moves(t_data *data);
void	ft_draw_map(t_data *data);
/*	--	 BUGGED ANIM	--	*/
// void	ft_enemy_anim(void *param);

/*	--	 map.c	--	*/
char	**ft_open_fd(char **argv);

/*	--	 move.c	--	*/
void	ft_keymove(t_data *data);
void	ft_keyhook(mlx_key_data_t keydata, void *param);

/*	--	 player_move.c	--	*/
void	ft_update_img(char keydata, t_data *data);
void	ft_player_up(t_data *data);
void	ft_player_down(t_data *data);
void	ft_player_left(t_data *data);
void	ft_player_right(t_data *data);

#endif