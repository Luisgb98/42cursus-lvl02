/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:16:58 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:55:33 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_lst **stack_a)
{
	revr(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_lst **stack_b)
{
	revr(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	revr(stack_a);
	revr(stack_b);
	ft_printf("rrr\n");
}

void	revr(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*last;
	t_lst	*second_last;

	last = ft_get_last_node(*stack);
	second_last = ft_get_second_last_node(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)-> next = tmp;
	second_last -> next = NULL;
}
