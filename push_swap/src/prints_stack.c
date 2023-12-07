/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:09:22 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/19 16:10:19 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_lst *stack, char c)
{
	while (stack)
	{
		ft_printf("STACK %c: ", c);
		ft_printf("%d\n", stack -> value);
		stack = stack -> next;
	}
}
