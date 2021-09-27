/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:44 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/27 19:23:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int load_enemy(t_env *env)
{
    load_texture(env, &(env->enemy_front), "textures/enemy-front.xpm");
	load_texture(env, &(env->enemy_back), "textures/enemy-back.xpm");
}

int	get_enemy_position(t_env *env)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (env->map[++y])
	{
		while (env->map[y][++x])
		{
			if (env->map[y][x] == 'Z')
			{
				draw_texture(env, (x * env->ppi), \
				(y * env->ppi), &(env->enemy_front));
			}
		}
		x = -1;
	}
	return (0);
}

