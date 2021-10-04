/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:54:21 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 13:54:23 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_collectible_number(t_env *env)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	env->collect.max_units = 0;
	env->collect.player_units = 0;
	while (env->map[++y][0])
	{
		while (env->map[y][++x])
		{
			if (env->map[y][x] == 'C')
			{
				draw_texture(env, (x * env->ppi), \
				(y * env->ppi), &(env->collectible));
				env->collect.max_units++;
			}
		}
		x = -1;
	}
	return (0);
}

int	get_exit_position(t_env *env)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (env->map[++y][0])
	{
		while (env->map[y][++x])
		{
			if (env->map[y][x] == 'E')
			{
				draw_texture(env, (x * env->ppi), \
				(y * env->ppi), &(env->exit_img));
			}
		}
		x = -1;
	}
	return (0);
}
