/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:45:02 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 13:45:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

int	draw_map(t_env *env, int countX, int countY);
int	draw_one_square(t_env *env, int x, int y, int color);
int	draw_wall(t_env *env, int countX, int countY);

#endif
