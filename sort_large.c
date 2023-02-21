/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:29:36 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/29 12:32:17 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	check_position(int *stack, int i, t_stru *mem)
{
	int	counter;
	int	j;

	j = 0;
	counter = 0;
	while (j < mem->max)
	{
		if (stack[i] > stack[j])
			counter++;
		j++;
	}
	return (counter);
}

static void	radix_sort(int *stack, int *temp, t_stru *mem)
{
	int	i;

	i = mem->max - 1;
	while (i >= 0)
	{
		if (!((stack[mem->stack - 1] >> mem->tracker) & 1))
			pb(stack, temp, mem);
		else
			ra(stack, mem);
		i--;
	}
	mem->tracker++;
	while (mem->temp)
		pa(stack, temp, mem);
}

void	sort_large_nb(int *stack, int *temp, t_stru *mem)
{
	while (!((mem->max - 1) >> mem->bits & 1) && mem->bits >= 0)
		mem->bits--;
	mem->bits += 1;
	while (mem->bits--)
	{
		radix_sort(stack, temp, mem);
		if (is_sorted(stack, mem->max))
			break ;
	}
}
