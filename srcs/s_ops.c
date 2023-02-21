/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:48:24 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:23:04 by anarebelo        ###   ########.fr       */
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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
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
	if (mem->stack > 1 || mem->temp > 1)
		write(1, "ss\n", 3);
}
