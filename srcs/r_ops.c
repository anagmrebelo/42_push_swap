/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:44 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:23:04 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *stack, t_stru *mem)
{
	int	aux;
	int	counter;

	counter = mem->stack - 1;
	aux = stack[mem->stack - 1];
	while (counter > 0)
	{
		stack[counter] = stack[counter - 1];
		counter--;
	}
	stack[0] = aux;
	write(1, "ra\n", 3);
}

void	rb(int *temp, t_stru *mem)
{
	int	aux;
	int	counter;

	counter = mem->temp - 1;
	aux = temp[mem->temp - 1];
	while (counter > 0)
	{
		temp[counter] = temp[counter - 1];
		counter--;
	}
	temp[0] = aux;
	write(1, "rb\n", 3);
}

void	rr(int *stack, int *temp, t_stru *mem)
{	
	int	aux;
	int	counter;

	counter = mem->stack;
	aux = stack[mem->stack - 1];
	while (counter > 0)
	{
		stack[counter] = stack[counter - 1];
		counter--;
	}
	stack[0] = aux;
	counter = mem->temp;
	aux = temp[mem->temp - 1];
	while (counter > 0)
	{
		temp[counter] = temp[counter - 1];
		counter--;
	}
	temp[0] = aux;
	write(1, "rr\n", 3);
}
