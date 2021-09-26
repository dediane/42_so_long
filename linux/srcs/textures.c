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

int	load_texture(t_env *env, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(env->params.mlx, path, \
	&(img->width), &(img->height));
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, \
		&(img->bits_per_pixel), &(img->line_lenght), \
		&(img->endian));
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

int	draw_texture(t_env *env, int x1, int y1, t_img *img)
{
	unsigned int color;
	int x;
	int y;
	float ratioY;
	float ratioX;

	x = -1;
	y = -1;

	//env->floor.line_lenght /= 4;
	while (++y < env->ppi)
	{
		ratioY = ((y / (float)env->ppi) * img->width);
		while (++x < env->ppi)
		{
			ratioX = ((x / (float)env->ppi) * img->height);
			color = index_color((int)ratioX, (int)ratioY, img);
			//color = env->floor.addr[env->floor.line_lenght * y] + x;
			my_mlx_pixel_put(&(env->img), x + x1, y + y1, color);
		}
		x = -1;
	}
	return (0);
}
	/*int color;
	
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