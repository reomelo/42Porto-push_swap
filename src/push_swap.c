/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:23:37 by riolivei          #+#    #+#             */
/*   Updated: 2023/02/07 18:54:53 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate(t_stacks *stacks, int argc)
{
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->stack_a = (int *)malloc(stacks->size_a * sizeof(int));
	stacks->stack_b = (int *)malloc(stacks->size_a * sizeof(int));
	stacks->count = 0;
}

void	check_duplicates(t_stacks *stacks)
{
	int	i;
	int	x;

	i = -1;
	while (++i < stacks->size_a - 1)
	{
		x = i;
		while (++x < stacks->size_a)
		{	
			if (stacks->stack_a[i] == stacks->stack_a[x])
			{
				write(2, "Error\n", 6);
				free_all_stacks(stacks);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	get_values(t_stacks *stacks, char *argv, int pos)
{
	int			i;
	long int	res;

	if (argv[0] == '-')
		i = 0;
	else
		i = -1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
		{
			write(2, "Error\n", 6);
			free_all_stacks(stacks);
			exit(EXIT_FAILURE);
		}
	}
	res = ft_atoi(argv);
	if (res > 2147483647)
	{
		write(2, "Error\n", 6);
		free_all_stacks(stacks);
		exit(EXIT_FAILURE);
	}
	stacks->stack_a[pos] = res;
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stacks	stacks;

	if (argc <= 2)
		return (0);
	initiate(&stacks, argc);
	i = 0;
	while (++i < argc)
		get_values(&stacks, argv[i], i - 1);
	check_duplicates(&stacks);
	if (!is_sorted(&stacks))
	{
		if (stacks.size_a == 3)
			tiny_sort(&stacks);
		else
			sort(&stacks);
	}
	free_all_stacks(&stacks);
	return (0);
}

/* int	main(int argc, char *argv[])
{
	int			i;
	t_stacks	stacks;

	if (argc <= 2)
		return (0);
	initiate(&stacks, argc);
	i = 0;
	while (++i < argc)
		get_values(&stacks, argv[i], i - 1);
	check_duplicates(&stacks);
	if (!is_sorted(&stacks))
	{
		if (stacks.size_a == 3)
			tiny_sort(&stacks);
		else
			sort(&stacks);
	}
	ft_printf("SORTED: %d\n", is_sorted(&stacks));
	show_a(&stacks);
	show_b(&stacks);
	free_all_stacks(&stacks);
	ft_printf("Instructions: %d\n", stacks.count);
	return (0);
} */
