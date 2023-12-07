/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:01 by lguisado          #+#    #+#             */
/*   Updated: 2023/11/13 19:58:00 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_b = NULL;
	if (!argv[1])
		return (0);
	stack_a = ft_init(argc, argv);
	if (ft_check_dup(stack_a) == 0)
		ft_error();
	ft_get_last_pos(stack_a);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b, ft_size_stack(stack_a));
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a -> next;
	}
}

t_lst	*ft_init(int argc, char **argv)
{
	if (argc == 2)
		return (list_stacks_one_argc(argv[1]));
	else
		return (list_stacks(argv));
}

t_lst	*list_stacks_one_argc(char *argv)
{
	t_lst	*stack_a;
	char	*split;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	while (argv[i])
	{
		n = 0;
		split = ft_calloc(ft_strlen(argv), sizeof(char));
		while (argv[i] != ' ' && argv[i])
			split[n++] = argv[i++];
		if (argv[i] == ' ')
			i++;
		if (ft_check_number(split) == 0 || ft_check_max(split) == 0)
			ft_error();
		if (j++ == 0)
			stack_a = ft_create_stack(ft_atoi(split));
		else
			ft_add_node(&stack_a, ft_create_stack(ft_atoi(split)));
		free(split);
	}
	return (stack_a);
}
