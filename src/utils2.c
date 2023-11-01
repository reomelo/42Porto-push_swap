/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:50:39 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/06 18:34:38 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_bigger(t_stacks *stacks, int value)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		if (stacks->stack_a[i] > value)
			return (1);
	return (0);
}

int	search_value_pos(t_stacks *stacks, int value)
{
	int	i;
	int	pos;
	int	biggest;

	i = -1;
	biggest = first_big(stacks, value);
	pos = pos_first_big(stacks, biggest);
	while (++i < stacks->size_a)
	{
		if (stacks->stack_a[i] > value && stacks->stack_a[i] < biggest)
		{
			biggest = stacks->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

int	first_big(t_stacks *stacks, int value)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		if (stacks->stack_a[i] > value)
			return (stacks->stack_a[i]);
	return (0);
}

int	pos_first_big(t_stacks *stacks, int value)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		if (stacks->stack_a[i] == value)
			return (i);
	return (0);
}
