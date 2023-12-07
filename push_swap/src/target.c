/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:43:50 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:07:25 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_pos(t_lst *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack -> position = i;
		stack = stack -> next;
		i++;
	}
}

int	ft_get_target(t_lst *stack_a, int b_idx, int target_idx, int target_pos)
{
	t_lst	*first_node;

	first_node = stack_a;
	while (stack_a)
	{
		if (stack_a -> last_pos > b_idx && stack_a -> last_pos < target_idx)
		{
			target_idx = stack_a -> last_pos;
			target_pos = stack_a -> position;
		}
		stack_a = stack_a -> next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	stack_a = first_node;
	while (stack_a)
	{
		if (stack_a->last_pos < target_idx)
		{
			target_idx = stack_a -> last_pos;
			target_pos = stack_a -> position;
		}
		stack_a = stack_a -> next;
	}
	return (target_pos);
}

void	ft_get_target_position(t_lst **stack_a, t_lst *stack_b)
{
	int		target_pos;

	ft_get_pos(*stack_a);
	ft_get_pos(stack_b);
	target_pos = 0;
	while (stack_b)
	{
		target_pos = ft_get_target(*stack_a, stack_b->last_pos,
				INT_MAX, target_pos);
		stack_b -> target_pos = target_pos;
		stack_b = stack_b -> next;
	}
}
