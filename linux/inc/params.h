/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:36:58 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/25 16:37:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef	struct s_params
{
	void	*mlx;
	void	*mlx_win;
}				t_params;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef	struct	s_env
{
	t_params	params;
	t_img		img;
	t_img		collect;
	t_img		wall;
	t_img		floor;
	t_img		exit;
}				t_env;

#endif

