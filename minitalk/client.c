/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:26:22 by lguisado          #+#    #+#             */
/*   Updated: 2022/11/17 15:49:05 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	ft_count(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putstr_fd("Received: ", 1);
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	ft_send(int pid, char *str)
{
	char	c;
	int		byte;
	int		i;

	i = 0;
	while (str[i])
	{
		byte = 8;
		c = str[i++];
		while (byte--)
		{
			if (c >> byte & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	byte = 8;
	while (byte--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Invalid arguments!", 1);
		return (0);
	}
	ft_putstr_fd("Sending: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	ft_send(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause ();
}
