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

int	load_enemy(t_env *env)
{
	load_texture(env, &(env->enemy_front), "textures/enemy-front.xpm");
	load_texture(env, &(env->enemy_back), "textures/enemy-back.xpm");
	return (0);
}

int	get_enemy_position(t_env *env, t_object *enemy)
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
				enemy->pos_x = x;
				enemy->pos_y = y;
			}
		}
		x = -1;
	}
	return (0);
}

int	enemy_move(t_object *enemy, t_object *player, t_env *env, t_img *img)
{
	while (1)
	{
		while ((enemy->pos_x != player->pos_x) && (enemy->pos_y != player->pos_y) \
		&& ((enemy->pos_y + 1) != '1'))
		{
			draw_texture(env, enemy->pos_x, enemy->pos_y, img);
			enemy->pos_y += 0.25;
		}
	}
	return (0);
}

int	show_bonus(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->enemy.img.img, 0, 0);
	return (1);
}

int	play_bonus(t_env *env)
{
	load_enemy(env);
	get_enemy_position(env, &(env->enemy));
	//enemy_move(&(env->enemy), &(env->player), env, &(env->enemy_front));
	mlx_loop_hook(env->params.mlx, show_bonus, &env);
	return (0);
}
