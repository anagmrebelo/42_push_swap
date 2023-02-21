SRCS		= push_swap.c\
		errors.c\
		stack.c\
		s_ops.c\
		p_ops.c\
		r_ops.c\
		rr_ops.c\
		sort_large.c\
		sort_small_nb.c

SRCS_BONUS	= bonus/checker_bonus.c\
			  bonus/s_ops_bonus.c\
			  bonus/p_ops_bonus.c\
			  bonus/r_ops_bonus.c\
			  bonus/rr_ops_bonus.c\
			  bonus/errors_bonus.c\
			  bonus/instructions_bonus.c\
			  bonus/stack_bonus.c\
			  bonus/get_next_line_utils.c\
			  bonus/get_next_line.c\

INCLUDES	= get_next_line.h\
			  includes/push_swap.h


OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= push_swap
NAME_BONUS	= checker

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		$(MAKE) -C ./libft all
		${CC} ${CFLAGS} ${SRCS} -o ${NAME} libft/libft.a

bonus:	${OBJS_BONUS}
		$(MAKE) -C ./libft all
		${CC} ${CGLAGS} ${SRCS_BONUS} -o ${NAME_BONUS} libft/libft.a

clean:		
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		$(MAKE) -C ./libft clean

fclean:		clean
		${RM} ${NAME} ${NAME_BONUS}
		$(MAKE) -C ./libft fclean

re:		fclean all

.PHONY:		all clean fclean re
