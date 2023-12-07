/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:42:34 by lguisado          #+#    #+#             */
/*   Updated: 2023/11/13 19:51:38 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*list_stacks(char **argv)
{
	t_lst		*stack_a;
	int			i;

	i = 0;
	while (argv[++i])
	{
		if (ft_check_number(argv[i]) == 0 || ft_check_max(argv[i]) == 0)
			ft_error();
		if (i == 1)
			stack_a = ft_create_stack(ft_atoi(argv[i]));
		else
			ft_add_node(&stack_a, ft_create_stack(ft_atoi(argv[i])));
	}
	return (stack_a);
}

t_lst	*ft_create_stack(int n)
{
	t_lst	*stack;

	stack = ft_calloc(1, sizeof(t_lst));
	if (!stack)
		return (NULL);
	stack -> value = n;
	stack -> last_pos = 0;
	stack -> position = -1;
	stack -> target_pos = -1;
	stack -> a_cost = -1;
	stack -> b_cost = -1;
	stack -> next = NULL;
	return (stack);
}

int	ft_size_stack(t_lst *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}

t_lst	*ft_copy_stack(t_lst *stack)
{
	t_lst	*tmp;
	int		i;

	i = 1;
	while (stack)
	{
		if (i == 1)
			tmp = ft_create_stack(stack -> value);
		else
			ft_add_node(&tmp, ft_create_stack(stack -> value));
		stack = stack -> next;
		i++;
	}
	return (tmp);
}

void	ft_get_last_pos(t_lst *stack_a)
{
	t_lst	*tmp;
	t_lst	*first_node;
	int		i;

	tmp = ft_copy_stack(stack_a);
	ft_bubble_sort(tmp);
	first_node = stack_a;
	i = 1;
	while (tmp)
	{
		if (stack_a -> value == tmp -> value)
		{
			stack_a -> last_pos = i++;
			stack_a = first_node;
			free(tmp);
			tmp = tmp -> next;
		}
		else
			stack_a = stack_a -> next;
	}
}
