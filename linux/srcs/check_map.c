/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:51:47 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/12 16:02:56 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_extension(char *map)
{
	int	size;

	size = ft_strlen(map);
	if (map[size - 4] != '.' || map[size - 3] != 'b' || \
	map[size - 2] != 'e' || map[size - 1] != 'r')
		return (0);
	return (1);
}

int	get_nb_of_line(char *map)
{
	int		fd;
	char	*line;
	int		j;

	line = NULL;
	j = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		j++;
		free(line);
	}
	free(line);
	close(fd);
	return (j);
}

int	check_map(char *map, int i, int j)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		map_error(2);
	get_next_line(fd, &line);
	while (line[++i] != '\0')
	{
		if (line[i] != '1')
			map_error(3);
	}
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		j += check_walls_side(line, ft_strlen(line), i);
		free(line);
	}
	close(fd);
	free(line);
	if ((j > 0) || (i <= 1))
		map_error(3);
	return (i);
}

char	**store_map(char **map, int width, int height, char *file)
{
	int	fd;
	int	i;

	i = 0;
	map = malloc((sizeof(char *) * (height + 1)) + (sizeof(char) * \
	(height + 1) * (width + 1)));
	if (!(map))
		return (NULL);
	fd = open(file, O_RDONLY);
	map[i] = NULL;
	while (get_next_line(fd, &map[i]) > 0)
	{
		i++;
		map[i] = NULL;
	}
	close(fd);
	return (map);
}

int	check_last_line(char **map, int height)
{
	int	i;

	i = -1;
	if (height <= 1)
	{
		ft_clear_tab(&map);
		map_error(3);
	}
	height -= 1;
	while (map[height][++i])
	{
		if (map[height][i] != '1')
			return (0);
	}
	return (1);
}
