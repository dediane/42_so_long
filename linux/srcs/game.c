/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:03:45 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 18:03:47 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	play_game(t_env *env)
{
	load_texture(env, &(env->floor), "textures/snowfloor.xpm");
	load_texture(env, &(env->wall), "textures/wall2.xpm");
	draw_map(env, 0, 0);
	get_player_position(env);
	get_collectible_number(env);
	get_exit_position(env);
	return (0);
}
