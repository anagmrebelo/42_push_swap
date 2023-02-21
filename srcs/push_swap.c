/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:00 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:47:49 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stru(t_stru *mem, int argc)
{
	mem->stack = argc - 1;
	mem->temp = 0;
	mem->max = argc - 1;
	mem->bits = 31;
	mem->tracker = 0;
}

int	main(int argc, char *argv[])
{
	static int	i;
	int			*stack;
	int			*temp;
	t_stru		*mem;

	if (argc < 1)
		return (1);
	stack = (int *)ft_calloc((argc - 1), sizeof(int));
	temp = (int *)ft_calloc((argc - 1), sizeof(int));
	mem = (t_stru *)malloc(sizeof(t_stru));
	if (!stack || !temp || !mem)
	{
		free_stacks(stack, temp, mem);
		return (1);
	}
	initialize_stru(mem, argc);
	while (++i < argc)
		if (!fill_stack(stack, mem, argv[i], temp))
			return (1);
	mem->stack = argc - 1;
	if (!duplicate_check(argc, stack, temp, mem))
		return (1);
	sort(stack, temp, mem);
	free_stacks(stack, temp, mem);
	return (0);
}

void	sort(int *stack, int *temp, t_stru *mem)
{
	int	i;

	if (is_sorted(stack, mem->max))
		return ;
	i = -1;
	while (++i < mem->max)
		temp[i] = check_position(stack, i, mem);
	ft_memcpy(stack, temp, mem->max * sizeof(int));
	if (mem->max == 2)
	{
		sa(stack, mem);
		return ;
	}
	else if (mem->max == 3)
		sort_small_nb(stack, temp, mem);
	else if (mem->max == 4)
		sort_four(stack, temp, mem);
	else if (mem->max == 5)
		sort_five(stack, temp, mem);
	else
		sort_large_nb(stack, temp, mem);
}
