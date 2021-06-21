/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/21 17:24:47 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

void	mlx_image_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int j = 50;
	int i = 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 450, "Hello World!");
	img.img = mlx_new_image(mlx, 600, 450);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while ( ++j < 200)
	{
		i = 50;
		while (++i < 200)
		{
			mlx_image_put(&img, j, i, 0x00FF0000);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		}
	}
	j = 150;
	while ( ++j < 350)
	{
		i = 150;
		while (++i < 350)
		{
			mlx_image_put(&img, j, i, 0x00FF0000);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		}
	}

	mlx_loop(mlx);
}
