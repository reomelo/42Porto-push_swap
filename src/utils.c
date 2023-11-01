/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:50:39 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/07 17:07:44 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_highest_value(t_stacks *stacks)
{
	int	i;
	int	pos;
	int	max;

	max = stacks->stack_a[0];
	pos = 0;
	i = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->stack_a[i] > max)
		{
			max = stacks->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

int	pos_smallest_value(t_stacks *stacks)
{
	int	i;
	int	pos;
	int	min;

	min = stacks->stack_a[0];
	pos = 0;
	i = 0;
	while (++i < stacks->size_a)
	{
		if (stacks->stack_a[i] < min)
		{
			min = stacks->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

int	is_sorted(t_stacks *stacks)
{
	int	i;
	int	x;

	i = -1;
	while (++i < stacks->size_a - 1)
	{
		x = stacks->size_a;
		while (--x > i)
			if (stacks->stack_a[i] > stacks->stack_a[x])
				return (0);
	}
	return (1);
}

void	show_a(t_stacks *stacks)
{
	int	i;

	i = -1;
	ft_printf("A:");
	while (++i < stacks->size_a)
		ft_printf(" %d ", stacks->stack_a[i]);
	ft_printf("\n");
}

void	free_all_stacks(t_stacks *stacks)
{
	free(stacks->stack_b);
	free(stacks->stack_a);
}
