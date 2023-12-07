/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:36:14 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:55:08 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_lst **stack_a)
{
	s(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_lst **stack_b)
{
	s(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	s(*stack_a);
	s(*stack_b);
	ft_printf("ss\n");
}

void	s(t_lst *stack)
{
	if (stack == 0 || stack -> next == 0)
		return ;
	ft_swap(&stack -> value, &stack -> next -> value);
	ft_swap(&stack -> last_pos, &stack -> next -> last_pos);
}
