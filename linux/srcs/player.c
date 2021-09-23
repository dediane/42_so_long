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
				draw_one_square(env, (x * env->ppi), (y * env->ppi), \
				create_trgb(1, 50, 50, 50));
			}
		}
		x = -1;
	}
	return (0);
}

int	move_player_up(t_env *env)
{
	char new_pos;

	new_pos = env->map[env->player.posY - 1][env->player.posX];
	if (!is_wall(new_pos))
	{
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 210, 242, 244));
		env->player.posY--;
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
	}
	else
		return(1);
	return (0);
}

int	move_player_down(t_env *env)
{
	char new_pos;

	new_pos = env->map[env->player.posY + 1][env->player.posX];
	if (!is_wall(new_pos))
	{		
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 210, 242, 244));
		env->player.posY++;
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
	}
	else
		return(1);
	return (0);
}

int	move_player_east(t_env *env)
{
	char new_pos;

	new_pos = env->map[env->player.posY][env->player.posX - 1];
	if (!is_wall(new_pos))
	{		
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 210, 242, 244));
		env->player.posX--;
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
	}
	else
		return(1);
	return (0);
}

int	move_player_west(t_env *env)
{
	char new_pos;

	new_pos = env->map[env->player.posY][env->player.posX + 1];
	if (!is_wall(new_pos))
	{
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 210, 242, 244));
		env->player.posX++;
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
	}
	else
		return(1);
	return (0);
}