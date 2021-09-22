/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:51:47 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/21 22:55:09 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_extension(char *map)
{
	int size;

	size = ft_strlen(map);
	if (map[size - 4] != '.' || map[size - 3] != 'b'|| 
	map[size - 2] != 'e' || map[size -1] != 'r')
		return (0);
	return(1);
}

int get_nb_of_line(char *map)
{
	int fd;
	char *line;
	int j;
	
	line = NULL;
	j = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		j++;
	}
	close(fd);
	return (j);
}

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
		map_error(2);
	get_next_line(fd, &line);
	while (line[++i] != '\0')
	{
		if (line[i] != '1')
			map_error(3);
	}
	while (get_next_line(fd, &line) > 0)
	{
		j = ft_strlen(line);
		if (j != i || i == 0)
			map_error(4);	
		if ((line[0] != '1') || (line[ft_strlen(line) - 1] != '1'))
			map_error(3);	
	}
	close(fd);
	return (i);
}

char	**store_map(char **map, int width, int height, char* file)
{
	int fd;
	int i = 0;

	map = malloc((sizeof(char*) * height) + (sizeof(char) * height * width));
	if (!(map))
		return (NULL);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &map[i]) > 0)
	{
		i++;
		//printf("map array -> %s\n", map[i]);
	}
	return (map);
}

int	check_last_line(char **map, int height)
{
	int i;

	i = -1;
	height -= 1;
	//printf("Last line : %s\n", map[height]);
	while(map[height][++i])
	{
		if (map[height][i] != '1')
			return(0);
	}
	return(1);
}
