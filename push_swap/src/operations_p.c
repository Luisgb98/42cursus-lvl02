/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:45:11 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/13 16:02:02 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_lst **stack_a, t_lst **stack_b)
{
	p(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_lst **stack_a, t_lst **stack_b)
{
	p(stack_a, stack_b);
	ft_printf("pb\n");
}

void	p(t_lst **src, t_lst **dst)
{
	t_lst	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}
