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

int	draw_texture(t_env *env, int x1, int y1, t_img *img)
{
	unsigned int color;
	int x;
	int y;
	float ratioY;
	float ratioX;

	x = -1;
	y = -1;
	while (++y < env->ppi)
	{
		ratioY = ((y / (float)env->ppi) * img->width);
		while (++x < env->ppi)
		{
			ratioX = ((x / (float)env->ppi) * img->height);
			color = index_color((int)ratioX, (int)ratioY, img);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&(env->img), x + x1, y + y1, color);
		}
		x = -1;
	}
	return (0);
}
