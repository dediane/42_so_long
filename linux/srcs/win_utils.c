/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:41:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/12 21:32:04 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	quit_program(t_env *env)
{
	write(1, "Goodbye!", 7);
	ft_clear_tab(&env->map);
	if (&(env->floor) != NULL)
		destroy_all_images(env);
	mlx_destroy_image(env->params.mlx, env->img.img);
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	mlx_destroy_display(env->params.mlx);
	free(env->params.mlx);
	exit(1);
}

int	move_1(int key, t_env *env)
{
	if (key == UP || key == ARROW_UP)
		move_player(env, &(env->player_back), 0, -1);
	if (key == DOWN || key == ARROW_DOWN)
		move_player(env, &(env->player_front), 0, 1);
	if (key == LEFT || key == ARROW_LEFT)
		move_player(env, &(env->player_left), -1, 0);
	if (key == RIGHT || key == ARROW_RIGHT)
		move_player(env, &(env->player_right), 1, 0);
	return (0);
}

int	move_2(int key, t_env *env)
{
	if (key == UP || key == ARROW_UP)
		move_player(env, &(env->player_back2), 0, -1);
	if (key == DOWN || key == ARROW_DOWN)
		move_player(env, &(env->player_front2), 0, 1);
	if (key == LEFT || key == ARROW_LEFT)
		move_player(env, &(env->player_left2), -1, 0);
	if (key == RIGHT || key == ARROW_RIGHT)
		move_player(env, &(env->player_right2), 1, 0);
	return (0);
}

int	keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	if (env->count % 2 == 0)
		move_1(key, env);
	else
		move_2(key, env);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT || \
	key == ARROW_DOWN || key == ARROW_UP || key == ARROW_LEFT || \
	key == ARROW_RIGHT)
	{
		env->count++;
		printf("%i\n", env->count);
	}
	return (0);
}
