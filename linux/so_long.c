/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/21 23:25:05 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		show_image(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->img.img, 0, 0);
	return(1);
}

void check_before_init(int ac, char **av)
{
	if (ac != 2)
		usage_error();
	if (!(check_file_extension(av[1])))
		map_error(1);
}

int	init_game(t_env *env, char *s)
{
	env->height = get_nb_of_line(s);
	env->width = check_map(s, -1, 0);
	env->map = store_map(env->map, env->width, env->height, s);
	if (!(check_last_line(env->map, env->height)) && check_sprites(env->map))
	{
		ft_clear_tab(&(env->map));
		map_error(3);
	}
	env->params.mlx = mlx_init();
	mlx_get_screen_size(env->params.mlx, &env->img.width, &env->img.height);
	env->img.width = env->img.width / 1.5;
	env->ppi = 64;
	env->params.mlx_win = mlx_new_window(env->params.mlx, \
	env->width * env->ppi, env->height * env->ppi, "So Long Game");
	env->img.img = mlx_new_image(env->params.mlx, env->width * env->ppi, \
	env->height * env->ppi);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, \
	&env->img.line_lenght, &env->img.endian);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	env;

	env.count = 0;
	ac ++;
	//check_before_init(ac, av);
	init_game(&env, av[1]);
	play_game(&env);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env);
	mlx_hook(env.params.mlx_win, 33, 1L<<17, quit_program, &env);
	mlx_loop_hook(env.params.mlx, show_image, &env);
	mlx_loop(env.params.mlx);
}
