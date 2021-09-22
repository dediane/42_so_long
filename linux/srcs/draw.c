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
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (env->map[++i])
	{
		countX = 0;
		while (env->map[i][++j])
		{
			if (env->map[i][j] == '1')
				draw_one_square(env, (countX * env->ppi), \
				(countY * env->ppi), create_trgb(1, 213, 74, 72));
			else
				draw_one_square(env, (countX * env->ppi), \
				(countY * env->ppi), create_trgb(1, 220, 170, 150));
			countX++;
		}
		j = -1;
		countY++;
	}
	return (0);
}
