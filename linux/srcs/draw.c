/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:16:14 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/22 15:17:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw_one_square(t_env *env, int x, int y, int color)
{
	int	tmp;
	int	tmpY;

	tmp = 0;
	tmpY = 0;
	while (tmpY < env->ppi)
	{
		tmp = 0;
		while (tmp < env->ppi)
		{
			my_mlx_pixel_put(&(env->img), x + tmp, y + tmpY, color);
			tmp++;
		}
		tmpY++;
	}
	return (0);
}

int	draw_map(t_env *env, int countX, int countY)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (env->map[++y])
	{
		countX = 0;
		while (env->map[y][++x])
		{
			if (env->map[y][x] == '1')
				draw_one_square(env, (countX * env->ppi), \
				(countY * env->ppi), create_trgb(1, 120, 200, 202));
			else
				draw_one_square(env, (countX * env->ppi), \
				(countY * env->ppi), create_trgb(1, 210, 242, 244));
			countX++;
		}
		x = -1;
		countY++;
	}
	get_player_position(env);
	get_collectible_number(env);
	get_exit_position(env);
	return (0);
}
