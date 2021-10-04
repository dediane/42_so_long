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
	int	tmp_y;

	tmp = 0;
	tmp_y = 0;
	while (tmp_y < env->ppi)
	{
		tmp = 0;
		while (tmp < env->ppi)
		{
			my_mlx_pixel_put(&(env->img), x + tmp, y + tmp_y, color);
			tmp++;
		}
		tmp_y++;
	}
	return (0);
}

int	draw_map(t_env *env, int countX, int countY)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (env->map[++y][0])
	{
		countX = 0;
		while (env->map[y][++x])
		{
			draw_texture(env, (countX * env->ppi), \
			(countY * env->ppi), &(env->floor));
			countX++;
		}
		x = -1;
		countY++;
	}
	return (0);
}

int	draw_wall(t_env *env, int countX, int countY)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (env->map[++y][0])
	{
		countX = 0;
		while (env->map[y][++x])
		{
			if (env->map[y][x] == '1')
				draw_texture(env, (countX * env->ppi), \
				(countY * env->ppi), &(env->wall));
			countX++;
		}
		x = -1;
		countY++;
	}
	return (0);
}
