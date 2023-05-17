/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:19:29 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/29 14:41:12 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_open_fd(char **argv)
{
	int		fd;
	char	*line;
	char	*holder;
	char	*save_line;
	char	**map;

	map = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(4);
	save_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = save_line;
		save_line = ft_strjoin(holder, line);
		free (line);
	}
	map = ft_split(save_line, '\n');
	free (save_line);
	close (fd);
	return (map);
}
