/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:22:43 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 13:22:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_player_position(t_env *env)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (env->map[++y])
	{
		while (env->map[y][++x])
		{
			if (env->map[y][x] == 'P')
			{
				env->player.posX = x;
				env->player.posY = y;
				draw_texture(env, (x * env->ppi), (y * env->ppi), &(env->player_front));
			}
		}
		x = -1;
	}
	return (0);
}

int	move_player_up(t_env *env)
{
	char	new_pos;

	new_pos = env->map[env->player.posY - 1][env->player.posX];
	if (!is_wall(new_pos))
	{
		if (!check_exit(env))
			draw_texture(env, (env->player.posX * env->ppi), \
			(env->player.posY * env->ppi), &(env->floor));
		env->player.posY--;
		draw_texture(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), &(env->player_back));
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}

int	move_player_down(t_env *env)
{
	char	new_pos;

	new_pos = env->map[env->player.posY + 1][env->player.posX];
	if (!is_wall(new_pos))
	{	
		if (!check_exit(env))
				draw_texture(env, (env->player.posX * env->ppi), \
				(env->player.posY * env->ppi), &(env->floor));
		env->player.posY++;
		draw_texture(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), &(env->player_front));
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}

int	move_player_west(t_env *env)
{
	char	new_pos;

	new_pos = env->map[env->player.posY][env->player.posX - 1];
	if (!is_wall(new_pos))
	{		
		if (!check_exit(env))
			draw_texture(env, (env->player.posX * env->ppi), \
			(env->player.posY * env->ppi), &(env->floor));
		env->player.posX--;
		draw_texture(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), &(env->player_left));
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}

int	move_player_east(t_env *env)
{
	char	new_pos;

	new_pos = env->map[env->player.posY][env->player.posX + 1];
	if (!is_wall(new_pos))
	{
		if (!check_exit(env))
			draw_texture(env, (env->player.posX * env->ppi), \
			(env->player.posY * env->ppi), &(env->floor));
		env->player.posX++;
		draw_texture(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), &(env->player_right));
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}
