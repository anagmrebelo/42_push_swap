/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:48:12 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/29 19:26:52 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
