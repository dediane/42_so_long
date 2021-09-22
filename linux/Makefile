# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 13:40:58 by ddecourt          #+#    #+#              #
#    Updated: 2021/09/21 22:38:05 by ddecourt@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= so_long.c \
		  srcs/mlx_utils.c \
		  srcs/win_utils.c \
		  srcs/check_map.c \
		  srcs/error.c \

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

HEADER	= mlx/mlx.h 

CC		= clang

CFLAGS	= -g -Wall -Wextra -Werror

RM = rm -f

.c .o:
	$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -O3 -c $< -o $@ 

$(NAME): $(OBJS)
		make -C libft
		make -C mlx
		$(CC) $(CFLAGS) $(OBJS)  -Imlx -Lmlx -lmlx -I -L./libft/ -Imlx -lXext -lX11 -lm ./libft/libft.a -o ${NAME}

all:	${NAME}

clean:
		make clean -C libft
		make clean -C mlx
		${RM} ${OBJS}

fclean: clean	
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
