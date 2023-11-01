/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:35 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/06 16:16:13 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sb(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	stacks->count++;
	write(1, "sb\n", 3);
}

void	exec_pb(t_stacks *stacks)
{
	int	i;

	if (!stacks->stack_a)
		return ;
	stacks->size_b++;
	i = stacks->size_b;
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = stacks->stack_a[0];
	i = -1;
	while (++i < stacks->size_a - 1)
		stacks->stack_a[i] = stacks->stack_a[i + 1];
	stacks->count++;
	stacks->size_a--;
	write(1, "pb\n", 3);
}

void	exec_rrb(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->size_b;
	temp = stacks->stack_b[stacks->size_b - 1];
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = temp;
	stacks->count++;
	write(1, "rrb\n", 4);
}

void	exec_rb(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = -1;
	temp = stacks->stack_b[0];
	while (++i < stacks->size_b - 1)
		stacks->stack_b[i] = stacks->stack_b[i + 1];
	stacks->stack_b[stacks->size_b - 1] = temp;
	stacks->count++;
	write(1, "rb\n", 3);
}
