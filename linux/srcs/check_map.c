/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:51:47 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 16:48:02 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char *map)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = -1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error, can't open map file\n");
		return (0);
	}
	get_next_line(fd, &line);
	while (line[++i] != '\0')
	{
		if (line[i] != '1')
		{
			printf("Error, map open on line 1\n");
			return (0);
		}
	}
	while (get_next_line(fd, &line) > 0)
	{
		j = ft_strlen(line);
		if (j != i)
		{
			printf("Map de taille inegale\n");
			return (0);
		}
		if ((line[0] != '1') || (line[ft_strlen(line) - 1] != '1'))
		{
			printf("Error, map open on the sides\n");
			return (0);
		}
	}
	return (i);
}
