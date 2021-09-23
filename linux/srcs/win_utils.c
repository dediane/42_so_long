/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:41:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 16:50:38 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	quit_program(t_params *params)
{
	write(1, "Goodbye!", 7);
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(1);
}

int	keypress(int key, t_params *params)
{
	if (key == ESC)
		quit_program(params);
	if (key == UP || key == ARROW_UP)
	{
		//move_player_up();
		printf("UP\n");
	}
	if (key == DOWN || key == ARROW_DOWN)
		printf("DOWN\n");
	if (key == LEFT || key == ARROW_LEFT)
		printf("LEFT\n");
	if (key == RIGHT || key == ARROW_RIGHT)
		printf("RIGHT\n");
	if (key == SPACE)
		printf("SPACE\n");
	return (0);
}
