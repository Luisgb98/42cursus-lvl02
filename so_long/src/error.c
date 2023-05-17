/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:22:45 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 14:30:12 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_printf("Error\nMap empty\n");
	if (error == 1)
		ft_printf("Error\nMap not provided\n");
	if (error == 2)
		ft_printf("Error\nCan't find a MLX window\n");
	if (error == 3)
		ft_printf("Error\nMap isn't surrounded by walls\n");
	if (error == 4)
		ft_printf("Error\nCan't open the file provided\n");
	if (error == 5)
		ft_printf("Error\nMap need to be a rectangle\n");
	if (error == 6)
		ft_printf("Error\nWrong file type\n");
	if (error == 7)
		ft_printf("Error\nNo collectables\n");
	if (error == 8)
		ft_printf("Error\nOnly one exit allowed\n");
	if (error == 9)
		ft_printf("Error\nOnly one player allowed\n");
	if (error == 10)
		ft_printf("Error\nOne argument allowed\n");
	if (error == 11)
		ft_printf("Error\nNo path available\n");
	exit (0);
}
