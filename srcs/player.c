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
				env->player.pos_x = x;
				env->player.pos_y = y;
				draw_texture(env, (x * env->ppi), \
				(y * env->ppi), &(env->player_front));
			}
		}
		x = -1;
	}
	return (0);
}

int	move_player(t_env *env, t_img *img, int x, int y)
{
	char	new_pos;

	new_pos = env->map[env->player.pos_y + y][env->player.pos_x + x];
	if (!is_wall(new_pos))
	{
		if (!check_exit(env))
			draw_texture(env, (env->player.pos_x * env->ppi), \
			(env->player.pos_y * env->ppi), &(env->floor));
		env->player.pos_y += y;
		env->player.pos_x += x;
		draw_texture(env, (env->player.pos_x * env->ppi), \
		(env->player.pos_y * env->ppi), img);
		check_collectible(env);
		is_exit(new_pos, env);
	}
	return (0);
}
