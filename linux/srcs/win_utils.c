/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:41:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 16:50:38 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	quit_program(t_env *env)
{
	write(1, "Goodbye!", 7);
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	exit(1);
}

int	keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	if (key == UP || key == ARROW_UP)
	{
		move_player_up(env);
		printf("UP\n");
	}
	if (key == DOWN || key == ARROW_DOWN)
	{
		move_player_down(env);
		printf("DOWN\n");
	}
	if (key == LEFT || key == ARROW_LEFT)
	{
		move_player_west(env);
		printf("LEFT\n");
	}
	if (key == RIGHT || key == ARROW_RIGHT)
	{
		move_player_east(env);
		printf("RIGHT\n");
	}
	if (key == SPACE)
		printf("SPACE\n");
	return (0);
}
