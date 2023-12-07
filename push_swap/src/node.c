/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:42:28 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:56:07 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*ft_get_second_last_node(t_lst *stack)
{
	while (stack && stack -> next && stack -> next -> next != NULL)
		stack = stack -> next;
	return (stack);
}

t_lst	*ft_get_last_node(t_lst *stack)
{
	while (stack && stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	ft_add_node(t_lst **stack, t_lst *new_node)
{
	t_lst	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = ft_get_last_node(*stack);
	last -> next = new_node;
}

int	ft_find_highest_last_pos(t_lst *stack)
{
	int		last_pos;

	last_pos = stack->last_pos;
	while (stack)
	{
		if (stack->last_pos > last_pos)
			last_pos = stack->last_pos;
		stack = stack->next;
	}
	return (last_pos);
}

int	ft_find_lowest_last_pos(t_lst **stack)
{
	t_lst	*tmp;
	int		lowest_last_pos;
	int		lowest_pos;

	tmp = *stack;
	lowest_last_pos = INT_MAX;
	ft_get_pos(*stack);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->last_pos < lowest_last_pos)
		{
			lowest_last_pos = tmp->last_pos;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
