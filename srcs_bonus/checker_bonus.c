/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:00 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:47:46 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stru(t_stru *mem, int argc)
{
	mem->stack = argc - 1;
	mem->temp = 0;
	mem->max = argc - 1;
	mem->bits = 31;
	mem->tracker = 0;
}

static void	verify_bonus(int *stack, int *temp, t_stru *mem)
{
	char	*nl;

	nl = get_next_line(0);
	if (nl && is_sorted(stack, mem->max))
	{
		write(2, "Error\n", 6);
		free(nl);
		return ;
	}
	while (nl)
	{
		if (instructions(nl, stack, temp, mem))
		{
			write(2, "Error\n", 6);
			free(nl);
			return ;
		}
		free(nl);
		nl = get_next_line(0);
	}
	if (is_sorted(stack, mem->max) && !mem->temp)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	static int	i;
	int			*stack;
	int			*temp;
	t_stru		*mem;

	if (argc < 2)
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
	verify_bonus(stack, temp, mem);
	free_stacks(stack, temp, mem);
	return (0);
}
