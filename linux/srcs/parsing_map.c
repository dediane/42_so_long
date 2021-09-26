/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:40:45 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/24 13:40:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_sprites(char **map)
{
	if (check_unique_object(map, 'P'))
		return (1);
	if (check_unique_object(map, 'E'))
		return (1);
	if (check_valid_map_char(map))
		return (1);
	return (0);
}

int	check_unique_object(char **map, char c)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = -1;
	flag = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == c)
				flag++;
		}
		j = -1;
	}
	if (flag != 1)
		return (1);
	return (0);
}

int	check_valid_map_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] != '0' || map[i][j] != '1' \
			|| map[i][j] != 'P' || map[i][j] != 'C' || \
			map[i][j] != 'E')
				return (1);
		}
		j = -1;
	}
	return (0);
}