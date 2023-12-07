/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:37:08 by lguisado          #+#    #+#             */
/*   Updated: 2023/11/13 19:56:16 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (0);
}

int	ft_check_dup(t_lst *stack)
{
	t_lst	*tmp;

	tmp = stack;
	while (stack)
	{
		while (tmp -> next != NULL)
		{
			tmp = tmp -> next;
			if (stack -> value == tmp -> value)
				return (0);
		}
		stack = stack -> next;
		tmp = stack;
	}
	return (1);
}

int	ft_check_number(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '-' || stack[i] == '+')
			i++;
		if (ft_isdigit(stack[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_max(char *stack)
{
	long	num;
	int		n;
	int		i;
	int		neg;

	neg = 1;
	num = 0;
	i = 0;
	if (stack[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (stack[i] != '\0' && (stack[i] >= '0' && stack[i] <= '9'))
	{
		n = stack[i++] - 48;
		num = (num * 10) + n;
	}
	if ((neg == -1 && num > 2147483648) || (neg == 1 && num > 2147483647))
		return (0);
	else
		return (1);
}
