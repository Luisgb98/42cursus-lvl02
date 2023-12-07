/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:06 by lguisado          #+#    #+#             */
/*   Updated: 2023/06/23 14:28:17 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_lst **stack_a, t_lst **stack_b, int total_size)
{
	if (total_size == 2 && !ft_is_sorted(*stack_a))
		sa(stack_a);
	else if (total_size == 3)
		ft_sorting_three(stack_a);
	else if (total_size > 3 && !ft_is_sorted(*stack_a))
		ft_algorithm(stack_a, stack_b, total_size);
}

void	ft_sorting_three(t_lst **stack)
{
	int		highest_last_pos;

	highest_last_pos = ft_find_highest_last_pos(*stack);
	if ((*stack)->last_pos == highest_last_pos)
		ra(stack);
	else if ((*stack)->next->last_pos == highest_last_pos)
		rra(stack);
	if ((*stack)->last_pos > (*stack)->next->last_pos)
		sa(stack);
}

void	ft_swap(int *i, int *j)
{
	int	aux;

	aux = *i;
	*i = *j;
	*j = aux;
}

int	ft_is_sorted(t_lst *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> value > stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	ft_bubble_sort(t_lst *stack)
{
	t_lst	*current;
	t_lst	*tmp;

	tmp = NULL;
	while (!ft_is_sorted(stack))
	{
		current = stack;
		while (current->next != tmp)
		{
			if (current->value > current->next->value)
				ft_swap(&current->value, &current->next->value);
			current = current->next;
		}
		tmp = current;
	}
}
