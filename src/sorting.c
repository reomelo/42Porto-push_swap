/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:27:39 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/06 18:00:55 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stacks *stacks)
{
	int	highest;

	highest = pos_highest_value(stacks);
	if (!highest)
		exec_ra(stacks);
	else if (1 == highest)
		exec_rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		exec_sa(stacks);
}

void	sort(t_stacks *stacks)
{
	while (!is_sorted(stacks) && stacks->size_a != 3)
	{
		if (stacks->stack_a[stacks->size_a - 1] < stacks->stack_a[0])
			exec_ra(stacks);
		else if (stacks->stack_a[0] > stacks->stack_a[1])
			exec_sa(stacks);
		else
			exec_pb(stacks);
	}
	if (stacks->size_a == 3)
		tiny_sort(stacks);
	while (stacks->size_b)
		push_back(stacks);
	adjust_a(stacks, pos_smallest_value(stacks), 'v');
}

void	push_back(t_stacks *stacks)
{
	int	i;
	int	pos;
	int	smallest_cost;
	int	current_cost;

	pos = 0;
	smallest_cost = cost(stacks, pos, stacks->stack_b[0]);
	i = 0;
	while (++i < stacks->size_b)
	{
		current_cost = cost(stacks, i, stacks->stack_b[i]);
		if (current_cost < smallest_cost)
		{
			smallest_cost = current_cost;
			pos = i;
		}
	}
	do_less_cost(stacks, pos);
	adjust_b(stacks, pos);
	exec_pa(stacks);
}

void	adjust_b(t_stacks *stacks, int pos)
{
	int	i;

	if (pos <= (stacks->size_b / 2))
	{
		i = -1;
		while (++i < pos)
			exec_rb(stacks);
	}
	else
	{
		i = stacks->size_b;
		while (--i >= pos)
			exec_rrb(stacks);
	}
}

void	adjust_a(t_stacks *stacks, int pos, char c)
{
	int	i;

	if (pos <= (stacks->size_a / 2))
	{
		i = -1;
		if (c == 'm')
			i = -2;
		while (++i < pos)
			exec_ra(stacks);
	}
	else
	{
		i = stacks->size_a;
		if (c == 'm')
			i--;
		while (--i >= pos)
			exec_rra(stacks);
	}
}
