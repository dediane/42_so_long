# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 13:40:58 by ddecourt          #+#    #+#              #
#    Updated: 2021/06/21 17:00:08 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft_cmd:
			make -C libft
			mv libft/libft.a .

SRCS	= so_long.c \

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

NAME	= so_long

HEADER	= minilibx-linux/mlx.h

OBJS	= ${SRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -I includes *.c -L /usr/local/lib -L./ -lft -lmlx -lXext -lX11 -lm -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
