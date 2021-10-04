/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:36:58 by ddecourt          #+#    #+#             */
/*   Updated: 2021/07/02 11:49:33 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef struct s_params
{
	void	*mlx;
	void	*mlx_win;
}				t_params;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
	int		ratio;
}			t_img;

typedef struct s_object
{
	int		pos_x;
	int		pos_y;
	t_img	img;
}			t_object;

typedef struct s_collect
{
	int		max_units;
	int		player_units;
	t_img	img;
}			t_collect;

typedef struct s_exit
{
	int	pos_x;
	int	pos_y;
}			t_exit;

typedef struct s_env
{
	char		**map;
	int			height;
	int			width;
	int			ppi;
	int			count;
	t_params	params;
	t_img		img;
	t_object	player;
	t_object	enemy;
	t_collect	collect;
	t_img		floor;
	t_img		wall;
	t_img		player_front;
	t_img		player_front2;
	t_img		player_left;
	t_img		player_left2;
	t_img		player_right;
	t_img		player_right2;
	t_img		player_back;
	t_img		player_back2;
	t_img		enemy_front;
	t_img		enemy_back;
	t_img		collectible;
	t_img		exit_img;
	t_exit		exit;
}				t_env;

#endif