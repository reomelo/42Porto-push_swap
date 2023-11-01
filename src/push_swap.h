/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:23:54 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:54 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stacks{
	int	*stack_a;
	int	*stack_b;
	int	*order;
	int	count;
	int	size_a;
	int	size_b;
}				t_stacks;

//SORTING.C
void	tiny_sort(t_stacks *stacks);
void	sort(t_stacks *stacks);
void	push_back(t_stacks *stacks);
void	adjust_b(t_stacks *stacks, int pos);
void	adjust_a(t_stacks *stacks, int pos, char c);
void	show_a(t_stacks *stacks);

//SORT_A.C
void	exec_sa(t_stacks *stacks);
void	exec_pa(t_stacks *stacks);
void	exec_ra(t_stacks *stacks);
void	exec_rra(t_stacks *stacks);

//SORT_B.C
void	exec_sb(t_stacks *stacks);
void	exec_pb(t_stacks *stacks);
void	exec_rb(t_stacks *stacks);
void	exec_rrb(t_stacks *stacks);

//UTILS.C
int		is_sorted(t_stacks *stacks);
int		pos_highest_value(t_stacks *stacks);
int		pos_smallest_value(t_stacks *stacks);
void	free_all_stacks(t_stacks *stacks);

//UTILS2.C
int		has_bigger(t_stacks *stacks, int value);
int		search_value_pos(t_stacks *stacks, int value);
int		first_big(t_stacks *stacks, int value);
int		pos_first_big(t_stacks *stacks, int value);

//COST.C
int		cost(t_stacks *stacks, int pos, int value);
int		cost_value(t_stacks *stacks, int pos, char c);
int		cost_highest(t_stacks *stacks, int pos);
void	do_less_cost(t_stacks *stacks, int pos);

#endif