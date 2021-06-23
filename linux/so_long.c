/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/23 13:50:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	quit_program(t_vars *vars)
{
	printf("Goodbye \n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

int	keypress(int key, t_vars *vars)
{
	if (key == ESC)
		quit_program(vars);
	if (key == UP)
		printf("Move UP\n");
	if (key == DOWN)
		printf("Move DOWN\n");
	if (key == LEFT)
		printf("Move LEFT\n");
	if (key == RIGHT)
		printf("Move RIGHT\n");
	if (key == SPACE)
		printf("SPACE\n");
	return (0);
}



int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 650, "So Long Game");
	vars.img = mlx_new_image(vars.mlx, 600, 450);
	mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
	mlx_loop(vars.mlx);
}


/*typedef struct	s_data 
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
	mlx_image_put(&img, 600, 450, 0x00ebb0ba);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_loop(mlx);
}*/
