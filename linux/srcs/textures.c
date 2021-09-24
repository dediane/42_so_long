/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:37:50 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/24 13:37:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_floor(t_env *env, char *path)
{
	env->floor.img = mlx_xpm_file_to_image(env->params.mlx, path, \
	&(env->floor.width), &(env->floor.height));
	if (env->floor.img)
		env->floor.addr = mlx_get_data_addr(env->floor.img, \
		&(env->floor.bits_per_pixel), &(env->floor.line_lenght), \
		&(env->floor.endian));
	return (0);
}

int	load_wall(t_env *env, char *path)
{
	env->wall.img = mlx_xpm_file_to_image(env->params.mlx, path, \
	&(env->wall.width), &(env->wall.height));
	if (env->wall.img)
		env->floor.addr = mlx_get_data_addr(env->floor.img, \
		&(env->floor.bits_per_pixel), &(env->floor.line_lenght), \
		&(env->floor.endian));
	return (0);
}

int	draw_floor(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->floor.img, \
	env->floor.endian, env->floor.line_lenght);
	return (0);
}