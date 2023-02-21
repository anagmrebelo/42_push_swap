/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:07:09 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:23:04 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	error_check(char *arg)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(arg);
	while (i < len)
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}	
	if (ft_atoi(arg) == -1 && len > 2)
		return (0);
	return (1);
}

_Bool	duplicate_check(int argc, int *stack, int *temp, t_stru *mem)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 2))
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (stack[i] == stack[j])
			{	
				free_stacks(stack, temp, mem);
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
