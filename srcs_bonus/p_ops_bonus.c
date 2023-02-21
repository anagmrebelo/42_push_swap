/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:48:12 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:47:46 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *stack, int *temp, t_stru *mem)
{	
	if (mem->temp > 0)
	{
		stack[mem->stack] = temp[(mem->temp - 1)];
		mem->stack++;
		mem->temp--;
	}
}

void	pb(int *stack, int *temp, t_stru *mem)
{
	if (mem->stack > 0)
	{
		temp[mem->temp] = stack[(mem->stack - 1)];
		mem->temp++;
		mem->stack--;
	}
}
