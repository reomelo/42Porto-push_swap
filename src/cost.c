/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:58:53 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/06 18:07:02 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_stacks *stacks, int pos, int value)
{
	int	count;
	int	target_pos;
	int	target_pos2;

	count = cost_value(stacks, pos, 'b');
	if (has_bigger(stacks, value))
	{
		target_pos = search_value_pos(stacks, value);
		count += cost_value(stacks, target_pos, 'a');
	}
	else
	{
		target_pos = pos_smallest_value(stacks);
		target_pos2 = pos_highest_value(stacks);
		if (cost_value(stacks, target_pos, 'a')
			> cost_highest(stacks, target_pos2))
			count += cost_highest(stacks, target_pos2);
		else
			count += cost_value(stacks, target_pos, 'a');
	}
	return (count);
}

int	cost_value(t_stacks *stacks, int pos, char c)
{
	int	count;
	int	size;

	size = stacks->size_b;
	if (c == 'a')
		size = stacks->size_a;
	count = pos;
	if (pos > (size / 2))
		count = size - pos;
	return (count);
}

int	cost_highest(t_stacks *stacks, int pos)
{
	int	count;

	count = pos + 1;
	if (pos > (stacks->size_a / 2))
		count = stacks->size_a - pos - 1;
	return (count);
}

void	do_less_cost(t_stacks *stacks, int pos)
{
	int	target_pos;
	int	target_pos2;

	if (has_bigger(stacks, stacks->stack_b[pos]))
		adjust_a(stacks, search_value_pos(stacks, stacks->stack_b[pos]), 'v');
	else
	{
		target_pos = pos_smallest_value(stacks);
		target_pos2 = pos_highest_value(stacks);
		if (cost_value(stacks, target_pos, 'a')
			> cost_highest(stacks, target_pos2))
			adjust_a(stacks,
				search_value_pos(stacks, stacks->stack_b[pos]), 'm');
		else
			adjust_a(stacks,
				search_value_pos(stacks, stacks->stack_b[pos]), 'v');
	}
}
