/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/28 16:51:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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

int main(void)
{
	t_env	env;

	env.params.mlx = mlx_init();
	env.params.mlx_win = mlx_new_window(env.params.mlx, 800, 650, "So Long Game");
	env.img.img = mlx_new_image(env.params.mlx, 800, 650);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env.params);
	mlx_hook(env.params.mlx_win, 33, 1L<<17, quit_program, &env.params);
	my_mlx_pixel_put(&(env.img), 125, 125, create_trgb(180, 200, 120, 130));
	/*draw_carre(&env);*/
	mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);
	mlx_loop(env.params.mlx);
}
