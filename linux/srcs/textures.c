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
	int color;

	color = env->floor.width;
	color++;
	return (0);
}
	/*int color;
	int x;
	int y;

	x = -1;
	y = -1;
	env->floor.line_lenght /= 4;
	while (++y < env->ppi)
	{
		while (++x < env->ppi)
		{
			color = env->floor.addr[env->floor.line_lenght * y] + x;
			my_mlx_pixel_put(&(env->img), x, y, color);
		}
		x = -1;
	}*/


	/*float ratioX;
	float ratioY;
	int i;
	int j;
	int color;

	ratioY = ((env->ppi / env->width) * env->floor.width);
	ratioX = ((env->ppi / env->height) * env->floor.height);
	
	i = -1;
	j = -1;
	color = index_color(ratioX, ratioY, &(env->floor));
	while(++i < (env->floor.height * (int)ratioY))
	{
		while(++j < (env->floor.width * (int)ratioX))
		{
			//my_mlx_pixel_put(&(env->img), j, i, color);
			j++;
		}
		j = -1;
	}*/
	/*mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->floor.img, \
	env->floor.endian, env->floor.line_lenght);*/

/*int *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
line_bytes /= 4;

int color = 0xABCDEF;

for(int y = 0; y < 360; ++y)
for(int x = 0; x < 640; ++x)
{
    buffer[(y * line_bytes) + x] = color;
}*/