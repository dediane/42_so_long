/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/21 23:02:35 by ddecourt         ###   ########.fr       */
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

int	key_hook(int keycode, t_data *img)
{
	char *hello = "Hello from the keyhook";
	write(1, &hello, ft_strlen(hello));
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int j = 0;
	int i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 450, "Hello World!");
	img.img = mlx_new_image(mlx, 600, 450);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*while ( ++i < 300)
	{
		j = 300 - k++;
		while (++j < 300 + k)
		{
			mlx_image_put(&img, j, i, 0x00ebb0ba);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		}
	}*/
	while (++i < 450)
	{
		j = 0;	
		while (++j < 600)
		{
			mlx_image_put(&img, j, i, 0x00ebb0ba);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		}
	}
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_loop(mlx);
}
