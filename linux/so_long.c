/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/07/01 19:00:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/*int		fonction1(t_env *env)
{

	mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);
	return(1);
}*/
void check_before_init(int ac, char **av)
{
	if (ac != 2)
		usage_error();
	if (!(check_file_extension(av[1])))
		map_error(1);
}

int main(int ac, char **av)
{
	int	width;
	int height;
	int ppi;

	t_env	env;

	check_before_init(ac, av);
	height = get_nb_of_line(av[1]);
	width = check_map(av[1]);
	env.map = store_map(env.map, width, height, av[1]);
	int i = -1;
	int j = -1;
	while (env.map[++i])
	{
		while (env.map[i][++j])
		{
			printf("%c", env.map[i][j]);
		}
		j = -1;
		printf("\n");
	}
	if (!(check_last_line(env.map, height)))
	{
		free(env.map);
		map_error(3);
	}

	env.params.mlx = mlx_init();
	mlx_get_screen_size(env.params.mlx, &env.img.width, &env.img.height);
	env.img.width = env.img.width / 1.5;
	ppi = env.img.width / width;
	env.params.mlx_win = mlx_new_window(env.params.mlx, width * ppi, height * ppi, "So Long Game");
	env.img.img = mlx_new_image(env.params.mlx, width * ppi, height * ppi);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env.params);
	mlx_hook(env.params.mlx_win, 33, 1L<<17, quit_program, &env.params);
/*	mlx_loop_hook(env.params.mlx, fonction1, &env);*/
	/*draw_carre(&env);
	mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);*/
	mlx_loop(env.params.mlx);
}
