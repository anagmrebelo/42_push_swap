/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:02:25 by arebelo           #+#    #+#             */
/*   Updated: 2022/04/04 10:51:49 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_stru
{
	int	stack;
	int	temp;
	int	max;
	int	bits;
	int	tracker;
}	t_stru;

_Bool			error_check(char *arg);
_Bool			duplicate_check(int argc, int *stack, int *temp, t_stru *mem);

_Bool			fill_stack(int *stack, t_stru *mem, char *arg, int *temp);
void			free_stacks(int *stack, int *temp, t_stru *mem);
int				check_position(int *stack, int i, t_stru *mem);

_Bool			is_sorted(int *stack, int size);
void			sort(int *stack, int *temp, t_stru *mem);
void			sa(int *stack, t_stru *mem);
void			sb(int *stack, t_stru *mem);
void			ss(int *stack, int *temp, t_stru *mem);
void			pa(int *stack, int *temp, t_stru *mem);
void			pb(int *stack, int *temp, t_stru *mem);
void			ra(int *stack, t_stru *mem);
void			rb(int *temp, t_stru *mem);
void			rr(int *stack, int *temp, t_stru *mem);
void			rra(int *stack, t_stru *mem);
void			rrb(int *temp, t_stru *mem);
void			rrr(int *stack, int *temp, t_stru *mem);

void			*ft_memmove_special(void *dst, void *src, size_t n);
void			*ft_memcpy_special(void *dst, void *src, size_t n);

void			sort_large_nb(int *stack, int *temp, t_stru *mem);
void			sort_small_nb(int *stack, int *temp, t_stru *mem);
void			sort_four(int *stack, int *temp, t_stru *mem);
void			sort_five(int *stack, int *temp, t_stru *mem);

_Bool			instructions(char *inst, int *stack, int *temp, t_stru *mem);

char			*get_next_line(int fd);
void			ft_putstr(char *str);
char			*ft_strndup(char *s1, size_t n);
char			*ft_strjoin(char *s1, char *s2);
char			*first_line(int fd, char buf[1], int *i);
char			*following_lines(int fd, char buf[1], int *i);
unsigned long	counter(char *buf, int j);

#endif
