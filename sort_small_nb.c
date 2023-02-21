/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:28:50 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/29 18:46:17 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_small_nb(int *stack, int *temp, t_stru *mem)
{
	if (stack[0] > stack[1] && stack[1] > stack[2])
		return ;
	if (stack[0] < stack[1] && stack[0] > stack[2])
	{
		pb(stack, temp, mem);
		sa(stack, mem);
		pa(stack, temp, mem);
	}
	else if (stack[2] > stack[1] && stack[2] < stack[0])
		sa(stack, mem);
	else if (stack[2] < stack [1] && stack[2] > stack[0])
		rra(stack, mem);
	else if (stack[0] > stack[1] && stack[0] < stack[2])
		ra(stack, mem);
	else
	{
		ra(stack, mem);
		sa(stack, mem);
	}
}

static void	find_position_push(int pos, int *stack, int *temp, t_stru *mem)
{
	int	i;
	int	counter;

	i = mem->stack;
	counter = 0;
	while (i && pos != stack[i - 1])
	{
		i--;
		counter++;
	}
	if (counter > (mem->stack) / 2)
	{
		counter = mem->stack - counter;
		while (counter)
		{
			rra(stack, mem);
			counter--;
		}
		pb(stack, temp, mem);
		return ;
	}
	while (counter--)
		ra(stack, mem);
	pb(stack, temp, mem);
}

void	sort_four(int *stack, int *temp, t_stru *mem)
{
	find_position_push(0, stack, temp, mem);
	sort_small_nb(stack, temp, mem);
	pa(stack, temp, mem);
}

void	sort_five(int *stack, int *temp, t_stru *mem)
{
	find_position_push(0, stack, temp, mem);
	find_position_push(1, stack, temp, mem);
	sort_small_nb(stack, temp, mem);
	pa(stack, temp, mem);
	pa(stack, temp, mem);
}
