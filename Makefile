# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 00:12:55 by anarebelo         #+#    #+#              #
#    Updated: 2023/02/22 00:54:25 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME		= push_swap
NAME_BONUS	= checker

# FILES
# **************************************************************************** #
SRCS		= push_swap.c\
			errors.c\
			stack.c\
			s_ops.c\
			p_ops.c\
			r_ops.c\
			rr_ops.c\
			sort_large.c\
			sort_small_nb.c

SRCS_BONUS	= checker_bonus.c\
			  s_ops_bonus.c\
			  p_ops_bonus.c\
			  r_ops_bonus.c\
			  rr_ops_bonus.c\
			  errors_bonus.c\
			  instructions_bonus.c\
			  stack_bonus.c\
			  get_next_line_utils.c\
			  get_next_line.c\

OBJS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
DEPS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}
OBJS_BONUS		=${addprefix ${OBJS_DIR}, ${SRCS_BONUS:.c=.o}}
DEPS_BONUS		=${addprefix ${OBJS_DIR}, ${SRCS_BONUS:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
SRCS_BONUS_DIR		= srcs_bonus/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I includes -I libft
LIB_EXE				= libft/libft.a

# COMPILATION
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror 
RM					= rm -rf

# RULES
# **************************************************************************** #
all:		make_libft ${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

$(OBJS_DIR)%.o:	$(SRCS_BONUS_DIR)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

make_libft:
		@$(MAKE) -C ./libft

${NAME}:	${OBJS}
		${LINK} ${CFLAGS} ${OBJS} ${LIB_EXE} -o ${NAME}

bonus:	make_libft ${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
		${LINK} ${CFLAGS} ${LIB_EXE} ${OBJS_BONUS} -o ${NAME_BONUS}

clean:		
		${RM} ${OBJS_DIR}
		$(MAKE) -C ./libft clean

fclean:		clean
		${RM} ${NAME} ${NAME_BONUS}
		$(MAKE) -C ./libft fclean

re:		fclean all

 -include ${DEPS}
 -include ${DEPS_BONUS}

.PHONY:		all clean fclean re
