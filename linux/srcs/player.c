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
	while (env->map[++y][0])
	{
		while (env->map[y][++x])
		{
			if (env->map[y][x] == 'P')
			{
				env->player.posX = x;
				env->player.posY = y;
				draw_texture(env, (x * env->ppi), \
				(y * env->ppi), &(env->player_left));
			}
		}
		x = -1;
	}
	return (0);
}

int	move_player(t_env *env, t_img *img, int x, int y)
{
	char	new_pos;

	new_pos = env->map[env->player.posY + y][env->player.posX + x];
	if (!is_wall(new_pos))
	{
		if (!check_exit(env))
			draw_texture(env, (env->player.posX * env->ppi), \
			(env->player.posY * env->ppi), &(env->floor));
		env->player.posY += y;
		env->player.posX += x;
		draw_texture(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), img);
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}
