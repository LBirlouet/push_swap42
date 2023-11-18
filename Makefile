# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 17:45:56 by lbirloue          #+#    #+#              #
#    Updated: 2023/11/18 10:51:54 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	 push_swap.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	push_swap.h

SRCS		=	main.c \
				push_swap_utils.c \
				algo_tab_a.c \
				algo_tab_b.c \
				algo_tab_same_time.c \
				algo_diverse.c \
				simple_dispach.c \


OBJS		=	${SRCS:.c=.o}



all:		${NAME}


${NAME}:	${OBJS}
	ar -rc ${NAME} ${OBJS}


%.o:		%.c
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


clean:
	rm -f ${OBJS}


fclean:		clean
	rm -f ${NAME}


re:			fclean all


.PHONY:		all clean fclean re 