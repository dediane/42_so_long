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
    // largeur en pixel -> env.img.width
    // hauteur en pixel -> env.img.height

    //largeur de ma maps -> env.width
    // hauteur de ma maps -> env.height


}*/

int draw_one_square(t_env *env, int i, int j)
{
    int color;

    color = create_trgb(150, 120, 145, 160);
    while (i < env->ppi)
    {
        j = 0;
        while (j < env->ppi)
        {
            my_mlx_pixel_put(&(env->img), j, i, color);
            j++;
        }
        i++;
    }
    return (0);
}