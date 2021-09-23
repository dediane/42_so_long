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

/*void	draw_carre_texture(struct s_env *env, char *path)
{
	int		i;
	int		j;
	int		color;

	env->floor.img = mlx_xpm_file_to_image(env->params.mlx, path, &(env->floor.width), &(env->floor.height));
	if(env->floor.img)
		mlx_get_data_addr(env->floor.img, &(env->floor.bits_per_pixel), &(env->floor.line_length), &(env->floor.endian));	
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
	env->width = check_map(s);
	env->map = store_map(env->map, env->width, env->height, s);
	if (!(check_last_line(env->map, env->height)))
	{
		free(env->map);
		map_error(3);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_env	env;

	check_before_init(ac, av);
	init_game(&env, av[1]);
	//env.height = get_nb_of_line(av[1]);
	//env.width = check_map(av[1]);
	//env.map = store_map(env.map, env.width, env.height, av[1]);

	env.params.mlx = mlx_init();
	mlx_get_screen_size(env.params.mlx, &env.img.width, &env.img.height);
	env.img.width = env.img.width / 1.5;
	env.ppi = env.img.width / env.width;
	env.params.mlx_win = mlx_new_window(env.params.mlx, env.width * env.ppi, env.height * env.ppi, "So Long Game");
	env.img.img = mlx_new_image(env.params.mlx, env.width * env.ppi, env.height * env.ppi);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env.params);
	mlx_hook(env.params.mlx_win, 33, 1L<<17, quit_program, &env.params);

	mlx_loop_hook(env.params.mlx, show_image, &env);
	draw_map(&env, 0, 0);
	
	mlx_loop(env.params.mlx);
}


//draw_map(&env);
	//draw_carre(&env);
	//mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);
	//char *relative_path = "./textures/snowfloor.xpm";
	//env.floor.img = mlx_xpm_file_to_image(env.params.mlx_win, relative_path, &env.floor.width ,&env.floor.height );
	//mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.floor.img, 0, 0);