# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 17:45:56 by lbirloue          #+#    #+#              #
#    Updated: 2023/11/24 12:23:34 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	push_swap.h

SRCS		=	main_push_swap.c \
				algo_diverse.c \
				algo_tab_a.c \
				algo_tab_b.c \
				algo_tab_same_time.c \
				algo.c \
				push_swap_utils.c \
				simple_dispach.c 


OBJS = $(SRCS:.c=.o)


all : $(NAME) 


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS)


fclean: clean
	rm -rf $(NAME) 

re: fclean all


.PHONY:		all clean fclean re