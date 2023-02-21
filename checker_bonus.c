/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:00 by arebelo           #+#    #+#             */
/*   Updated: 2022/03/29 19:26:37 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stru(t_stru *mem, int argc)
{
	mem->stack = argc - 1;
	mem->temp = 0;
	mem->max = argc - 1;
	mem->bits = 31;
	mem->tracker = 0;
}

int	main(int argc, char *argv[])
{
	static int	i;
	int			*stack;
	int			*temp;
	t_stru		*mem;

	if (argc < 1)
		return (1);
	stack = (int *)ft_calloc((argc - 1), sizeof(int));
	temp = (int *)ft_calloc((argc - 1), sizeof(int));
	mem = (t_stru *)malloc(sizeof(t_stru));
	if (!stack || !temp || !mem)
	{
		free_stacks(stack, temp, mem);
		return (1);
	}
	initialize_stru(mem, argc);
	while (++i < argc)
		if (!fill_stack(stack, mem, argv[i], temp))
			return (1);
	mem->stack = argc - 1;
	if (!duplicate_check(argc, stack, temp, mem))
		return (1);
	free_stacks(stack, temp, mem);
	return (0);
}
