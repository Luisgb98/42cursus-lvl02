/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:13:17 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:55:47 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_lst **stack_a)
{
	r(stack_a);
	ft_printf("ra\n");
}

void	rb(t_lst **stack_b)
{
	r(stack_b);
	ft_printf("rb\n");
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	r(stack_a);
	r(stack_b);
	ft_printf("rr\n");
}

void	r(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = *stack;
	*stack = (*stack)-> next;
	last = ft_get_last_node(*stack);
	tmp -> next = 0;
	last -> next = tmp;
}
