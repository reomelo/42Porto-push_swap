/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:42:52 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/06 16:08:13 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	stacks->count++;
	write(1, "sa\n", 3);
}

void	exec_pa(t_stacks *stacks)
{
	int	i;

	if (!stacks->stack_b)
		return ;
	stacks->size_a++;
	i = stacks->size_a;
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = stacks->stack_b[0];
	i = -1;
	while (++i < stacks->size_b - 1)
		stacks->stack_b[i] = stacks->stack_b[i + 1];
	stacks->count++;
	stacks->size_b--;
	write(1, "pa\n", 3);
}

void	exec_rra(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->size_a;
	temp = stacks->stack_a[stacks->size_a - 1];
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = temp;
	stacks->count++;
	write(1, "rra\n", 4);
}

void	exec_ra(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = -1;
	temp = stacks->stack_a[0];
	while (++i < stacks->size_a - 1)
		stacks->stack_a[i] = stacks->stack_a[i + 1];
	stacks->stack_a[stacks->size_a - 1] = temp;
	stacks->count++;
	write(1, "ra\n", 3);
}
