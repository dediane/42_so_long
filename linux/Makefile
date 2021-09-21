# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 13:40:58 by ddecourt          #+#    #+#              #
#    Updated: 2021/09/21 19:57:26 by ddecourt@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

lib_cmd:
			make -C libft
			make -C minilibx

SRCS	= so_long.c \
		  srcs/mlx_utils.c \
		  srcs/win_utils.c \
		  srcs/check_map.c \
		  srcs/error.c \

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

NAME	= so_long

HEADER	= minilibx/mlx.h 

OBJS	= ${SRCS:.c=.o}


%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@ 

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -I -L./minilibx/ -L./libft/ -lft -lmlx -lXext -lX11 -lm -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
