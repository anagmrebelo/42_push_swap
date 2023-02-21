/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:48:24 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:47:46 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack, t_stru *mem)
{
	int	aux;

	if (mem->stack > 1)
	{
		aux = stack[mem->stack - 1];
		stack[mem->stack - 1] = stack[mem->stack - 2];
		stack[mem->stack - 2] = aux;
	}
}

void	sb(int *stack, t_stru *mem)
{
	int	aux;

	if (mem->temp > 1)
	{
		aux = stack[mem->temp - 1];
		stack[mem->temp - 1] = stack[mem->temp - 2];
		stack[mem->temp - 2] = aux;
	}
}

void	ss(int *stack, int *temp, t_stru *mem)
{	
	int	aux;

	if (mem->stack > 1)
	{
		aux = stack[mem->stack - 1];
		stack[mem->stack - 1] = stack[mem->stack - 2];
		stack[mem->stack - 2] = aux;
	}
	if (mem->temp > 1)
	{
		aux = temp[mem->temp - 1];
		temp[mem->temp - 1] = temp[mem->temp - 2];
		temp[mem->temp - 2] = aux;
	}
}
