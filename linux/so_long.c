/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/25 18:28:09 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}*/

/*int	keypress(int key, t_params *vars)
{
	if (key == ESC)
		quit_program(vars);
	if (key == UP || key == ARROW_UP)
		printf("Move UP\n");
	if (key == DOWN || key == ARROW_DOWN)
		printf("Move DOWN\n");
	if (key == LEFT || key == ARROW_LEFT)
		printf("Move LEFT\n");
	if (key == RIGHT || key == ARROW_RIGHT)
		printf("Move RIGHT\n");
	if (key == SPACE)
		printf("SPACE\n");
	return (0);
}*/

/*void	draw_carre(struct s_env *env)
{
	int		i;
	int		j;
	int		color;

	color = create_trgb(150, 120, 145, 160);
	i = -1;
	j = 0;
	while(++i < 250)
	{
		j = 0;
		while(j < 250)
		{
			my_mlx_pixel_put(&(env->img), 125 + j, 125 + i, color);
			j++;
		}
	}
}*/
void	quit_program(t_params *params)
{
	write(1, "Goodbye!", 7);
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(1);
}

int	keypress(int key, t_params *params)
{
	if (key == ESC)
		quit_program(params);
	if (key == UP || key == ARROW_UP)
		printf("UP\n");
	if (key == DOWN || key ==ARROW_DOWN)
		printf("DOWN\n");
	if (key == LEFT || key == ARROW_LEFT)
		printf("LEFT\n");
	if (key == RIGHT || key == ARROW_RIGHT)
		printf("RIGHT\n");
	if (key == SPACE)
		printf("SPACE\n");
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_env	env;

	env.params.mlx = mlx_init();
	env.params.mlx_win = mlx_new_window(env.params.mlx, 800, 650, "So Long Game");
	env.img.img = mlx_new_image(env.params.mlx, 800, 650);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env.params);
	my_mlx_pixel_put(&(env.img), 125, 125, create_trgb(180, 200, 120, 130));
	/*draw_carre(&env);*/
	mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);
	mlx_loop(env.params.mlx);
}
