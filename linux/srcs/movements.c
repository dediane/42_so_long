/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:07:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 16:07:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	check_exit(t_env *env)
{
	char	current_pos;

	current_pos = env->map[env->player.posY][env->player.posX];
	if (current_pos == 'E')
	{
		//if (env->collect.max_units == env->collect.player_units)
		//{
		//	draw_one_square(env, (env->player.posX * env->ppi), \
		//	(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
		//	quit_program(env);
		//	return (1);
		//}
		draw_one_square(env, (env->player.posX * env->ppi), \
		(env->player.posY * env->ppi), create_trgb(1, 25, 250, 150));
		return (1);
	}
	return (0);
}

int	check_collectible(t_env *env)
{
	char	pos;

	pos = env->map[env->player.posY][env->player.posX];
	if (pos == 'C')
		env->collect.player_units++;
	return (0);
}

int	is_exit(char c, t_env *env)
{
	if (c == 'E')
	{
		if (env->collect.max_units == env->collect.player_units)
		{
			draw_one_square(env, (env->player.posX * env->ppi), \
			(env->player.posY * env->ppi), create_trgb(1, 50, 50, 50));
			quit_program(env);
			return (1);
		}
	}
	return (0);
}
