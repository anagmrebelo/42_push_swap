/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:50:03 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/29 19:27:25 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(int *stack, t_stru *mem)
{
	int	aux;
	int	counter;

	counter = 0;
	aux = stack[0];
	while (counter < mem->stack)
	{
		stack[counter] = stack[counter + 1];
		counter++;
	}
	stack[mem->stack - 1] = aux;
}

void	rrb(int *temp, t_stru *mem)
{
	int	aux;
	int	counter;

	counter = 0;
	aux = temp[0];
	while (counter < mem->temp)
	{
		temp[counter] = temp[counter + 1];
		counter++;
	}
	temp[mem->temp - 1] = aux;
}

void	rrr(int *stack, int *temp, t_stru *mem)
{
	int	aux;
	int	counter;

	counter = 0;
	aux = stack[0];
	while (counter < mem->stack)
	{
		stack[counter] = stack[counter + 1];
		counter++;
	}
	stack[mem->stack - 1] = aux;
	counter = 0;
	aux = temp[0];
	while (counter < mem->temp)
	{
		temp[counter] = temp[counter + 1];
		counter++;
	}
	temp[mem->temp - 1] = aux;
}
