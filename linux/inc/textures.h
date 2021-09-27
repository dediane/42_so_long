/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:38:11 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/24 13:38:16 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

int	draw_texture(t_env *env, int x1, int y1, t_img *img);
int	load_texture(t_env *env, t_img *img, char *path);
int	destroy_texture(t_env *env, t_img *img);

#endif