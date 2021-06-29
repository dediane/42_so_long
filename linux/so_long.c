/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:55:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 18:08:51 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_carre(struct s_env *env)
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
}

int main(int ac, char **av)
{
	int	width;
	int height;
	int ppi;

	ppi = 64;
	if (ac != 2)
	{
		printf("Usage: so_long.c map.ber\n");
		return(-1);
	}
	if (!(check_file_extension(av[1])))
		printf("Erreur, mauvaise extension de fichier.");
	width = check_map(av[1]);
	if (width == 0)
		printf("Erreur map \n");
	height = get_nb_of_line(av[1]);
	if (height == 0)
		printf("Erreur map \n");
	printf("Valeur de width = %i\n", width);
	printf("Valeur de height = %i\n", height);
	
	t_env	env;
	env.params.mlx = mlx_init();
	env.params.mlx_win = mlx_new_window(env.params.mlx, width * ppi, height * ppi, "So Long Game");
	env.img.img = mlx_new_image(env.params.mlx, width * ppi, height * ppi);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
	mlx_hook(env.params.mlx_win, 2, 1L<<0,  keypress, &env.params);
	mlx_hook(env.params.mlx_win, 33, 1L<<17, quit_program, &env.params);
	/*draw_carre(&env);
	mlx_put_image_to_window(env.params.mlx, env.params.mlx_win, env.img.img, 0, 0);*/
	mlx_loop(env.params.mlx);
}
