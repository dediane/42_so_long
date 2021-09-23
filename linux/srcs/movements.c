/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:07:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 16:07:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	find_where_to_move(t_env *env, char direction)
{
	char position;

	if (direction == 'N')
		position = env->map[env->player.posY - 1][env->player.posX];
	if (direction == 'S')
		position = env->map[env->player.posY + 1][env->player.posX];
	if (direction == 'E')
		position = env->map[env->player.posY][env->player.posX + 1];
	if (direction == 'W')
		position = env->map[env->player.posY][env->player.posX - 1];
	else
		exit(2);
	return (position);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return(0);
}