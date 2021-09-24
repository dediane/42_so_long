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
	//draw_map(env, 0, 0);
	load_floor(env, "textures/snowfloor.xpm");
	draw_floor(env);
	//get_player_position(env);
	//get_collectible_number(env);
	//get_exit_position(env);
	return (0);
}
