/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:16:14 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/22 15:17:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int   draw_map(t_env *env)
{
	int i;
	int j;
	int width;
	int height;
	int color;

	i = -1;
	j = -1;
	width = 0;
	height = 0;
	while (env->map[++i])
	{
		printf("---Taille de i = %i ---\n", i);		
		while (env->map[i][++j])
		{
			printf("---Taille de j = %i ---\n", j);
			if (env->map[i][j] == '1')
			{
				draw_one_square(env, height, width, color);
				color = create_trgb(1, 113, 204, 212);
			}
			if (env->map[i][j] == '0')
			{
				color = create_trgb(1, 238, 246, 247);
				draw_one_square(env, height, width, color);
			}
			printf("---Taille de width = %i ---\n", width);
			width += env->ppi;
		}
		j = -1;
		height += env->ppi;
		width = 0;
	}
	return(0);
    // largeur en pixel -> env.img.width
    // hauteur en pixel -> env.img.height

    //largeur de ma maps -> env.width
    // hauteur de ma maps -> env.height


}*/

int draw_one_square(t_env *env, int x, int y, int color)
{
	int tmp;

	tmp = x;
	printf("i have been here\n");
    while (y < env->ppi)
    {
		x = 0;
        while (x < (env->ppi + tmp))
        {
            my_mlx_pixel_put(&(env->img), x, y, color);
			x++;
        }
		y++;
    }
    return (0);
}

int	draw_map(t_env *env)
{
	int i;
	int j;
	int count2;
	int count;

	count = 0;
	count2 = 0;
	i = -1;
	j = -1;

	while (env->map[++i])
	{
		while (env->map[i][++j])
		{
			if (env->map[i][j] == '1')
				draw_one_square(env, (count * env->ppi), (count2 * env->ppi), create_trgb(1, 113, 204, 212));
			else
				draw_one_square(env, (count * env->ppi), (count2 * env->ppi), create_trgb(1, 113, 204, 102));
			count++;
			}
		j = -1;
		count = 0;
	}

	//draw_one_square(env, color);

	return(0);
}