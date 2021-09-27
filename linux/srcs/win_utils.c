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
	ft_clear_tab(&env->map);
	exit(1);
}

int	keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	if (key == UP || key == ARROW_UP)
	{	
		if (env->count % 2 == 0)
			move_player(env, &(env->player_back), 0, -1);
		else
			move_player(env, &(env->player_back2), 0, -1);
	}
	if (key == DOWN || key == ARROW_DOWN)
	{
		if (env->count % 2 == 0)
			move_player(env, &(env->player_front), 0, 1);
		else
			move_player(env, &(env->player_front2), 0, 1);
	}
	if (key == LEFT || key == ARROW_LEFT)
	{
		if (env->count % 2 == 0)
			move_player(env, &(env->player_left), -1, 0);
		else
			move_player(env, &(env->player_left2), -1, 0);
	}
	if (key == RIGHT || key == ARROW_RIGHT)
	{
		if (env->count % 2 == 0)
			move_player(env, &(env->player_right), 1, 0);
		else
			move_player(env, &(env->player_right2), 1, 0);
	}
	env->count++;
	printf("%i\n", env->count);
	return (0);
}
