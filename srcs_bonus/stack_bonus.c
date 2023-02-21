/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:03:12 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:47:46 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	fill_stack(int *stack, t_stru *mem, char *arg, int *temp)
{
	if (!error_check(arg))
	{
		write(2, "Error\n", 6);
		free_stacks(stack, temp, mem);
		return (0);
	}
	stack[mem->stack - 1] = ft_atoi(arg);
	mem->stack--;
	return (1);
}

_Bool	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_stacks(int *stack, int *temp, t_stru *mem)
{
	if (stack)
		free(stack);
	if (temp)
		free(temp);
	if (mem)
		free(mem);
}
