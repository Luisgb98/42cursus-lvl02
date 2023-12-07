/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:05:43 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 15:36:36 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algorithm(t_lst **stack_a, t_lst **stack_b, int total_size)
{
	ft_push_all_less_three_to_b(stack_a, stack_b, total_size);
	ft_sorting_three(stack_a);
	while (*stack_b)
	{
		ft_get_target_position(stack_a, *stack_b);
		ft_find_cost(*stack_a, *stack_b);
		ft_moves(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_set_in_order(stack_a);
}

void	ft_push_all_less_three_to_b(t_lst **stack_a,
		t_lst **stack_b, int total_size)
{
	int	i;

	i = 0;
	while (total_size - i > total_size / 2 && i < total_size / 2)
	{
		if ((*stack_a)-> last_pos <= total_size / 2)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	while (total_size - i > 3)
	{
		pb(stack_a, stack_b);
		i++;
	}
}

void	ft_set_in_order(t_lst **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_size_stack(*stack_a);
	lowest_pos = ft_find_lowest_last_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
