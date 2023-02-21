/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:34 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/04 11:29:03 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

_Bool	instructions(char *inst, int *stack, int *temp, t_stru *mem)
{
	if (!ft_strncmp(inst, "sa\n", ft_strlen(inst)))
		sa(stack, mem);
	else if (!ft_strncmp(inst, "sb\n", ft_strlen(inst)))
		sb(temp, mem);
	else if (!ft_strncmp(inst, "ss\n", ft_strlen(inst)))
		ss(stack, temp, mem);
	else if (!ft_strncmp(inst, "pa\n", ft_strlen(inst)))
		pa(stack, temp, mem);
	else if (!ft_strncmp(inst, "pb\n", ft_strlen(inst)))
		pb(stack, temp, mem);
	else if (!ft_strncmp(inst, "ra\n", ft_strlen(inst)))
		ra(stack, mem);
	else if (!ft_strncmp(inst, "rb\n", ft_strlen(inst)))
		rb(temp, mem);
	else if (!ft_strncmp(inst, "rr\n", ft_strlen(inst)))
		rr(stack, temp, mem);
	else if (!ft_strncmp(inst, "rra\n", ft_strlen(inst)))
		rra(stack, mem);
	else if (!ft_strncmp(inst, "rrb\n", ft_strlen(inst)))
		rrb(temp, mem);
	else if (!ft_strncmp(inst, "rrr\n", ft_strlen(inst)))
		rrr(stack, temp, mem);
	else
		return (1);
	return (0);
}
