/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:27:49 by lguisado          #+#    #+#             */
/*   Updated: 2023/11/13 19:30:50 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_lst
{
	int				value;
	int				last_pos;
	int				position;
	int				target_pos;
	int				a_cost;
	int				b_cost;
	struct s_lst	*next;
}	t_lst;

typedef struct s_costs
{
	int	a_cost;
	int	b_cost;
}	t_costs;

/*    --    algorithm.c    --    */
void	ft_algorithm(t_lst **stack_a, t_lst **stack_b, int total_size);
void	ft_push_all_less_three_to_b(t_lst **stack_a,
			t_lst **stack_b, int total_size);
void	ft_set_in_order(t_lst **stack_a);
int		ft_abs(int n);

/*    --    check_errors.c    --    */
void	ft_error(void);
int		ft_check_dup(t_lst *stack);
int		ft_check_number(char *stack);
int		ft_check_max(char *stack);

/*    --    moves.c    --    */
void	ft_find_cost(t_lst *stack_a, t_lst *stack_b);
void	ft_both_rotate(t_lst **stack_a, t_lst **stack_b,
			t_costs costs, char *str);
void	ft_moves(t_lst **stack_a, t_lst **stack_b);
void	ft_make_moves(t_lst **stack_a, t_lst **stack_b, int a_cost, int b_cost);
void	ft_choose_rotate(t_lst **stack, int *cost, char c);

/*    --    node.c    --    */
void	ft_add_node(t_lst **stack, t_lst *new_node);
t_lst	*ft_get_last_node(t_lst *stack);
t_lst	*ft_get_second_last_node(t_lst *stack);
int		ft_find_highest_last_pos(t_lst *stack);
int		ft_find_lowest_last_pos(t_lst **stack);

/*    --    operations_p.c    --    */
void	pa(t_lst **stack_a, t_lst **stack_b);
void	pb(t_lst **stack_a, t_lst **stack_b);
void	p(t_lst **src, t_lst **dst);

/*    --    operations_r.c    --    */
void	ra(t_lst **stack_a);
void	rb(t_lst **stack_b);
void	rr(t_lst **stack_a, t_lst **stack_b);
void	r(t_lst **stack);

/*    --    operations_rr.c    --    */
void	rra(t_lst **stack_a);
void	rrb(t_lst **stack_b);
void	rrr(t_lst **stack_a, t_lst **stack_b);
void	revr(t_lst **stack);

/*    --    operations_s.c    --    */
void	sa(t_lst **stack_a);
void	sb(t_lst **stack_b);
void	ss(t_lst **stack_a, t_lst **stack_b);
void	s(t_lst *stack);

/*    --    push_swap.c    --    */
t_lst	*ft_init(int argc, char **argv);
t_lst	*list_stacks_one_argc(char *argv);

/*    --    print_stacks.c    --    */
void	ft_print_stack(t_lst *stack, char c);

/*    --    sort.c    --    */
void	ft_sort(t_lst **stack_a, t_lst **stack_b, int total_size);
void	ft_sorting_three(t_lst **stack);
void	ft_swap(int *i, int *j);
int		ft_is_sorted(t_lst *stack);
void	ft_bubble_sort(t_lst *stack);

/*    --    stack.c    --    */
t_lst	*list_stacks(char **argv);
t_lst	*ft_create_stack(int n);
t_lst	*ft_copy_stack(t_lst *stack);
int		ft_size_stack(t_lst *stack);
void	ft_get_last_pos(t_lst *stack_a);

/*    --    target.c    --    */
void	ft_get_pos(t_lst *stack);
int		ft_get_target(t_lst *stack_a, int b_idx,
			int target_idx, int target_pos);
void	ft_get_target_position(t_lst **stack_a, t_lst *stack_b);

#endif