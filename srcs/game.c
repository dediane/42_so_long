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

int	destroy_all_images(t_env *env)
{
	destroy_texture(env, &(env->exit_img));
	destroy_texture(env, &(env->collectible));
	destroy_texture(env, &(env->floor));
	destroy_texture(env, &(env->wall));
	destroy_texture(env, &(env->player_front));
	destroy_texture(env, &(env->player_front2));
	destroy_texture(env, &(env->player_left));
	destroy_texture(env, &(env->player_right));
	destroy_texture(env, &(env->player_back));
	destroy_texture(env, &(env->player_left2));
	destroy_texture(env, &(env->player_right2));
	destroy_texture(env, &(env->player_back2));
	return (0);
}

int	load_all_images(t_env *env)
{
	load_texture(env, &(env->floor), "textures/snowfloor.xpm");
	load_texture(env, &(env->wall), "textures/tree.xpm");
	load_texture(env, &(env->player_front), "textures/princesse-front.xpm");
	load_texture(env, &(env->player_left), "textures/princesse-left.xpm");
	load_texture(env, &(env->player_right), "textures/princesse-right.xpm");
	load_texture(env, &(env->player_back), "textures/princesse-back0.xpm");
	load_texture(env, &(env->player_front2), "textures/princesse-front2.xpm");
	load_texture(env, &(env->player_left2), "textures/princesse-left2.xpm");
	load_texture(env, &(env->player_right2), "textures/princesse-right2.xpm");
	load_texture(env, &(env->player_back2), "textures/princesse-back2.xpm");
	load_texture(env, &(env->collectible), "textures/apple.xpm");
	load_texture(env, &(env->exit_img), "textures/exit.xpm");
	return (0);
}

int	play_game(t_env *env)
{
	load_all_images(env);
	draw_map(env, 0, 0);
	draw_wall(env, 0, 0);
	get_player_position(env);
	get_collectible_number(env);
	get_exit_position(env);
	return (0);
}
