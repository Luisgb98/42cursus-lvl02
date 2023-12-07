/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:02:54 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 16:05:00 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_cost(t_lst *stack_a, t_lst *stack_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_size_stack(stack_a);
	size_b = ft_size_stack(stack_b);
	while (stack_b)
	{
		stack_b -> b_cost = stack_b -> position;
		if (stack_b -> position > size_b / 2)
			stack_b -> b_cost = (size_b - stack_b -> position) * -1;
		stack_b->a_cost = stack_b -> target_pos;
		if (stack_b -> target_pos > size_a / 2)
			stack_b -> a_cost = (size_a - stack_b -> target_pos) * -1;
		stack_b = stack_b -> next;
	}
}

void	ft_choose_rotate(t_lst **stack, int *cost, char c)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (c == 'a')
				ra(stack);
			else if (c == 'b')
				rb(stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (c == 'a')
				rra(stack);
			else if (c == 'b')
				rrb(stack);
			(*cost)++;
		}
	}
}

void	ft_both_rotate(t_lst **stack_a, t_lst **stack_b,
		t_costs costs, char *str)
{
	if (strcmp(str, "rr"))
	{
		while (costs.a_cost > 0 && costs.b_cost > 0)
		{
			costs.a_cost--;
			costs.b_cost--;
			rr(stack_a, stack_b);
		}
	}
	else if (strcmp(str, "rrr"))
	{
		while (costs.a_cost < 0 && costs.b_cost < 0)
		{
			costs.a_cost++;
			costs.b_cost++;
			rrr(stack_a, stack_b);
		}
	}
}

void	ft_make_moves(t_lst **stack_a, t_lst **stack_b, int a_cost, int b_cost)
{
	t_costs	costs;

	costs.a_cost = a_cost;
	costs.b_cost = b_cost;
	if (a_cost < 0 && b_cost < 0)
		ft_both_rotate(stack_a, stack_b, costs, "rrr");
	else if (a_cost > 0 && b_cost > 0)
		ft_both_rotate(stack_a, stack_b, costs, "rr");
	ft_choose_rotate(stack_a, &a_cost, 'a');
	ft_choose_rotate(stack_b, &b_cost, 'b');
	pa(stack_a, stack_b);
}

void	ft_moves(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	int		cheapest;
	int		a_cost;
	int		b_cost;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->a_cost) + ft_abs(tmp->b_cost) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->b_cost) + ft_abs(tmp->a_cost);
			a_cost = tmp->a_cost;
			b_cost = tmp->b_cost;
		}
		tmp = tmp->next;
	}
	ft_make_moves(stack_a, stack_b, a_cost, b_cost);
}
